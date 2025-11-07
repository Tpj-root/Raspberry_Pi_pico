cmake_minimum_required(VERSION 3.13)

# Import the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(hello_serial C CXX ASM)

# Initialize the SDK
pico_sdk_init()

add_executable(hello_serial
    hello_serial.c
)

# Pull in common dependencies
target_link_libraries(hello_serial pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(hello_serial pico_cyw43_arch_none)
endif()

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(hello_serial)

pico_enable_stdio_usb(hello_serial 0)
pico_enable_stdio_uart(hello_serial 1)


# Add optional URL
#example_auto_set_url(hello_serial)

