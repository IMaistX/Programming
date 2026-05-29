cmake_minimum_required(VERSION 3.10)
project(CryptoProject C)

set(CMAKE_C_STANDARD 99)
add_library(shifr SHARED shifr.c shifr.h)

target_link_libraries(shifr PRIVATE m)

add_executable(program main.c)
target_link_libraries(program PRIVATE shifr)

add_executable(unit_tests test.c)
target_link_libraries(unit_tests PRIVATE shifr cmocka)

file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/config.txt ${CMAKE_CURRENT_BINARY_DIR}/config.txt SYMBOLIC)
