#include "vector.h"

vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity){
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if(v->data == NULL && newCapacity != 0){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if(newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
}

bool isEmpty(vector *v){
    return v->size;
}

bool isFull(vector *v){
    return v->size;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if(v->size == v->capacity) {
        v->capacity *= 2;
        if (v->capacity == 0)
            v->capacity = 1;
        reserve(v, v->capacity);
    }
    v->data[v->size++] = x;
}

void popBack(vector *v){
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index){
    int *element = (int*) malloc(sizeof(int));
    *element = v->data[index];
    if(index >= v->size || index < 0){
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return element;
}

int* back(vector *v){
    int *element = (int*) malloc(sizeof(int));
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    *element = v->data[v->size - 1];

    return element;
}

int* front(vector *v){
    int *element = (int*) malloc(sizeof(int));
    if(v->size == 0){
        fprintf(stderr, "empty vector");
        exit(1);
    }
    *element = v->data[0];

    return element;
}