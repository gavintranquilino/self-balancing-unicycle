cmake_minimum_required(VERSION 3.0)
project(unicycle LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add raylib library
# add_subdirectory(include/raylib)

# Add src directory 
add_subdirectory(src)
