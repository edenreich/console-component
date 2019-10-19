
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(console
    VERSION 1.0.2
    LANGUAGES C CXX
    DESCRIPTION "An easy to use component for building powerful console applications."
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DISTRIBUTE_DIR ${CMAKE_BINARY_DIR}/dist)

option(WITH_TESTS "Compile the tests as well." ON)

add_subdirectory(src)

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()