#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data = malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL && newCapacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    v->size = 0;
    v->capacity = 0;
    free(v->data);
}

bool isEmptyV(vectorVoid *v) {
    return !v->size;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size || index < 0) {
        fprintf(stderr, "IndexError: a[i] is not exists");
        exit(1);
    }
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    char *a = (char *) v->data + index * v->baseTypeSize;
    memcpy(a, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source){
    if(v->size == v->capacity) {
        if (v->capacity == 0)
            v->capacity = 1;
        else
            v->capacity *= 2;
        reserveV(v, v->capacity);
    }
    setVectorValueV(v, v->size++, source);
}

