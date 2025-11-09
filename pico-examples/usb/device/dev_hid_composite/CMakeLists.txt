cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(dev_hid_composite_project)
pico_sdk_init()

add_executable(dev_hid_composite
    main.c
    usb_descriptors.c
)

target_include_directories(dev_hid_composite PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(dev_hid_composite PUBLIC
    pico_stdlib
    pico_unique_id
    tinyusb_device
    tinyusb_board
)

# Optional errata fix
# target_compile_definitions(dev_hid_composite PUBLIC PICO_RP2040_USB_DEVICE_ENUMERATION_FIX=1)

pico_add_extra_outputs(dev_hid_composite)

#example_auto_set_url(dev_hid_composite)

