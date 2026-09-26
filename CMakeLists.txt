cmake_minimum_required(VERSION 3.22)
project(stm32l432_firmware C ASM)

# ---- Target chip -------------------------------------------------------------
# STM32L432KC: Cortex-M4F, 256K flash, 64K SRAM.
set(DEVICE    STM32L432xx)
set(LD_SCRIPT ${CMAKE_SOURCE_DIR}/src/drivers/startup/STM32L432KCUx_FLASH.ld)
set(ARCH_FLAGS -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)            # -std=c11, same as the Makefile
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Source discovery (mirrors the Makefile; src/test is host-only) ----------
file(GLOB_RECURSE C_SRCS  CONFIGURE_DEPENDS src/*.c)
file(GLOB_RECURSE STARTUP CONFIGURE_DEPENDS src/*.s)
file(GLOB_RECURSE HDRS    CONFIGURE_DEPENDS src/*.h)
list(FILTER C_SRCS  EXCLUDE REGEX "/src/test/")
list(FILTER STARTUP EXCLUDE REGEX "/src/test/")
list(FILTER HDRS    EXCLUDE REGEX "/src/test/")

# Every directory holding a header becomes an include path.
set(INC_DIRS "")
foreach(h ${HDRS})
  get_filename_component(d ${h} DIRECTORY)
  list(APPEND INC_DIRS ${d})
endforeach()
list(REMOVE_DUPLICATES INC_DIRS)

# ---- Firmware target ---------------------------------------------------------
add_executable(firmware ${C_SRCS} ${STARTUP})
set_target_properties(firmware PROPERTIES SUFFIX ".elf" LINK_DEPENDS ${LD_SCRIPT})

target_include_directories(firmware PRIVATE ${INC_DIRS})
target_compile_definitions(firmware PRIVATE ${DEVICE})
target_compile_options(firmware PRIVATE
  ${ARCH_FLAGS}
  $<IF:$<CONFIG:Debug>,-O0,-Og> -g3   # -O0 in Debug so stepping/variables match the source
  "$<$<COMPILE_LANGUAGE:C>:-Wall;-Wextra;-ffunction-sections;-fdata-sections;-fno-common;-fmessage-length=0>"
  "$<$<COMPILE_LANGUAGE:ASM>:-x;assembler-with-cpp;-Wall>"
)
target_link_options(firmware PRIVATE
  ${ARCH_FLAGS}
  -T${LD_SCRIPT}
  -static
  --specs=nano.specs
  -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map
  -Wl,--gc-sections
  -Wl,--print-memory-usage
)

# ---- Post-build: .bin for flashing, plus size report -------------------------
add_custom_command(TARGET firmware POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware> ${CMAKE_BINARY_DIR}/firmware.bin
  COMMAND ${CMAKE_SIZE} $<TARGET_FILE:firmware>
  VERBATIM
)
