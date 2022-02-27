#include "string_.h"

size_t strlen_(const char *s){
    char *a = s;
    while (*a != '\0')
        a++;

    return a - s;
}
