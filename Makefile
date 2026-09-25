# ---- Directories -------------------------------------------------------------
SRC_DIR   = ./src
BUILD_DIR = ./build

TARGET = $(BUILD_DIR)/firmware

# ---- Target chip -------------------------------------------------------------
# STM32L432KC: Cortex-M4F, 256K flash @ 0x08000000, 64K SRAM.
MCU_SPEC = cortex-m4
FPU_SPEC = fpv4-sp-d16
DEVICE   = STM32L432xx

# ---- Source discovery --------------------------------------------------------
# src/test holds host-side unit tests, not firmware sources - keep it out of
# the cross-compiled build.
LD_SCRIPT = $(shell find $(SRC_DIR) -name '*.ld' -not -path '*/test/*')
STARTUP   = $(shell find $(SRC_DIR) -name '*.s' -not -path '*/test/*')
C_SRCS    = $(shell find $(SRC_DIR) -name '*.c' -not -path '*/test/*')

# Every directory holding a header becomes an include path.
INC_DIRS      = $(sort $(dir $(shell find $(SRC_DIR) -name '*.h' -not -path '*/test/*')))
INC_DIRS_FLAG = $(addprefix -I, $(INC_DIRS))

OBJS  = $(addprefix $(BUILD_DIR)/, $(STARTUP:.s=.o))
OBJS += $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
DEPS  = $(OBJS:.o=.d)

# ---- STM32CubeCLT -------------------------------------------------------------
CUBECLT_DIR = /opt/st/stm32cubeclt_1.22.0

# ---- Toolchain ---------------------------------------------------------------
TOOLCHAIN = $(CUBECLT_DIR)/GNU-tools-for-STM32
CC   = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS   = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
OC   = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD   = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS   = $(TOOLCHAIN)/bin/arm-none-eabi-size
GDB  = $(TOOLCHAIN)/bin/arm-none-eabi-gdb

# ---- ST-Link tooling ------------------------------------------------------
PROGRAMMER_CLI = $(CUBECLT_DIR)/STM32CubeProgrammer/bin/STM32_Programmer_CLI
GDBSERVER_DIR  = $(CUBECLT_DIR)/STLink-gdb-server/bin
GDBSERVER_PORT = 61234

# Architecture flags shared by the assembler, compiler and linker. Keeping them
# identical everywhere is what stops the float-ABI mismatch at link time.
ARCH_FLAGS  = -mcpu=$(MCU_SPEC)
ARCH_FLAGS += -mthumb
ARCH_FLAGS += -mfpu=$(FPU_SPEC)
ARCH_FLAGS += -mfloat-abi=hard

# ---- Assembler ---------------------------------------------------------------
ASFLAGS  = $(ARCH_FLAGS)
ASFLAGS += -c
ASFLAGS += -x assembler-with-cpp
ASFLAGS += -Og -g3
ASFLAGS += -Wall

# ---- Compiler ----------------------------------------------------------------
CFLAGS  = $(ARCH_FLAGS)
CFLAGS += -D$(DEVICE)
CFLAGS += -std=c11
CFLAGS += -Wall -Wextra
CFLAGS += -Og -g3
CFLAGS += -ffunction-sections -fdata-sections -fno-common
CFLAGS += -fmessage-length=0
CFLAGS += -MMD -MP
CFLAGS += $(INC_DIRS_FLAG)

# ---- Linker ------------------------------------------------------------------
LFLAGS  = $(ARCH_FLAGS)
LFLAGS += -T$(LD_SCRIPT)
LFLAGS += --static
LFLAGS += --specs=nano.specs
# Re-enable nosys.specs if you ever pull in printf/malloc; it supplies the
# syscall stubs (_sbrk, _write, ...). Left off here to keep the link warning-free.
#LFLAGS += --specs=nosys.specs
#LFLAGS += -nostartfiles  # keep crti/crtn: startup calls __libc_init_array, which needs _init
LFLAGS += -Wl,-Map=$(TARGET).map
LFLAGS += -Wl,--gc-sections
LFLAGS += -Wl,--print-memory-usage

# ---- Rules -------------------------------------------------------------------
.PHONY: all
all: $(TARGET).bin compile_commands.json

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET).elf: $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $^ $(LFLAGS) -o $@
	@$(OS) $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -O binary $< $@

$(TARGET).hex: $(TARGET).elf
	$(OC) -O ihex $< $@

# Disassembly listing, handy when checking what the compiler actually emitted.
.PHONY: dump
dump: $(TARGET).elf
	$(OD) -d -S $< > $(TARGET).lst

.PHONY: flash
flash: $(TARGET).bin
	$(PROGRAMMER_CLI) -c port=SWD -w $(TARGET).bin 0x08000000 -v -rst

.PHONY: debug
debug: $(TARGET).elf
	cd $(GDBSERVER_DIR) && ./ST-LINK_gdbserver -d -p $(GDBSERVER_PORT) -cp $(dir $(PROGRAMMER_CLI)) &
	sleep 1
	$(GDB) -ex="target extended-remote :$(GDBSERVER_PORT)" $(TARGET).elf
	pkill -f ST-LINK_gdbserver

# IntelliSense and clangd resolve headers from compile_commands.json. It is
# generated from the same CFLAGS the compiler gets, so the editor can never
# disagree with the build about include paths or defines.
.PHONY: compile_commands.json
compile_commands.json:
	@echo '[' > $@
	@for src in $(C_SRCS); do \
	    printf '  {"directory": "%s", "file": "%s", "command": "%s -c %s %s"},\n' \
	        '$(CURDIR)' "$$src" '$(CC)' '$(CFLAGS)' "$$src" >> $@; \
	done
	@sed -i '$$ s/,$$//' $@
	@echo ']' >> $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: fromscratch
fromscratch: clean all

-include $(DEPS)
