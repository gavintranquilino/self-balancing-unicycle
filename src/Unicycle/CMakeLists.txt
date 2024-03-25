add_library(Unicycle unicycle.cpp unicycle.h)

# Added these to include the raylib library as <raylib.h>
target_link_directories(Unicycle PUBLIC ${CMAKE_SOURCE_DIR}/external/raylib/raylib/)
target_link_libraries(Unicycle PUBLIC raylib) 