cmake_minimum_required(VERSION 3.20)
project(unicycle LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add src directory to the build (makes a build/src directory)
add_subdirectory(src)

# Automatically grap external libraries from GitHub repos when this prohect is cloned
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
   option(GIT_SUBMODULE "Check submodules during build" ON) # User can turn on or off to grab submodule from GitHub
   if(GIT_SUBMODULE)
       message(STATUS "Submodule update")
       execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                       RESULT_VARIABLE GIT_SUBMOD_RESULT)
       if(NOT GIT_SUBMOD_RESULT EQUAL "0")
           message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
       endif()
   endif()
endif()

# Link and build external libraries
add_subdirectory(external/raylib)
target_include_directories(${PROJECT_NAME} PUBLIC external/raylib/raylib/include)
target_link_directories(${PROJECT_NAME} PUBLIC external/raylib/raylib/)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/raylib/CMakeLists.txt")
   message(FATAL_ERROR "Raylib submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()