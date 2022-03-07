#ifndef COURSE__GETSTRINGOFALTERNATINGWORDS_H
#define COURSE__GETSTRINGOFALTERNATINGWORDS_H

#include "../string_.h"

char *getStringOfAlternatingWords(char *s1, char *s2) {
    char *s = malloc(sizeof(char) * (strlen_(s1) + strlen_(s2)));
    char *endS = s;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)), (isW2Found = getWord(beginSearch2, &word2)), isW1Found ||
                                                                                                     isW2Found) {
        if (isW1Found && isW2Found) {
            char *endW1 = copy(word1.begin, word1.end, endS);
            *endW1 = ' ';
            endS = endW1 + 1;
            beginSearch1 = word1.end;
            char *endW2 = copy(word2.begin, word2.end, endS);
            *endW2 = ' ';
            endS = endW2 + 1;
            beginSearch2 = word2.end;
        } else if (isW1Found) {
            char *endW1 = copy(word1.begin, word1.end, endS);
            *endW1 = ' ';
            endS = endW1 + 1;
            beginSearch1 = word1.end;
        } else {
            char *endW2 = copy(word2.begin, word2.end, endS);
            *endW2 = ' ';
            endS = endW2 + 1;
            beginSearch2 = word2.end;
        }
    }
    if(endS != s)
        *(endS - 1) = '\0';
    else
        *endS = '\0';

    return s;
}

#endif