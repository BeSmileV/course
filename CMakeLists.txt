cmake_minimum_required(VERSION 3.20)
project(course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(course_ main.c)


add_subdirectory(libs)
target_link_libraries(course_ data_structures)
target_link_libraries(course_ algorithms)