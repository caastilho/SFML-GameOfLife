cmake_minimum_required(VERSION 3.19)

# Create project settings
project (
    GameOfLife 
    VERSION 1.0.0
    DESCRIPTION "John Conway - Game of Life"
    )

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/others/bin)


# Create application
file (GLOB source_files 
    ${CMAKE_SOURCE_DIR}/source/*/*.cpp
    ${CMAKE_SOURCE_DIR}/source/main.cpp
    )

add_executable (app ${source_files})
set_target_properties (app PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    )


# Setup include directory
include_directories (${CMAKE_SOURCE_DIR}/include)


# Include SFML2 library
find_package (SFML REQUIRED COMPONENTS graphics)
target_link_libraries (app sfml-graphics)
