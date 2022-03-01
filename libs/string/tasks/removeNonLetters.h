#ifndef COURSE__REMOVENONLETTERS_H
#define COURSE__REMOVENONLETTERS_H

#include "../string_.h"



/// удалить из строки s все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif
