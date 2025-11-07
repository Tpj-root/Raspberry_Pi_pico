cmake_minimum_required(VERSION 3.13)

# Import Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(hello_usb C CXX ASM)

# Initialize SDK
pico_sdk_init()

if (TARGET tinyusb_device)
    add_executable(hello_usb
        hello_usb.c
    )

    # Link SDK libraries
    target_link_libraries(hello_usb pico_stdlib)

    # Enable USB serial, disable UART
    pico_enable_stdio_usb(hello_usb 1)
    pico_enable_stdio_uart(hello_usb 0)

    # Create UF2 and other outputs
    pico_add_extra_outputs(hello_usb)

    # Optional URL
    # example_auto_set_url(hello_usb)

elseif(PICO_ON_DEVICE)
    message("Skipping hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()

