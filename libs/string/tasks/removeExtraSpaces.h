#ifndef COURSE__REMOVEEXTRASPACES_H
#define COURSE__REMOVEEXTRASPACES_H

void removeExtraSpaces(char *s){
    size_t indexRead = 0;
    size_t indexWrite = 0;
    while(s[indexRead] != '\0') {
        if (s[indexRead] != ' ' || s[indexRead] != s[indexRead + 1])
            s[(indexWrite++)] = s[indexRead];
        indexRead++;
    }
    s[indexWrite] = '\0';
}

#endif
