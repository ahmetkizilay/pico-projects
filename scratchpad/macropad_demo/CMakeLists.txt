add_executable(macropad_demo macropad_demo.cc)
target_link_libraries(macropad_demo 
  PRIVATE 
    pico_stdlib 
    adafruit_macropad
)

pico_enable_stdio_usb(macropad_demo 1)
pico_enable_stdio_uart(macropad_demo 0)

pico_add_extra_outputs(macropad_demo)
