#ifndef COURSE__STRING__H
#define COURSE__STRING__H

#include <stdio.h>
#include <ctype.h>

/// возвращает значение длины строки s
size_t strlen_(const char *s);

/// возвращает указатель на первый элемент с кодом ch,
/// расположенным между begin и end не включая end,
/// если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch);

/// возвращает указатель на первый, отличный от пробельного, символ,
/// если символ не найден, возвращается значение end
char *findNonSpace(char *begin);

/// возвращает указатель на первый пробельный символ,
/// если символ не найден, возвращается значение end
char *findSpace(char *begin);

/// возвращает указатель на первый справа символ, отличный от пробельных,
/// расположенный на ленте памяти, начиная с rend и заканчивая rbegin,
/// если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

/// возвращает указатель на первый справа пробельный символ
/// расположенный на ленте памяти, начиная с rend и заканчивая rbegin,
/// если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);

#endif
