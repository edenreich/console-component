
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(tests)

option(BUILD_GMOCK "Builds the googlemock subproject" OFF)

include(../cmake/CPM.cmake)

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.10.0
  VERSION 1.10.0
  OPTIONS
      "INSTALL_GTEST OFF"
      "gtest_force_shared_crt ON"
)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES_CXX_FILES
  unit/parser_test.cpp
  unit/output_test.cpp
  unit/input_test.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES_CXX_FILES})
target_link_libraries(${PROJECT_NAME} gtest console)

add_test(NAME ParserTest COMMAND ${PROJECT_NAME})
add_test(NAME OutputInterfaceTest COMMAND ${PROJECT_NAME})

set_tests_properties(${unit} PROPERTIES TIMEOUT 10)
