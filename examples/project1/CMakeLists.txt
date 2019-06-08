
cmake_minimum_required(VERSION 3.12)

project(App)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(HEADERS_CXX_FILES
)

set(SOURCES_CXX_FILES
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_link_libraries(${PROJECT_NAME} commandline)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
