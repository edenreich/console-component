
cmake_minimum_required(VERSION 3.12)

project(http)

set(HEADERS_CXX_FILES
    commands/long_task.h
)

set(SOURCES_CXX_FILES
    main.cpp
    commands/long_task.cpp
)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_link_libraries(${PROJECT_NAME} console Threads::Threads)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
