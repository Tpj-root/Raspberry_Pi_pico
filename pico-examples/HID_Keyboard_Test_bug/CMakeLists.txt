cmake_minimum_required(VERSION 3.13)

# ----------------------------------------------------
# Project setup
# ----------------------------------------------------
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(pico_hid_keyboard C CXX ASM)

pico_sdk_init()

# ----------------------------------------------------
# Executable and source files
# ----------------------------------------------------
add_executable(pico_hid_keyboard
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
)

# ----------------------------------------------------
# Include paths
# ----------------------------------------------------
target_include_directories(pico_hid_keyboard PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# ----------------------------------------------------
# Libraries
# ----------------------------------------------------
target_link_libraries(pico_hid_keyboard PUBLIC
    pico_stdlib
    tinyusb_device
    tinyusb_board
)

# ----------------------------------------------------
# Enable USB output (optional)
# ----------------------------------------------------
pico_enable_stdio_usb(pico_hid_keyboard 1)
pico_enable_stdio_uart(pico_hid_keyboard 0)

# ----------------------------------------------------
# Final output
# ----------------------------------------------------
pico_add_extra_outputs(pico_hid_keyboard)

# ----------------------------------------------------
# Optional: add URL metadata
# ----------------------------------------------------
#example_auto_set_url(pico_hid_keyboard)

