cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(max7219_test)

pico_sdk_init()

add_executable(max7219_test hello_display.c)
target_link_libraries(max7219_test pico_stdlib hardware_spi)
pico_add_extra_outputs(max7219_test)


# Add optional URL
#example_auto_set_url(https://github.com/Tpj-root/Raspberry_Pi_pico)

