
cmake_minimum_required(VERSION 3.12)

project(http)

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
    commands/long_task.h
)

set(SOURCES_CXX_FILES
    main.cpp
    commands/long_task.cpp
)

add_executable(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_link_libraries(${PROJECT_NAME} ${LIBRARY_LIB_DIRECTORY}/libcommandline.a)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
