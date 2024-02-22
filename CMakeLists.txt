cmake_minimum_required(VERSION 3.20)
project(unicycle LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add src directory to the build (makes a build/src directory)
add_subdirectory(src)

# Link and build external libraries
add_subdirectory(external/raylib)
target_include_directories(${PROJECT_NAME} PRIVATE external/raylib/raylib/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/raylib/raylib/)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)