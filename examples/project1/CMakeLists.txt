
cmake_minimum_required(VERSION 3.12)

project(todo)

set(PROJECT_ROOT_DIRECTORY 
    ${PROJECT_SOURCE_DIR}/../../
)

set(LIBRARY_INCLUDE_DIRECTORY
    ${PROJECT_ROOT_DIRECTORY}/build/dist/include
)

set(LIBRARY_LIB_DIRECTORY
    ${PROJECT_ROOT_DIRECTORY}/build/dist/lib
)

include_directories(
    ${LIBRARY_INCLUDE_DIRECTORY}
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

target_link_libraries(${PROJECT_NAME} ${LIBRARY_LIB_DIRECTORY}/libcommandline.a)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
