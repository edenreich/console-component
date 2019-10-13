
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(http CXX)

# Add The CPM Package Manager
include(cmake/CPM.cmake)

# Add The console-component
CPMAddPackage(
  NAME console
  GITHUB_REPOSITORY edenreich/console-component
  VERSION 1.0.2
  OPTIONS
    "WITH_TESTS Off"
)

# Move The Default Directory Of The Executable To bin Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Collect Implemention Files Of The Current Project
set(SOURCES_CXX_FILES
    main.cpp
    commands/long_task.cpp
)

# Add The Definition Files
include_directories(${CMAKE_BINARY_DIR}/dist/include)

# Add PThreads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Add The Implemention Files To The Executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Link The Executable With The Libraries
target_link_libraries(${PROJECT_NAME} console Threads::Threads)
