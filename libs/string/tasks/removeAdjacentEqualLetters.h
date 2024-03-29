#ifndef COURSE__REMOVEADJACENTEQUALLETTERS_H
#define COURSE__REMOVEADJACENTEQUALLETTERS_H

void removeAdjacentEqualLetters(char *s){
    size_t indexRead = 0;
    size_t indexWrite = 0;
    while(s[indexRead] != '\0') {
        if (s[indexRead] != s[indexRead + 1])
            s[(indexWrite++)] = s[indexRead];
        indexRead++;
    }
    s[indexWrite] = '\0';
}

#endif
