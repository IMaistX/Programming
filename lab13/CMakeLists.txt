cmake_minimum_required(VERSION 3.10)

project(car)


option(BUILD_SHARED_LIBS ON)




include_directories(include)

add_library(Lab13 src/automobil.c)

add_executable(main src/main.c)

target_link_libraries(main Lab13)

set(CMAKE_INSTALL_RPATH ".")