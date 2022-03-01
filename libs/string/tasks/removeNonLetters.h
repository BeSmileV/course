#ifndef COURSE__REMOVENONLETTERS_H
#define COURSE__REMOVENONLETTERS_H

#include "../string_.h"

/// возвращает указатель на конец строки s
char *getEndOfString(char *s) {
    return s + strlen_(s);
}

/// удалить из строки s все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif
