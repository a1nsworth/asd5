cmake_minimum_required(VERSION 3.21)
project(List C)

set(CMAKE_C_STANDARD 23)

add_executable(List main.c)

add_subdirectory(includes)
target_link_libraries(List includes)
