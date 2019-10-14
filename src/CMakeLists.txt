
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(console
    VERSION 1.0.2
    LANGUAGES C CXX
    DESCRIPTION "An easy to use component for building powerful console applications."
)

set(BUILD_SHARED_LIBS OFF)

set(CMAKE_DEBUG_POSTFIX _${CMAKE_SYSTEM_NAME}_d)
set(CMAKE_RELEASE_POSTFIX _${CMAKE_SYSTEM_NAME}_r)

set(SOURCES_CXX_FILES
    application.cpp
    output.cpp
    input.cpp
    progress_bar.cpp
)

add_library(${PROJECT_NAME}
    ${SOURCES_CXX_FILES}
)
