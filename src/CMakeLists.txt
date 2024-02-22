# Get all the files that end in .cpp and store in SOURCES variable using file()
# file(GLOB_RECURSE SOURCES "*.cpp")
# message("SOURCES: ${SOURCES}")

add_executable(${PROJECT_NAME} main.cpp)

# Get all the items in the src directory and store in a SRC_ITEMS variable using file()
file(GLOB SRC_ITEMS LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/*)
message("SRC_ITEMS: ${SRC_ITEMS}")

# ----- Adding all the libraries in the src directory -----
# Get just the name of the subdirectory for every SUB_DIR and store in a variable SUB_DIR_NAME using file()
foreach(item ${SRC_ITEMS})
    if(IS_DIRECTORY ${item})
        if (EXISTS ${item}/CMakeLists.txt) # Can't include directory if it does not have CMakelists.txt
            file(RELATIVE_PATH item_name ${CMAKE_CURRENT_SOURCE_DIR} ${item})
            add_subdirectory(${item_name})# Link all the .cpp files in src to the executable
            target_include_directories(${PROJECT_NAME} PUBLIC ${item})
            target_link_libraries(${PROJECT_NAME} PUBLIC ${item_name})
            message("ADDED AND LINKED LIBRARY IN SRC: ${item_name}")
        endif()
    endif()
endforeach()

# ----- Adding library test -----
# Create subdirectory in the build directory
# add_subdirectory(Bruh)

# Create a target include directories for the bruh library, this made libBruh.a in the build/src/build dir
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Bruh)

# Link the library within the build directory (link the .a file to the executable in bin/) 
# target_link_libraries(${PROJECT_NAME} Bruh) # Not needed because it is added to the SOURCES that are added to executable

# Set output directory for executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)
