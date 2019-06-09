
cmake_minimum_required(VERSION 3.12)

project(commandline 
    VERSION 1.0.0
    LANGUAGES C CXX
    DESCRIPTION "Commandline parser library for building powerful cli."
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY     ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
#add_subdirectory(examples/project1)