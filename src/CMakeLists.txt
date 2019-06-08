

project(commandline)

set(BUILD_SHARED_LIBS OFF)
set(DISTRIBUTE_DIR ${CMAKE_BINARY_DIR}/dist)

set(HEADERS_CXX_FILES_CONSOLE
    include/console/application_interface.h
    include/console/application.h
    include/console/command.h
)

set(HEADERS_CXX_FILES_CONSOLE_TYPES
    include/console/types/colors.h
    include/console/types/exit_code.h
    include/console/types/metadata.h
)

set(SOURCES_CXX_FILES
    application.cpp
)


add_library(${PROJECT_NAME}
    ${HEADERS_CXX_FILES}
    ${SOURCES_CXX_FILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DISTRIBUTE_DIR}/bin
    LIBRARY DESTINATION ${DISTRIBUTE_DIR}/lib
    ARCHIVE DESTINATION ${DISTRIBUTE_DIR}/lib
)

install(
    FILES ${HEADERS_CXX_FILES_CONSOLE}
    DESTINATION ${DISTRIBUTE_DIR}/include/console
)
install(
    FILES ${HEADERS_CXX_FILES_CONSOLE_TYPES}
    DESTINATION ${DISTRIBUTE_DIR}/include/console/types
)

message("[INFO] - Distribution dir: " ${DISTRIBUTE_DIR})
