add_library(font "")
target_sources(font
  PRIVATE
    font.cc
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/font.h
)
target_include_directories(font
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_library(dotmatrix_font "")
target_sources(dotmatrix_font
  PRIVATE
    dotmatrix_font.cc
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/dotmatrix_font.h
)
target_link_libraries(dotmatrix_font 
  PRIVATE
  font
)
target_include_directories(dotmatrix_font
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
