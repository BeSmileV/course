#ifndef COURSE__GETSTRINGDIFFERENTFROMLASTWORD_H
#define COURSE__GETSTRINGDIFFERENTFROMLASTWORD_H

#include "../string_.h"

int isNotEqualWords(WordDescriptor w1, WordDescriptor w2) {
    wordDescriptorToString_(w1, _stringBuffer);
    wordDescriptorToString_(w2, _stringBuffer + 1 + MAX_WORD_SIZE);

    return strcmp_(_stringBuffer, _stringBuffer + 1 + MAX_WORD_SIZE);
}

char *getStringDifferentFromLastWord(char *s) {
    char *str = malloc(sizeof(char) * (MAX_STRING_SIZE + 1));
    char *Write = str;
    getBagOfWords(&_bag, s);
    size_t n = _bag.size - 1;
    for (size_t i = 0; i < n; i++)
        if (isNotEqualWords(_bag.words[i], _bag.words[n])) {
            Write = copy(_bag.words[i].begin, _bag.words[i].end, Write);
            *(Write++) = ' ';
        }
    *(Write - 1) = '\0';

    return str;
}

#endif
