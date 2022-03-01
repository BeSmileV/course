cmake_minimum_required(VERSION 3.20)

project(course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(course_ main.c)

add_subdirectory(libs)
add_library(str libs/string/string_.h libs/string/string_.c
        libs/string/tasks/removeNonLetters.h
        libs/string/tasks/removeAdjacentEqualLetters.h)

target_link_libraries(course_ str)
target_link_libraries(course_ data_structures)
target_link_libraries(course_ algorithms)
