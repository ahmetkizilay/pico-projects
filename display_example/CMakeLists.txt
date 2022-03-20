add_executable(display_example display_example.cc)
target_link_libraries(display_example 
  PRIVATE 
    adafruit_ssd1306
    dotmatrix_font
    hardware_spi 
    pico_stdlib 
    text_manager
)

pico_enable_stdio_usb(display_example 1)
pico_enable_stdio_uart(display_example 0)

pico_add_extra_outputs(display_example)
