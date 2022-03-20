add_library(text_manager "")
target_sources(text_manager
  PRIVATE
    text_manager.cc
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/text_manager.h
)
target_link_libraries(text_manager 
  PRIVATE
    adafruit_ssd1306
    font
)
target_include_directories(text_manager
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)