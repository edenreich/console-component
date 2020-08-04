
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(http CXX)

# Add The CPM Package Manager
if(NOT EXISTS "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
  file(DOWNLOAD https://raw.githubusercontent.com/TheLartians/CPM.cmake/master/cmake/CPM.cmake "${CMAKE_HOME_DIRECTORY}/cmake/CPM.cmake")
endif()

include(cmake/CPM.cmake)

# Add The console-component
CPMAddPackage(
  NAME console
  GITHUB_REPOSITORY edenreich/console-component
  VERSION 1.0.5
  OPTIONS
    "WITH_TESTS Off"
)

# Move The Default Directory Of The Executable To bin Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Collect Implemention Files Of The Current Project
set(SOURCES_CXX_FILES
    main.cpp
    commands/fetch_data.cpp
)

# Add The Implemention Files To The Executable
add_executable(${PROJECT_NAME} ${SOURCES_CXX_FILES})

# Add The Definition Files
include_directories(${CMAKE_BINARY_DIR}/dist/include)

# Require Threads
find_package(Threads REQUIRED)

# Link The Executable With The Library
target_link_libraries(${PROJECT_NAME} console Threads::Threads)
