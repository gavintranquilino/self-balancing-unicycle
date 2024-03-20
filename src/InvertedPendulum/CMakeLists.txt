add_library(InvertedPendulum invertedpendulum.cpp invertedpendulum.h)

# Added these to include the raylib library as <raylib.h>
target_link_directories(InvertedPendulum PUBLIC ${CMAKE_SOURCE_DIR}/external/raylib/raylib/)
target_link_libraries(InvertedPendulum PUBLIC raylib)