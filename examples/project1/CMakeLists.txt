
cmake_minimum_required(VERSION 3.12)

project(todo)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(HEADERS_CXX_FILES
    commands/copy_files.h
    commands/hello_world.h
)

set(SOURCES_CXX_FILES
    main.cpp
    commands/copy_files.cpp
    commands/hello_world.cpp
)

add_executable(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_link_libraries(${PROJECT_NAME} console)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
