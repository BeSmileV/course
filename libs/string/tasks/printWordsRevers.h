#ifndef COURSE__PRINTWORDSREVERS_H
#define COURSE__PRINTWORDSREVERS_H

#include "../string_.h"

void getBagOfWords_(BagOfWords *bag, char *s){
    WordDescriptor word;
    bag->size = 0;
    while(getWord(s, &word)){
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

void printWordsRevers(char *s){
    getBagOfWords_(&_bag, s);
    for(int i = _bag.size - 1; i >= 0; i--){
        char word[MAX_WORD_SIZE];
        char *end = copy(_bag.words[i].begin, _bag.words[i].end, word);
        *end ='\0';
        puts(word);
    }
}

#endif
