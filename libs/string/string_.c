#include "string_.h"

size_t strlen_(const char *s) {
    char *a = (char *)s;
    while (*a != '\0')
        a++;

    return a - s;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t n = endSource - beginSource;
    memcpy(beginDestination, beginSource, n);

    return beginDestination + n;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;
        rbeginSource--;
    }

    return beginDestination;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word){
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend)
        return 0;

    word->begin = findSpaceReverse(word->end, rend);
    word->end++;
    word->begin++;

    return 1;
}

char *getEndOfString(char *s) {
    return s + strlen_(s);
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2){
    char copyW1[MAX_WORD_SIZE];
    char copyW2[MAX_WORD_SIZE];
    char *endW1 = copy(w1.begin, w1.end, copyW1);
    char *endW2 = copy(w2.begin, w2.end, copyW2);
    *endW1 ='\0';
    *endW2 ='\0';

    return strcmp_(copyW1, copyW2);
}

void getBagOfWords(BagOfWords *bag, char *s){
    WordDescriptor word;
    bag->size = 0;
    while(getWord(s, &word)){
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

void wordDescriptorToString_(WordDescriptor word, char *destination){
    char *end = copy(word.begin, word.end, destination);
    *end = '\0';
}