

project(commandline
    VERSION 1.0.0
    LANGUAGES C CXX
    DESCRIPTION "Commandline parser library for building powerful cli."
)

set(BUILD_SHARED_LIBS OFF)
set(DISTRIBUTE_DIR ${CMAKE_BINARY_DIR}/dist)

set(HEADERS_CXX_FILES_CONSOLE
    console/application.h
    console/output.h
    console/input.h
    console/progress_bar.h
)

set(HEADERS_CXX_FILES_CONSOLE_INTERFACES
    console/interfaces/command_interface.h
    console/interfaces/output_interface.h
    console/interfaces/input_interface.h
    console/interfaces/application_interface.h
)

set(HEADERS_CXX_FILES_CONSOLE_TYPES
    console/types/colors.h
    console/types/exit_code.h
    console/types/collections.h
)

set(SOURCES_CXX_FILES
    application.cpp
    output.cpp
    input.cpp
    progress_bar.cpp
)

add_library(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/dist)
file(COPY console DESTINATION ${CMAKE_BINARY_DIR}/dist/include)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DISTRIBUTE_DIR}/bin
    LIBRARY DESTINATION ${DISTRIBUTE_DIR}/lib
    ARCHIVE DESTINATION ${DISTRIBUTE_DIR}/lib
)

message("[INFO] - Distribution dir: " ${DISTRIBUTE_DIR})
