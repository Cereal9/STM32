# ---- Directories -------------------------------------------------------------
CORE_DIR    = ./core
DRIVERS_DIR = ./drivers
LIB_DIR     = ./lib
BUILD_DIR   = ./build

TARGET = $(BUILD_DIR)/firmware

# ---- Target chip -------------------------------------------------------------
# STM32L432KC: Cortex-M4F, 256K flash @ 0x08000000, 64K SRAM.
MCU_SPEC = cortex-m4
FPU_SPEC = fpv4-sp-d16
DEVICE   = STM32L432xx

# ---- Source discovery --------------------------------------------------------
# Only search directories that actually exist, so a missing drivers/ or lib/
# is not an error.
DIRS = $(CORE_DIR)
ifneq (,$(wildcard $(DRIVERS_DIR)))
    DIRS += $(DRIVERS_DIR)
endif
ifneq (,$(wildcard $(LIB_DIR)))
    DIRS += $(LIB_DIR)
endif

LD_SCRIPT = $(shell find $(DIRS) -name '*.ld')
STARTUP   = $(shell find $(DIRS) -name '*.s')
C_SRCS    = $(shell find $(DIRS) -name '*.c')

# Every directory holding a header becomes an include path.
INC_DIRS      = $(sort $(dir $(shell find $(DIRS) -name '*.h')))
INC_DIRS_FLAG = $(addprefix -I, $(INC_DIRS))

OBJS  = $(addprefix $(BUILD_DIR)/, $(STARTUP:.s=.o))
OBJS += $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
DEPS  = $(OBJS:.o=.d)

# ---- Toolchain ---------------------------------------------------------------
TOOLCHAIN = /usr
CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size

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
all: $(TARGET).bin

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
	st-flash --reset write $(TARGET).bin 0x08000000

.PHONY: debug
debug: $(TARGET).elf
	st-util &
	arm-none-eabi-gdb -ex="target extended-remote :4242" $(TARGET).elf
	pkill st-util

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: fromscratch
fromscratch: clean all

-include $(DEPS)
