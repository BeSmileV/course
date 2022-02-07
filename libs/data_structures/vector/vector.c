#include "vector.h"

/// возвращает пустую структуру vector максимальным размером n
vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, n};
}

/// изменяет количество выделяемой памяти под вектор v на newCapacity,
/// если newCapacity равно 0, то в data будет NULL, если newCapacity меньше size,
/// size будет равно newCapacity
void reserve(vector *v, size_t newCapacity){
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if(v->data == NULL && newCapacity != 0){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if(newCapacity == 0)
        v->data = NULL;
    else if(newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

/// удаляет элементы вектора v
void clear(vector *v){
    v->size = 0;
}

/// освобождает память вектора v, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v){
    reserve(v, v->size);
}

/// освобождает память, выделенную вектору v
void deleteVector(vector *v){
    free(v->data);
}

/// возвращает 1, если вектор v пуст, иначе - 0
bool isEmpty(vector *v){
    return !v->size;
}

/// возвращает 1, если вектор v полный, иначе - 0
bool isFull(vector *v){
    return v->size == v->capacity;
}

/// возвращает значение i-го элемента вектора v
int getVectorValue(vector *v, size_t i){
    if(i >= v->size || i < 0){
        fprintf(stderr, "IndexError: a[i] is not exists");
        exit(1);
    }

    return v->data[i];
}

/// добавляет элемент x в конец вектора v, если вектор заполнен увеличивает
/// количество выделяемой памяти в 2 раза
void pushBack(vector *v, int x){
    if(v->size == v->capacity) {
        if (v->capacity == 0)
            v->capacity = 1;
        else
            v->capacity *= 2;
        reserve(v, v->capacity);
    }
    v->data[v->size++] = x;
}

/// удаляет последний элемент из вектора v
void popBack(vector *v){
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    v->size--;
}

/// возвращает указатель на index-ый элемент вектора v
int* atVector(vector *v, size_t index){
    int *element = (int*) malloc(sizeof(int));
    *element = v->data[index];
    if(index >= v->size || index < 0){
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return element;
}

/// возвращает указатель на последний элемент вектора v
int* back(vector *v){
    int *element = (int*) malloc(sizeof(int));
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    *element = v->data[v->size - 1];

    return element;
}

/// возвращает указатель на первый элемент вектора v
int* front(vector *v){
    int *element = (int*) malloc(sizeof(int));
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    *element = v->data[0];

    return element;
}