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
    deleteVector(&v);
}

void test_isEmpty_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(isEmpty(&v) == false);
    deleteVector(&v);
}

void test_isFull_FullVector() {
    vector v = createVector(2);

    assert(isFull(&v) == false);
    deleteVector(&v);
}

void test_isFull_notFullVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(isFull(&v) == true);
    deleteVector(&v);
}

void test_getVectorValue() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 12);

    assert(getVectorValue(&v, 0) == 10 && getVectorValue(&v, 1) == 12);
    deleteVector(&v);
}

void test_pushBack_emptyVector() {
    vector v = createVector(10);
    pushBack(&v, 10);
    assert(v.data[0] == 10);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    int *a = (int *) malloc(sizeof(int) * 5);
    vector v = {a, 5, 5};
    pushBack(&v, 6);
    assert(v.capacity == 10 && v.size == 6 && v.data[5] == 6);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(4);
    pushBack(&v, 10);
    pushBack(&v, 12);
    pushBack(&v, 121);

    assert(*atVector(&v, 0) == 10 && *atVector(&v, 1) == 12);
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*atVector(&v, 1) == 22);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 11);

    assert(*back(&v) == 11);
    deleteVector(&v);
}

void test_back_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*back(&v) == 22);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 11);

    assert(*front(&v) == 11);
    deleteVector(&v);
}

void test_front_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 11);
    pushBack(&v, 22);

    assert(*front(&v) == 11);
    deleteVector(&v);
}

void testVector() {
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

void test_swapRows() {
    int a[] = {1, 2, 3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 3 && m.values[0][1] == 4 && m.values[1][0] == 1 && m.values[1][1] == 2);
    freeMemMatrix(m);
}

void test_swapColumns() {
    int a[] = {1, 2, 3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    swapColumns(m, 0, 1);
    assert(m.values[0][0] == 2 && m.values[0][1] == 1 && m.values[1][0] == 4 && m.values[1][1] == 3);
    freeMemMatrix(m);
}

void test_isSquareMatrix_SquareMatrix() {
    int a[] = {1, 2, 3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_NotSquareMatrix() {
    int a[] = {1, 2, 3, 4, 5, 6};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_twoMatricesEqual_EqualMatrices() {
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_NotEqualMatrices() {
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 3, 3, 3};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_EMatrix() {
    int a[] = {1, 0, 0, 1};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NotEMatrix() {
    int a[] = {1, 1, 1, 0};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NotSquareMatrix() {
    int a[] = {1, 0, 0, 0, 1, 0};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_Symmetric(){
    int a[] = {2, 1, 1, 2};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSymmetric(){
    int a[] = {1, 2, 3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSquareMatrix() {
    int a[] = {1, 1, 1, 1, 1, 1};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix(){
    int a[] = {1, 2, 3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    transposeSquareMatrix(m1);
    int b[] = {1, 3, 2, 4};
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos(){
    int a[] = {1, 4, 23, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    position p = getMinValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex] == 1);
    freeMemMatrix(m);
}

void test_getMaxValuePos(){
    int a[] = {1, 4, 23, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    position p = getMaxValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex]  == 23);
    freeMemMatrix(m);
}

void testMatrix() {
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix_SquareMatrix();
    test_isSquareMatrix_NotSquareMatrix();
    test_twoMatricesEqual_EqualMatrices();
    test_twoMatricesEqual_NotEqualMatrices();
    test_isEMatrix_EMatrix();
    test_isEMatrix_NotEMatrix();
    test_isEMatrix_NotSquareMatrix();
    test_isSymmetricMatrix_Symmetric();
    test_isSymmetricMatrix_NotSymmetric();
    test_isSymmetricMatrix_NotSquareMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    testVector();
    testMatrix();

    return 0;
}