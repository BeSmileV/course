#ifndef COURSE__GETSPACEFORDIGITS_H
#define COURSE__GETSPACEFORDIGITS_H

#include "../string_.h"

void getSpaceForDigits(char *s){
    char *endBuffer = copy(s, s + strlen_(s), _stringBuffer);
    *endBuffer = '\0';
    size_t indexRead = 0;
    size_t indexWrite = 0;
    while(_stringBuffer[indexRead] != '\0'){
        if(isdigit(_stringBuffer[indexRead])) {
            size_t n = _stringBuffer[indexRead] - '0';
            for (size_t i = 0; i < n; i++)
                s[indexWrite + i] = ' ';
            indexWrite += n;
        }
        else {
            s[indexWrite] = _stringBuffer[indexRead];
            indexWrite++;
        }

        indexRead++;
    }
    s[indexWrite] = '\0';
}

#endif
