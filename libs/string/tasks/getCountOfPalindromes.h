#ifndef COURSE__GETCOUNTOFPALINDROMES_H
#define COURSE__GETCOUNTOFPALINDROMES_H

#include "../string_.h"

bool isPalindrome(WordDescriptor word){
    char s[MAX_WORD_SIZE];
    char *end = copy(word.begin, word.end, s);
    *end = '\0';
    size_t len = strlen_(s);
    size_t n = len / 2;
    for(size_t i = 0; i < n; i++)
        if(s[i] != s[len - 1 - i])
            return false;

    return true;
}

int getCountOfPalindromes(char *s){
    int count = 0;
    WordDescriptor word;
    while(getWord(s, &word)){
        if(isPalindrome(word))
            count++;

        s = word.end;
    }

    return count;
}

#endif
