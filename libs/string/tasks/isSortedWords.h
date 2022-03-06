#ifndef COURSE__ISSORTEDWORDS_H
#define COURSE__ISSORTEDWORDS_H

#include "../string_.h"

int areWordsEqual_(WordDescriptor w1, WordDescriptor w2){
    char copyW1[MAX_WORD_SIZE];
    char copyW2[MAX_WORD_SIZE];
    char *endW1 = copy(w1.begin, w1.end, copyW1);
    char *endW2 = copy(w2.begin, w2.end, copyW2);
    *endW1 ='\0';
    *endW2 ='\0';

    return strcmp_(copyW1, copyW2);
}

bool isSortedWords(char *s){
    WordDescriptor word;
    if(!getWord(s, &word))
        return true;
    WordDescriptor wordNow;
    while(getWord(word.end, &wordNow)) {
        if (areWordsEqual_(word, wordNow) > 0)
            return false;
        word = wordNow;
    }

    return true;
}

#endif
