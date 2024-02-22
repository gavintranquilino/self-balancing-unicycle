# Link the cart folder
add_library(bruh bruh/bruh.cpp)

# Link all the .cpp files in src to the executable
file(GLOB_RECURSE SOURCES "*.cpp")
message("SOURCES: ${SOURCES}")
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory for executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)
