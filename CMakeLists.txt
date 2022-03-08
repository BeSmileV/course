cmake_minimum_required(VERSION 3.20)

project(course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(course_ main.c)

add_subdirectory(libs)
add_library(str libs/string/string_.h libs/string/string_.c
        libs/string/tasks/removeNonLetters.h
        libs/string/tasks/removeAdjacentEqualLetters.h
        libs/string/tasks/removeExtraSpaces.h
        libs/string/tasks/digitToEnd.h
        libs/string/tasks/getSpaceForDigits.h
        libs/string/tasks/replace.h
        libs/tests/tests_string_.h libs/string/tasks/isSortedWords.h libs/string/tasks/printWordsRevers.h libs/string/tasks/getCountOfPalindromes.h libs/string/tasks/getStringOfAlternatingWords.h libs/string/tasks/getReverseString.h libs/string/tasks/printWordBeforeFirstWordWithA.h libs/string/tasks/findFirstStrLastWordOfSecondStr.h libs/string/tasks/haveEqualWords.h libs/string/tasks/haveAnagrams.h)

target_link_libraries(course_ str)
target_link_libraries(course_ data_structures)
target_link_libraries(course_ algorithms)
