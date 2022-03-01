#ifndef COURSE__DIGITTOEND_H
#define COURSE__DIGITTOEND_H

#include "../string_.h"

void digitToEnd(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
        char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
        copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
        beginSearch = word.end;
    }
}

#endif