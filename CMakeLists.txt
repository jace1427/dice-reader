cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(dice-reader C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(dice-reader dice-reader.c)

pico_enable_stdio_usb(dice-reader 1)
pico_enable_stdio_uart(dice-reader 0)

target_link_libraries(dice-reader pico_stdlib pico_cyw43_arch_none hardware_i2c)

pico_add_extra_outputs(dice-reader)

