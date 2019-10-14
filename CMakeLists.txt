
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

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DISTRIBUTE_DIR}/bin
    LIBRARY DESTINATION ${DISTRIBUTE_DIR}/lib
    ARCHIVE DESTINATION ${DISTRIBUTE_DIR}/lib
)

file(COPY src/include DESTINATION ${DISTRIBUTE_DIR})

message(STATUS "[INFO] Distributed Files Directory: " ${DISTRIBUTE_DIR})

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()