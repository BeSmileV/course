#ifndef COURSE__PRINTWORDBEFOREFIRSTWORDWITHA_H
#define COURSE__PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

bool isHaveAinWord(WordDescriptor word) {
    while (word.begin != word.end) {
        if (*word.begin == 'a')
            return true;
        word.begin++;
    }

    return *word.begin == 'a';
}

int getWordBeforeFirstWordWithA(char *s, WordDescriptor *wordBeforeA) {
    WordDescriptor word;
    bool isFindA = false;
    char *copyS = s;
    if (!getWord(s, &word))
        return EMPTY_STRING;
    isFindA = isHaveAinWord(word);
    s = word.end;
    while (!isFindA && getWord(s, &word)) {
        isFindA = isHaveAinWord(word);
        s = word.end;
    }

    if (!isFindA)
        return NOT_FOUND_A_WORD_WITH_A;
    else if (getWordReverse(word.begin - 1, copyS - 1, &word)) {
        wordBeforeA->begin = word.begin;
        wordBeforeA->end = word.end;

        return WORD_FOUND;
    } else
        return FIRST_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor wordBeforeA;
    getWordBeforeFirstWordWithA(s, &wordBeforeA);

    char buf[MAX_WORD_SIZE];
    char *endBuf = copy(wordBeforeA.begin, wordBeforeA.end, buf);
    *endBuf = '\0';

    puts(buf);
}

#endif
