#ifndef COURSE__HAVEANAGRAMS_H
#define COURSE__HAVEANAGRAMS_H

#include <stdlib.h>

#include "../string_.h"
#include "../tasks/haveEqualWords.h"

int cmp_char(const void *arg1, const void *arg2) {
    char a = *(char *) arg1;
    char b = *(char *) arg2;

    return a - b;
}

bool haveAnagrams(char *s) {
    getBagOfWords(&_bag, s);
    for (size_t i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp_char);

    return haveEqualWords(s);
}

#endif
