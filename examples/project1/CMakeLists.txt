
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(todo CXX)

# Setup Conan
if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
endif()

# Collect Implemention Files
set(SOURCES_CXX_FILES
    main.cpp
    commands/copy_files.cpp
    commands/hello_world.cpp
)

# Add Implemention Files To Executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Link The Executable With The Library
target_include_directories(${PROJECT_NAME} PUBLIC CONAN_PKG::console-component)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::console-component)
