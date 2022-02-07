#ifndef COURSE__VECTORVOID_H
#define COURSE__VECTORVOID_H

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

/// возвращает 1, если вектор v пуст, иначе - 0
bool isEmptyV(vectorVoid *v);

/// возвращает 1, если вектор v полный, иначе - 0
bool isFullV(vectorVoid *v);

/// записывает значение index-го элемента вектора в ячейку памяти по адресу destination
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

/// записывает на index-ый элемент вектора v значение, расположенное по
/// адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

/// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

/// добавляет элемент по адресу source в конец вектора v, если вектор заполнен увеличивает
/// количество выделяемой памяти в 2 раза
void pushBackV(vectorVoid *v, void *source);

#endif
