#ifndef COURSE__HAVEEQUALWORDS_H
#define COURSE__HAVEEQUALWORDS_H

#include "../string_.h"

bool haveEqualWords(char *s){
    getBagOfWords(&_bag, s);
    for(size_t i = 0; i < _bag.size; i++)
        for(size_t j = i + 1; j < _bag2.size; j++){
            wordDescriptorToString(_bag.words[i], _stringBuffer);
            wordDescriptorToString(_bag.words[j], _stringBuffer + MAX_WORD_SIZE + 1);
            if(!strcmp_(_stringBuffer, _stringBuffer + MAX_WORD_SIZE + 1)){
                return true;
            }
        }

    return false;
}

#endif
