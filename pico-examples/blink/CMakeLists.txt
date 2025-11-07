cmake_minimum_required(VERSION 3.13)

# Import the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(blink C CXX ASM)

# Initialize the SDK
pico_sdk_init()

add_executable(blink
    blink.c
)

# Pull in common dependencies
target_link_libraries(blink pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(blink pico_cyw43_arch_none)
endif()

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(blink)

# Add optional URL
#example_auto_set_url(blink)

