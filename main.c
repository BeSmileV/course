#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"

void test_isEmpty_emptyVector() {
    vector v = createVector(2);

    assert(isEmpty(&v) == true);
}

void test_isEmpty_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(isEmpty(&v) == false);
}

void test_isFull_FullVector() {
    vector v = createVector(2);

    assert(isFull(&v) == false);
}

void test_isFull_notFullVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(isFull(&v) == true);
}

void test_getVectorValue() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(getVectorValue(&v, 0) == 10 && getVectorValue(&v, 1) == 12);
}

void test_pushBack_emptyVector() {
    vector v = createVector(10);
    pushBack(&v, 10);
    assert(v.data[0] == 10);
}

void test_pushBack_fullVector() {
    int *a = (int *) malloc(sizeof(int) * 5);
    vector v = {a, 5, 5};
    pushBack(&v, 6);
    assert(v.capacity == 10 && v.size == 6 && v.data[5] == 6);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(4);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 121);

    assert(*atVector(&v, 0) == 10 && *atVector(&v, 1) == 12);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*atVector(&v, 1) == 22);
}

void test_back_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 11);

    assert(*back(&v) == 11);
}

void test_back_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*back(&v) == 22);
}

void test_front_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 11);

    assert(*front(&v) == 11);
}

void test_front_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*front(&v) == 11);
}

void test() {
    test_isFull_FullVector();
    test_isFull_notFullVector();
    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
    test_getVectorValue();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_notEmptyVector();
    test_back_oneElementInVector();
    test_front_notEmptyVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);
    outputMatrix(m);

    return 0;
}