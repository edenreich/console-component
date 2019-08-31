
cmake_minimum_required(VERSION 3.12)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY     ${CMAKE_BINARY_DIR}/bin)

option(WITH_EXAMPLES "Compile examples." OFF)
option(WITH_TESTS "Compile the tests as well." ON)

add_subdirectory(src)

if(WITH_EXAMPLES)
    add_subdirectory(examples/project1)
    add_subdirectory(examples/project2)
endif()

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
