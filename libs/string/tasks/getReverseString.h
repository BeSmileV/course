#ifndef COURSE__GETREVERSESTRING_H
#define COURSE__GETREVERSESTRING_H

#include "../string_.h"

void getReverseString(char *s){
    char *endS = getEndOfString(s);
    WordDescriptor word;
    char *endBuf = copy(s, endS, _stringBuffer);
    *endBuf = '\0';
    while(getWordReverse(endBuf - 1, _stringBuffer - 1, &word)){
        s = copy(word.begin, word.end, s);
        *(s++) = ' ';
        endBuf = word.begin;
    }

    *(s - 1) = '\0';
}

#endif
