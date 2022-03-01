#ifndef COURSE__REPLACE_H
#define COURSE__REPLACE_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    char word[MAX_WORD_SIZE];
    WordDescriptor wordNow;
    while (getWord(readPtr, &wordNow)) {
        recPtr = copy(readPtr, wordNow.begin, recPtr);
        char *endWord = copy(wordNow.begin, wordNow.end, word);
        *endWord = '\0';
        if (!strcmp_(word, w1))
            recPtr = copy(w2, getEndOfString(w2), recPtr);
        else
            recPtr = copy(word, endWord, recPtr);
        readPtr = wordNow.end;
    }
    *recPtr = '\0';
}

#endif
