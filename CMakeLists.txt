cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico-projects)

pico_sdk_init()


add_subdirectory(adafruit_macropad)
add_subdirectory(adafruit_ssd1306)
add_subdirectory(blink)
add_subdirectory(display_example)
add_subdirectory(font)
add_subdirectory(text_manager)
add_subdirectory(scratchpad)
add_subdirectory(ws2812)

