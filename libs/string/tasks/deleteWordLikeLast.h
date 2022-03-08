#ifndef COURSE__DELETEWORDLIKELAST_H
#define COURSE__DELETEWORDLIKELAST_H

#include "../string_.h"

int isEqualWords(WordDescriptor w1, WordDescriptor w2) {
    wordDescriptorToString_(w1, _stringBuffer);
    wordDescriptorToString_(w2, _stringBuffer + 1 + MAX_WORD_SIZE);

    return !strcmp_(_stringBuffer, _stringBuffer + 1 + MAX_WORD_SIZE);
}

void deleteWordLikeLast(char *s) {
    if(*s == '\0')
        return;

    char buf[MAX_STRING_SIZE];
    char *endBuf = copy(s, s + strlen_(s), buf);
    *endBuf = '\0';
    getBagOfWords(&_bag, buf);
    size_t indexLast = _bag.size - 1;
    for (size_t i = 0; i < indexLast; i++) {
        if (!isEqualWords(_bag.words[i], _bag.words[indexLast])) {
            s = copy(_bag.words[i].begin, _bag.words[i].end, s);
            *(s++) = ' ';
        }
    }

    *(s - 1) = '\0';
}

#endif
