#ifndef COURSE__ISINCLUDEALLLETTERSINSTR_H
#define COURSE__ISINCLUDEALLLETTERSINSTR_H

#include "../string_.h"

#define COUNT_OF_SYMBOLS 256

bool isIncludeAllLettersInStr(char *s, char *word){
    char a[COUNT_OF_SYMBOLS] = {0};
    while(*s != '\0'){
        char sym = *s;
        if(isalpha(sym))
            a[sym]++;
        s++;
    }

    while(*word != '\0'){
        if(a[*word] == 0)
            return false;
        word++;
    }

    return true;
}

#endif