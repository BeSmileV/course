#ifndef COURSE__VECTOR_H
#define COURSE__VECTOR_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

/// возвращает пустую структуру vector максимальным размером n
vector createVector(size_t n);

/// изменяет количество выделяемой памяти под вектор v на newCapacity,
/// если newCapacity равно 0, то в data будет NULL, если newCapacity
/// меньше size, size будет равно newCapacity
void reserve(vector *v, size_t newCapacity);

/// удаляет элементы вектора v
void clear(vector *v);

/// освобождает память вектора v, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

/// освобождает память, выделенную вектору v
void deleteVector(vector *v);

/// возвращает 1, если вектор v пуст, иначе - 0
bool isEmpty(vector *v);

/// возвращает 1, если вектор v полный, иначе - 0
bool isFull(vector *v);

/// возвращает значение i-го элемента вектора v
int getVectorValue(vector *v, size_t i);

/// добавляет элемент x в конец вектора v, если вектор заполнен увеличивает
/// количество выделяемой памяти в 2 раза
void pushBack(vector *v, int x);

/// удаляет последний элемент из вектора v
void popBack(vector *v);

/// возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index);

/// возвращает указатель на последний элемент вектора v
int *back(vector *v);

/// возвращает указатель на первый элемент вектора v
int *front(vector *v);

#endif
