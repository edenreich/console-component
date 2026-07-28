
cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(todo CXX)

# Add The console-component from local source
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../src ${CMAKE_CURRENT_BINARY_DIR}/console)

# Move The Default Directory Of The Executable To bin Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Collect Implemention Files Of The Current Project
set(SOURCES_CXX_FILES
    main.cpp
    commands/copy_files.cpp
    commands/hello_world.cpp
)

# Add The Implemention Files To The Executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Add The Definition Files
include_directories(${CMAKE_BINARY_DIR}/dist/include)

# Link The Executable With The Library
target_link_libraries(${PROJECT_NAME} console)
