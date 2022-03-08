#ifndef COURSE__FINDWORDBEFOREW_H
#define COURSE__FINDWORDBEFOREW_H

#include "../string_.h"

WordDescriptor findWordBeforeW(char *s, WordDescriptor w) {
    wordDescriptorToString(w, _stringBuffer + MAX_WORD_SIZE + 1);
    getBagOfWords(&_bag, s);
    char *rbegin;
    for (size_t i = 0; i < w.begin - s; i++) {
        wordDescriptorToString_(_bag.words[i], _stringBuffer);
        if (!strcmp_(_stringBuffer, _stringBuffer + MAX_WORD_SIZE + 1)){
            rbegin = _bag.words[i].begin;
            break;
        }
    }
    WordDescriptor res;

    getWordReverse(rbegin - 1, s - 1, &res);

    return res;
}

#endif
