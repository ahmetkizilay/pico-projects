add_library(adafruit_ssd1306 "")
target_sources(adafruit_ssd1306
  PRIVATE
  adafruit_ssd1306.cc
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/adafruit_ssd1306.h
)
target_link_libraries(adafruit_ssd1306 
  PRIVATE
    hardware_spi
    pico_stdlib 
)
target_include_directories(adafruit_ssd1306
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)