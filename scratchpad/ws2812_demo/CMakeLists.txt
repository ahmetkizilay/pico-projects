add_executable(ws2812_demo ws2812_demo.cc)
target_link_libraries(ws2812_demo 
  PRIVATE 
    pico_stdlib 
    ws2812
    hardware_pio
)

pico_enable_stdio_usb(ws2812_demo 1)
pico_enable_stdio_uart(ws2812_demo 0)

pico_add_extra_outputs(ws2812_demo)
