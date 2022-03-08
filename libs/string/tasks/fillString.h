#ifndef COURSE__FILLSTRING_H
#define COURSE__FILLSTRING_H

#include "../string_.h"

void swapCharPointer(char **a, char **b) {
    char *t = *a;
    *a = *b;
    *b = t;
}

void swapSize_t(size_t *a, size_t *b) {
    size_t t = *a;
    *a = *b;
    *b = t;
}


void fillString(char *s1, char *s2) {
    size_t n1 = strlen_(s1);
    size_t n2 = strlen_(s2);
    if (n1 > n2) {
        swapCharPointer(&s1, &s2);
        swapSize_t(&n1, &n2);
    } else if(n1 == 0 && n2 == 0)
        return;

    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    char *begin;
    if(n1 != 0) {
        begin = _bag.words[_bag.size - 1].end;
        *begin = ' ';
    } else
        begin = s1 - 1;
    char *endS1 = copy(_bag2.words[_bag.size].begin, _bag2.words[_bag2.size - 1].end, begin + 1);
    *endS1 = '\0';
}

#endif
