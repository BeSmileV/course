#ifndef COURSE__FINDFIRSTSTRLASTWORDOFSECONDSTR_H
#define COURSE__FINDFIRSTSTRLASTWORDOFSECONDSTR_H

#include "../string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination){
    char *end = copy(word.begin, word.end, destination);
    *end = '\0';
}

WordDescriptor findFirstStrLastWordOfSecondStr(char *s1, char *s2){
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for(size_t i = _bag.size; i >= 0; i--)
        for(size_t j = 0; j < _bag2.size; j++){
            wordDescriptorToString(_bag.words[i], _stringBuffer);
            wordDescriptorToString(_bag2.words[j], _stringBuffer + MAX_WORD_SIZE + 1);
            if(!strcmp_(_stringBuffer, _stringBuffer + MAX_WORD_SIZE + 1)){
                return _bag.words[i];
            }
        }
}

#endif
