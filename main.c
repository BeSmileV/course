#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"

#define ERROR_RATE 10e-7

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
    int a[] = {1, 2, 3,
               4, 5, 6};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_twoMatricesEqual_EqualMatrices() {
    int a[] = {1, 2,
               3, 4};
    int b[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_NotEqualMatrices() {
    int a[] = {1, 2,
               3, 4};
    int b[] = {3, 3,
               3, 3};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_EMatrix() {
    int a[] = {1, 0,
               0, 1};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NotEMatrix() {
    int a[] = {1, 1,
               1, 0};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_NotSquareMatrix() {
    int a[] = {1, 0, 0,
               0, 1, 0};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_Symmetric() {
    int a[] = {2, 1,
               1, 2};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSymmetric() {
    int a[] = {1, 2,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSquareMatrix() {
    int a[] = {1, 1, 1,
               1, 1, 1};
    matrix m = createMatrixFromArray(a, 2, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    int a[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    transposeSquareMatrix(m1);
    int b[] = {1, 3,
               2, 4};
    matrix m2 = createMatrixFromArray(b, 2, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos() {
    int a[] = {1, 4,
               23, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    position p = getMinValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex] == 1);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    int a[] = {1, 4,
               23, 4};
    matrix m = createMatrixFromArray(a, 2, 2);
    position p = getMaxValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex] == 23);
    freeMemMatrix(m);
}

/// возвращает наибольший элемент массива a
int getMax(int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];

    return max;
}

void test_insertionSortRowsMatrixByRowCriteria() {
    int a[] = {3, 4,
               5, 6,
               1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 2);
    insertionSortRowsMatrixByRowCriteria(m1, getMax);
    int b[] = {1, 2,
               3, 4,
               5, 6};
    matrix m2 = createMatrixFromArray(b, 3, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_insertionSortColsMatrixByRowCriteria() {
    int a[] = {1, 3, 2,
               4, 6, 5};
    matrix m1 = createMatrixFromArray(a, 2, 3);
    selectionSortColsMatrixByColCriteria(m1, getMax);
    int b[] = {1, 2, 3,
               4, 5, 6};
    matrix m2 = createMatrixFromArray(b, 2, 3);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void testMatrix() {
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix_SquareMatrix();
    test_isSquareMatrix_NotSquareMatrix();
    test_twoMatricesEqual_EqualMatrices();
    test_twoMatricesEqual_NotEqualMatrices();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByRowCriteria();
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

// TASKS
// NUM 2
/// упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMinElement() {
    int a[] = {33, 25, 54,
               12, 22, 21,
               1, 3, 2};
    matrix m = createMatrixFromArray(a, 3, 3);
    sortRowsByMinElement(m);
    int b[] = {1, 3, 2,
               12, 22, 21,
               33, 25, 54};
    matrix res = createMatrixFromArray(b, 3, 3);
    assert(twoMatricesEqual(m, res));

    freeMemMatrix(m);
    freeMemMatrix(res);
}

// NUM 3
/// возвращает наименьший элемент массива a
int getMin(int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];

    return min;
}

/// упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement() {
    int a[] = {4, 33, 22,
               22, 2, 211,
               211, 55, 1};
    matrix m = createMatrixFromArray(a, 3, 3);
    sortColsByMinElement(m);
    int b[] = {22, 33, 4,
               211, 2, 22,
               1, 55, 211};
    matrix res = createMatrixFromArray(b, 3, 3);
    assert(twoMatricesEqual(m, res));

    freeMemMatrix(m);
    freeMemMatrix(res);
}

// NUM 4
/// возвращает произведение строки indexRow матрицы m1 и столбца indexCol матрицы m2,
/// линна строки и столбца n
int getMulOfRowAndCol_(matrix m1, matrix m2, int indexRow, int indexCol, int n) {
    int mul = 0;
    for (size_t i = 0; i < n; i++)
        mul += m1.values[indexRow][i] * m2.values[i][indexCol];

    return mul;
}

void test_getMulOfRowAndCol() {
    int a[] = {5, 2, 1,
               3, 5, 6,
               4, 3, 2};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(getMulOfRowAndCol_(m1, m2, 1, 2, 3) == 93);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

/// возвращает матрицу равной произведению матриц m1 и m2
matrix mulMatrices_(matrix m1, matrix m2) {
    int mulNRows = m1.nRows;
    int mulNCols = m2.nCols;
    int n = m1.nCols;
    matrix mul = getMemMatrix(mulNRows, mulNCols);
    for (int i = 0; i < mulNRows; i++) {
        for (int j = 0; j < mulNCols; j++)
            mul.values[i][j] = getMulOfRowAndCol_(m1, m2, i, j, n);
    }

    return mul;
}

void test_mulMatrices() {
    int a[] = {5, 2, 1,
               3, 5, 6,
               4, 3, 2};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    matrix mul = mulMatrices_(m1, m2);
    int c[] = {20, 28, 36,
               65, 79, 93,
               30, 39, 48};
    matrix res = createMatrixFromArray(c, 3, 3);

    assert(twoMatricesEqual(res, mul));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(res);
    freeMemMatrix(mul);
}

// NUM 5
/// возвращает суммы массива a размера n
long long getSum(int *a, int n) {
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void test_getSum() {
    int a[] = {1, 2, 3, 4};
    assert(getSum(a, 4) == 10);
}

/// возвращает true, если все элементы массива a размера n
/// уникальны, иначе - false
bool isUnique(long long *a, int n) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

void test_isUnique() {
    long long a[] = {1, 2, 3, 4};
    long long b[] = {1, 2, 3, 3};
    assert(isUnique(a, 4) && !isUnique(b, 4));
}

/// транспонировать матрицу, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols) {
    long long *a = (long long *) malloc(sizeof(long long) * nRows);
    for (size_t i = 0; i < nRows; i++)
        a[i] = getSum(m.values[i], nCols);
    if (isUnique(a, nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasEqualSumOfRows_NotEqual() {
    int a[] = {1, 2,
               3, 4};
    matrix ma = createMatrixFromArray(a, 2, 2);
    transposeIfMatrixHasEqualSumOfRows(ma, ma.nRows, ma.nCols);
    int resA[] = {1, 3,
                  2, 4};
    matrix mResA = createMatrixFromArray(resA, 2, 2);

    assert(twoMatricesEqual(ma, mResA));

    freeMemMatrix(ma);
    freeMemMatrix(mResA);
}

void test_transposeIfMatrixHasEqualSumOfRows_Equal() {
    int b[] = {2, 2,
               3, 1};
    matrix mb = createMatrixFromArray(b, 2, 2);
    transposeIfMatrixHasEqualSumOfRows(mb, mb.nRows, mb.nCols);
    int resB[] = {2, 2,
                  3, 1};
    matrix mResB = createMatrixFromArray(resB, 2, 2);

    assert(twoMatricesEqual(mb, mResB));

    freeMemMatrix(mb);
    freeMemMatrix(mResB);
}

// NUM 6
/// возвращает true, если матрицы взаимообратные, иначе - false
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mul = mulMatrices_(m1, m2);
    bool isE = isEMatrix(mul);
    freeMemMatrix(mul);
    return isE;
}

void test_isMutuallyInverseMatrices_MutuallyInverse() {
    int a[] = {1, 1, 0,
               1, 1, 1,
               0, 1, 1};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {0, 1, -1,
               1, -1, 1,
               -1, 1, 0};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_NotMutuallyInverse() {
    int a[] = {1, 1, 12,
               1, 1, 1,
               0, 1, 1};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {0, 1, -1,
               1, -1, 1,
               -1, 1, 0};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

// NUM 7
/// возвращает максимальное значение из a и b
int max(int a, int b) {
    return a > b ? a : b;
}

void test_max() {
    assert(max(1, 2) == 2);
    assert(max(2222, -1000) == 2222);
}

/// возвращает сумму максимальных значений псевдодиагоналей матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    size_t n = m.nCols + m.nRows - 2;
    int *arrayOFMaxes = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < m.nRows - 1; i++)
        arrayOFMaxes[i] = m.values[i + 1][0];

    for (int i = 0; i < m.nCols - 1; i++)
        arrayOFMaxes[i + m.nRows - 1] = m.values[0][i + 1];

    for (int i = 1; i < m.nRows; i++)
        for (int j = 1; j < m.nCols; j++) {
            int dif = j - i;
            if (dif > 0)
                arrayOFMaxes[dif + m.nRows - 2] = max(arrayOFMaxes[dif + m.nRows - 2], m.values[i][j]);
            else if (dif < 0)
                arrayOFMaxes[-dif - 1] = max(arrayOFMaxes[-dif - 1], m.values[i][j]);
        }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arrayOFMaxes[i];

    return sum;
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    int a[] = {1, 3, 5, 7,
               2, 5, 6, 7,
               14, 2, 3, -1};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 36);

    freeMemMatrix(m);
}

int main() {
    testVector();
    testMatrix();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getMulOfRowAndCol();
    test_mulMatrices();
    test_transposeIfMatrixHasEqualSumOfRows_NotEqual();
    test_transposeIfMatrixHasEqualSumOfRows_Equal();
    test_isMutuallyInverseMatrices_MutuallyInverse();
    test_isMutuallyInverseMatrices_NotMutuallyInverse();
    test_max();
    test_findSumOfMaxesOfPseudoDiagonal();

    int nRows1, nCols1;
    scanf("%d %d", &nRows1, &nCols1);

    matrix m1 = getMemMatrix(nRows1, nCols1);
    inputMatrix(m1);

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m1));

    return 0;
}