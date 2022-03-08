#ifndef COURSE__FINDWORDBEFOREW_H
#define COURSE__FINDWORDBEFOREW_H

#include "../string_.h"

WordDescriptor findWordBeforeW(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for(size_t i = 0; i < _bag.size; i++)
        for(size_t j = 0; j < _bag2.size; j++){
            wordDescriptorToString(_bag.words[i], _stringBuffer);
            wordDescriptorToString(_bag2.words[j], _stringBuffer + MAX_WORD_SIZE + 1);
            if(!strcmp_(_stringBuffer, _stringBuffer + MAX_WORD_SIZE + 1)){
                return _bag.words[i - 1];
            }
        }
}

#endif
