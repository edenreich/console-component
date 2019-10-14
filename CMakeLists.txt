
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(console)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WITH_TESTS "Compile the tests as well." ON)

add_subdirectory(src)

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
