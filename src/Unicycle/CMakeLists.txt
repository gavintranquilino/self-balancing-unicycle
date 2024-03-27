add_library(Unicycle unicycle.cpp unicycle.h)

# Added these to include the raylib library as <raylib.h>
target_link_directories(Unicycle PUBLIC ${CMAKE_SOURCE_DIR}/external/raylib/raylib/)
target_link_libraries(Unicycle PUBLIC raylib) 

# Add Base Inverted Pendulum Class
# CMAKE_SOURCE_DIR is the root directory of the project (where the top-level CMakeLists.txt file is located)
# CMAKE_CURRENT_SOURCE_DIR is the directory where the current CMakeLists.txt file is located (Unicycle~)
target_include_directories(Unicycle PUBLIC ${CMAKE_SOURCE_DIR}/src/InvertedPendulum/)
message(STATUS "InvertedPendulum: ${CMAKE_SOURCE_DIR}/src/InvertedPendulum/")
target_link_libraries(Unicycle PUBLIC InvertedPendulum) 