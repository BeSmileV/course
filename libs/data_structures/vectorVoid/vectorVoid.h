#ifndef COURSE__VECTORVOID_H
#define COURSE__VECTORVOID_H

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа
} vectorVoid;

/// возвращает пустую структуру vector максимальным размером n
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

/// изменяет количество выделяемой памяти под вектор v на newCapacity,
/// если newCapacity равно 0, то в data будет NULL, если newCapacity
/// меньше size, size будет равно newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

/// освобождает память вектора v, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

/// удаляет элементы вектора v
void clearV(vectorVoid *v);

/// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

#endif
