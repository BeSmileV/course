#ifndef COURSE__TESTS_STRING__H
#define COURSE__TESTS_STRING__H

#include "../tests/tests_string_.h"
#include "../string/tasks/replace.h"
#include "../string/tasks/removeNonLetters.h"
#include "../string/tasks/removeAdjacentEqualLetters.h"
#include "../string/tasks/removeExtraSpaces.h"
#include "../string/tasks/digitToEnd.h"
#include "../string/tasks/getSpaceForDigits.h"
#include "../string/tasks/isSortedWords.h"
#include "../string/tasks/getCountOfPalindromes.h"
#include "../string/tasks/getStringOfAlternatingWords.h"
#include "malloc.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, " Got : \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_strlen_() {
    char s1[] = "String";
    char s2[] = "";
    assert(strlen_(s1) == 6 && strlen_(s2) == 0);
}

void test_findNonSpace() {
    char s1[] = " 123";
    char s2[] = " ";
    assert(findNonSpace(s1) == s1 + 1 && findNonSpace(s2) == s2 + 1);
}

void test_findSpace() {
    char s1[] = "1 23";
    char s2[] = "123";
    assert(findSpace(s1) == s1 + 1 && findSpace(s2) == s2 + 3);
}

void test_findNonSpaceReverse() {
    char s1[] = "1\n3\n\n";
    char s2[] = "\n\n\n\n";

    assert(findNonSpaceReverse(s1 + 4, s1 - 1) == s1 + 2 && findNonSpaceReverse(s2 + 3, s2 - 1) == s2 - 1);
}

void test_findSpaceReverse() {
    char s1[] = "1\n3\n\n4\n5";
    char s2[] = "1234";

    assert(findSpaceReverse(s1 + 7, s1 - 1) == s1 + 6 && findSpaceReverse(s2 + 3, s2 - 1) == s2 - 1);
}

void test_strcmp_() {
    char s1[] = "ABC";
    char s2[] = "AAC";

    assert(strcmp_(s1, s2) > 0 && strcmp_(s1, s1) == 0 && strcmp_(s2, s1) < 0);
}

void test_copy() {
    char s1[] = "World";
    char s2[10];
    char *end = copy(s1, s1 + 5, s2 + 3);
    *end = '\0';

    ASSERT_STRING(s1, s2 + 3);
}

int isEven(int a) {
    return a % 2 == 0;
}

void test_copyIf() {
    char s1[] = "123456";
    char s2[10];
    char *end = copyIf(s1, s1 + 5, s2 + 3, isEven);
    *end = '\0';

    ASSERT_STRING("24", s2 + 3);
}

void test_copyIfReverse() {
    char s1[] = "223456";
    char s2[10] = {0};
    char *end = copyIfReverse(s1 + 5, s1, s2, isEven);
    *end = '\0';

    ASSERT_STRING("642", s2);
}

void testString_() {
    test_strlen_();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

// TASKS

void test_removeNonLetters_NotEmpty() {
    char s[] = "H e l  lo";
    removeNonLetters(s);

    ASSERT_STRING("Hello", s);
}

void test_removeNonLetters_Empty() {
    char s[] = "";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_NotEmpty();
    test_removeNonLetters_Empty();
}

void test_removeAdjacentEqualLetters_NotEmpty() {
    char s[] = "AASSDD";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("ASD", s);
}

void test_removeAdjacentEqualLetters_Empty() {
    char s[] = "";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_Empty();
    test_removeAdjacentEqualLetters_NotEmpty();
}

void test_removeExtraSpaces_Empty() {
    char s[] = "";
    removeExtraSpaces(s);

    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_NotEmpty() {
    char s[] = "I like   5e";
    removeExtraSpaces(s);

    ASSERT_STRING("I like 5e", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_Empty();
    test_removeExtraSpaces_NotEmpty();
}

void test_digitToEnd_Empty() {
    char s[] = "";
    digitToEnd(s);

    ASSERT_STRING("", s);
}

void test_digitToEnd_NotEmpty() {
    char s[] = "1sda2  3aaa3";
    digitToEnd(s);

    ASSERT_STRING("sda12  aaa33", s);
}

void test_digitToEnd() {
    test_digitToEnd_Empty();
    test_digitToEnd_NotEmpty();
}

void test_getSpaceForDigits_Empty() {
    char s[] = "";
    getSpaceForDigits(s);

    ASSERT_STRING("", s);
}

void test_getSpaceForDigits_NotEmpty() {
    char s[] = "I1come0at3am";
    getSpaceForDigits(s);

    ASSERT_STRING("I comeat   am", s);
}

void test_getSpaceForDigits() {
    test_getSpaceForDigits_NotEmpty();
    test_getSpaceForDigits_Empty();
}

void test_replace_Empty() {
    char s[] = "";
    replace(s, "I", "You");

    ASSERT_STRING("", s);
}

void test_replace_NotEmpty() {
    char s[] = "I come, You and I";
    replace(s, "I", "You");

    ASSERT_STRING("You come, You and You", s);
}

void test_replace() {
    test_replace_Empty();
    test_replace_NotEmpty();
}

void test_isSortedWords_Empty() {
    char s[] = "";

    assert(isSortedWords(s));
    ASSERT_STRING("OK", "OK");
}

void test_isSortedWords_NotEmpty() {
    char s1[] = "AAAA AAB  AAC";
    char s2[] = "AAA AA AAAA CA";
    char s3[] = "Asd";

    assert(isSortedWords(s1) && !isSortedWords(s2) && isSortedWords(s3));
    ASSERT_STRING("OK", "OK");
}


void test_isSortedWords() {
    test_isSortedWords_NotEmpty();
    test_isSortedWords_Empty();
}

void test_getCountOfPalindromes_NotEmpty(){
    char *s = "ABA,ABBA,ABB,,asdDdsa";

    assert(getCountOfPalindromes(s) == 3);
    ASSERT_STRING("OK", "OK");
}

void test_getCountOfPalindromes_Empty(){
    char *s = "";

    assert(!getCountOfPalindromes(s));
    ASSERT_STRING("OK", "OK");
}

void test_getCountOfPalindromes(){
    test_getCountOfPalindromes_NotEmpty();
    test_getCountOfPalindromes_Empty();
}

void test_getStringOfAlternatingWords_NotEmpty(){
    char s1[] = "I done   homework";
    char s2[] = " have my";
    char *s = getStringOfAlternatingWords(s1, s2);

    ASSERT_STRING("I have done my homework", s);
}

void test_getStringOfAlternatingWords_Empty(){
    char s1[] = "";
    char s2[] = "";
    char *s = getStringOfAlternatingWords(s1, s2);

    ASSERT_STRING("", s);
}

void test_getStringOfAlternatingWords(){
    test_getStringOfAlternatingWords_Empty();
    test_getStringOfAlternatingWords_NotEmpty();
}

void test_tasks_String_() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitToEnd();
    test_getSpaceForDigits();
    test_replace();
    test_isSortedWords();
    test_getCountOfPalindromes();
    test_getStringOfAlternatingWords();
}

#endif
