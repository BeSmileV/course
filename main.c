#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/tests/tests_string_.h"
#include "libs/string/tasks/getCountOfPalindromes.h"

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

void test_task2() {
    test_sortRowsByMinElement();
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

void test_task3() {
    test_sortColsByMinElement();
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

void test_task4() {
    test_getMulOfRowAndCol();
    test_mulMatrices();
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

void test_task5() {
    test_transposeIfMatrixHasEqualSumOfRows_NotEqual();
    test_transposeIfMatrixHasEqualSumOfRows_Equal();
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

void test_task6() {
    test_isMutuallyInverseMatrices_MutuallyInverse();
    test_isMutuallyInverseMatrices_NotMutuallyInverse();
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
    size_t n = m.nCols + m.nRows - 1;
    int *arrayOFMaxes = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < m.nRows - 1; i++)
        arrayOFMaxes[i] = m.values[i + 1][0];

    for (int i = 0; i < m.nCols; i++)
        arrayOFMaxes[i + m.nRows - 1] = m.values[0][i];

    for (int i = 1; i < m.nRows; i++)
        for (int j = 1; j < m.nCols; j++) {
            int dif = j - i;
            if (dif >= 0)
                arrayOFMaxes[dif + m.nRows - 1] = max(arrayOFMaxes[dif + m.nRows - 1], m.values[i][j]);
            else
                arrayOFMaxes[-dif - 1] = max(arrayOFMaxes[-dif - 1], m.values[i][j]);
        }
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arrayOFMaxes[i];
    sum -= arrayOFMaxes[m.nRows - 1];

    free(arrayOFMaxes);

    return sum;
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    int a[] = {1, 3, 5, 7,
               2, 5, 6, 7,
               14, 2, 3, -1};
    matrix m1 = createMatrixFromArray(a, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 36);
    int b[] = {1, 3, 3, 2,
               22, 5, 6, 2,
               124, 12, 3, 2};
    matrix m2 = createMatrixFromArray(b, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m2) == 157);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task7() {
    test_max();
    test_findSumOfMaxesOfPseudoDiagonal();
}

// NUM 8
/// возвращает минимальный элемент матрицы в треугольной области выше максимального
int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int min = m.values[max.rowIndex][max.colIndex];
    for (int i = 0; i < max.rowIndex; i++) {
        int leftColIndex = max.colIndex - max.rowIndex + i;
        if (leftColIndex < 0)
            leftColIndex = 0;
        int rightColIndex = leftColIndex + 2 * max.rowIndex + 1;
        if (rightColIndex >= m.nCols)
            rightColIndex = m.nCols - 1;
        for (int j = leftColIndex; j <= rightColIndex; j++)
            if (min > m.values[i][j])
                min = m.values[i][j];
    }

    return min;
}

void test_getMinInArea_inTheCenter() {
    int a[] = {10, 7, 5, 6,
               3, 11, 8, 9,
               4, 1, 12, 2};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_getMinInArea_inTheUpperLeftCorner() {
    int a[] = {-1, 7, 5, 6,
               3, 11, 8, 9,
               4, 1, 12, 2};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(getMinInArea(m) == -1);

    freeMemMatrix(m);
}

void test_getMinInArea_inTheUpperRightCorner() {
    int a[] = {10, 7, 5, -1,
               3, 11, 8, 9,
               4, 1, 12, 2};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(getMinInArea(m) == -1);

    freeMemMatrix(m);
}

void test_getMinInArea_MaxInTheLowerLeftCorner() {
    int a[] = {10, 7, 5, 6,
               3, 11, 8, 9,
               12, 1, 11, 2};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(getMinInArea(m) == 3);

    freeMemMatrix(m);
}

void test_getMinInArea_MaxInTheLowerRightCorner() {
    int a[] = {10, 7, 5, 6,
               3, 11, 8, 9,
               10, 1, 11, 12};
    matrix m = createMatrixFromArray(a, 3, 4);
    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_task8() {
    test_getMinInArea_inTheCenter();
    test_getMinInArea_inTheUpperLeftCorner();
    test_getMinInArea_inTheUpperRightCorner();
    test_getMinInArea_MaxInTheLowerLeftCorner();
    test_getMinInArea_MaxInTheLowerRightCorner();
}

// NUM 9
/// возвращает значение дистанции точки, хранящейся в массиве a размера n, до начал координат
float getDistance(int *a, int n) {
    float sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += (float) (a[i] * a[i]);

    return sqrtf(sum);
}

void test_getDistance() {
    int a[] = {3, 4, 1, 2, 3};
    assert(getDistance(a, 5) - 7 < FLT_EPSILON);
    int b[] = {1, 2, 3};
    assert(getDistance(b, 3) - sqrt(14) < FLT_EPSILON);
    int c[] = {22, 3, 4};
    assert(getDistance(c, 3) - sqrt(509) < FLT_EPSILON);
}

/// выполняет сортировку вставками строк матрицы m по неубыванию
/// значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *a = (float *) malloc(sizeof(float) * m.nRows);
    for (size_t i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        float t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] - t > FLT_EPSILON) {
            a[j] = a[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        a[j] = t;
    }
    free(a);
}

void test_insertionSortRowsMatrixByRowCriteriaF() {
    int a[] = {3, 4,
               5, 6,
               1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 2);
    insertionSortRowsMatrixByRowCriteriaF(m1, getDistance);
    int b[] = {1, 2,
               3, 4,
               5, 6};
    matrix m2 = createMatrixFromArray(b, 3, 2);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

/// сортирует точки, хранящихся в матрице m по неубыванию их расстояний до начала координат
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances() {
    int a[] = {12, 4,
               5, 22,
               1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 2);
    insertionSortRowsMatrixByRowCriteriaF(m1, getDistance);
    int b[] = {1, 2,
               12, 4,
               5, 22};
    matrix m2 = createMatrixFromArray(b, 3, 2);

    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task9() {
    test_getDistance();
    test_insertionSortRowsMatrixByRowCriteriaF();
    test_sortByDistances();
}

// NUM 10
/// возвращает значение больше нуля, если значение по указателю
/// pa больше pb, если наоборот значение меньше 0, иначе - 0
int cmp_long_long(const void *pa, const void *pb) {
    long long *a = (long long *) pa;
    long long *b = (long long *) pb;

    return (int) (*a - *b);
}

/// возвращает количество уникальных элементов в упорядоченном массиве a размера n
int countNUnique(long long *a, int n) {
    int count = 0;
    for (size_t i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            count++;

    return count + (n != 0);
}

void test_countNUnique() {
    long long a[] = {1, 2, 2, 3, 4};
    assert(countNUnique(a, 5) == 4);
    long long b[] = {1, 2, 3, 4};
    assert(countNUnique(b, 4) == 4);
}

/// возвращает количество классов эквивалентных строк данной прямоугольной матрицы m
int countEqClassesByRowsSum(matrix m) {
    int n = m.nRows;
    long long *a = (long long *) malloc(sizeof(long long) * n);
    for (size_t i = 0; i < n; i++)
        a[i] = getSum(m.values[i], m.nCols);
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count = countNUnique(a, n);

    free(a);

    return count;
}

void test_countEqClassesByRowsSum() {
    int a[] = {7, 1,
               8, 0,
               2, 3,
               4, 1};
    matrix m1 = createMatrixFromArray(a, 4, 2);
    assert(countEqClassesByRowsSum(m1) == 2);

    int b[] = {7, 1,
               2, 7,
               5, 4,
               4, 3,
               1, 6,
               8, 0};
    matrix m2 = createMatrixFromArray(b, 6, 2);
    assert(countEqClassesByRowsSum(m2) == 3);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task10() {
    test_countNUnique();
    test_countEqClassesByRowsSum();
}

// NUM 11
/// заполняет массив a суммой элементов столбов матрицы m
void getSumOfColsElements(matrix m, long long *a) {
    for (size_t j = 0; j < m.nCols; j++)
        for (size_t i = 0; i < m.nRows; i++)
            a[j] += m.values[i][j];
}

void test_getSumOfColsElements() {
    long long *b = (long long *) calloc(4, sizeof(long long));
    int a[] = {10, 7, 5, 6,
               3, 11, 8, 9,
               10, 1, 11, 12};
    matrix m = createMatrixFromArray(a, 3, 4);
    getSumOfColsElements(m, b);

    assert(b[0] == 23 && b[1] == 19 && b[2] == 24 && b[3] == 27);

    freeMemMatrix(m);
    free(b);
}

/// возвращает количество "особых" элементов матрицы m, считая элемент "особым",
/// если он больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m) {
    long long *a = (long long *) calloc(m.nCols, sizeof(long long));
    getSumOfColsElements(m, a);

    int count = 0;
    for (size_t j = 0; j < m.nCols; j++)
        for (size_t i = 0; i < m.nRows; i++)
            if (m.values[i][j] * 2 > a[j]) {
                count++;
                break;
            }

    free(a);

    return count;
}

void test_getNSpecialElement() {
    int a[] = {2, 3, 9,
               5, 4, 3,
               2, 0, 0};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {3, 3, 4,
               5, 6, 7,
               8, 9, 10};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(getNSpecialElement(m1) == 3 && getNSpecialElement(m2) == 0);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task11() {
    test_getSumOfColsElements();
    test_getNSpecialElement();
}

// NUM 12
/// возвращает позицию самого левого минимального элемента
position getLeftMin(matrix m) {
    position min = {0, 0};
    for (int j = 0; j < m.nCols; j++)
        for (int i = 0; i < m.nRows; i++)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }

    return min;
}

void test_getLeftMin() {
    int a[] = {7, 1, 8, 2,
               2, 3, 4, 1};
    matrix m1 = createMatrixFromArray(a, 2, 4);
    position min = getLeftMin(m1);

    assert(min.rowIndex == 0 && min.colIndex == 1);

    freeMemMatrix(m1);
}

/// заменяет предпоследнюю строку матрицы m первым из столбцов, в котором
/// находится минимальный элемент матрицы
void swapPenultimateRow(matrix m, int n) {
    position min = getLeftMin(m);
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t i = 0; i < n; i++)
        a[i] = m.values[i][min.colIndex];
    for (size_t i = 0; i < n; i++)
        m.values[m.nRows - 2][i] = a[i];

    free(a);
}

void test_swapPenultimateRow() {
    int a[] = {2, 5, 7,
               3, 1, 3,
               4, 6, 9};
    matrix m1 = createMatrixFromArray(a, 3, 3);
    swapPenultimateRow(m1, m1.nRows);

    int b[] = {2, 5, 7,
               5, 1, 6,
               4, 6, 9};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task12() {
    test_getLeftMin();
    test_swapPenultimateRow();
}

// NUM 13
/// возвращает true, если массив отсортирован, иначе - false
bool isNonDescendingSorted(int *a, int n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

void test_isNonDescendingSorted_Sorted() {
    int a[] = {1, 2, 3, 4};
    assert(isNonDescendingSorted(a, 4));
}

void test_isNonDescendingSorted_Unsorted() {
    int a[] = {1, 4, 3, 2};
    assert(!isNonDescendingSorted(a, 4));
}

/// возвращает true, если все строки матрицы m отсортирован, иначе - false
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

void test_hasAllNonDescendingRows_Unsorted() {
    int a[] = {2, 5, 7,
               3, 1, 3,
               4, 6, 9};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    assert(!hasAllNonDescendingRows(m1));

    freeMemMatrix(m1);
}

void test_hasAllNonDescendingRows_Sorted() {
    int a[] = {2, 5, 7,
               3, 3, 3,
               4, 6, 9};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    assert(hasAllNonDescendingRows(m1));

    freeMemMatrix(m1);
}

/// возвращает число матриц в массиве матриц ms размера nMatrix,
/// строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (size_t i = 0; i < nMatrix; i++)
        count += hasAllNonDescendingRows(ms[i]);

    return count;
}

void test_countNonDescendingRowsMatrices() {
    int a[] = {1, 2,
               3, 4,

               2, 1,
               3, 4,

               2, 2,
               3, 3};
    matrix *ms = createArrayOfMatrixFromArray(a, 3, 2, 2);
    assert(countNonDescendingRowsMatrices(ms, 3) == 2);

    freeMemMatrices(ms, 3);
}

void test_task13() {
    test_isNonDescendingSorted_Sorted();
    test_isNonDescendingSorted_Unsorted();
    test_hasAllNonDescendingRows_Unsorted();
    test_hasAllNonDescendingRows_Sorted();
    test_countNonDescendingRowsMatrices();
}

// NUM 14
/// возвращает количество элементов равны value в массиве a размера n
int countValues(const int *a, int n, int value) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}

void test_countValues() {
    int a[] = {1, 2, 3, 3, 4, 3, 2};

    assert(countValues(a, 7, 3) == 3 && countValues(a, 7, 2) == 2);
}

/// возвращает количество нулевых строк в матрице m
int countZeroRows(matrix m) {
    int count = 0;
    for (size_t i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;

    return count;
}

void test_countZeroRows() {
    int a[] = {0, 0, 0,
               0, 0, 3,
               4, 0, 9};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {0, 1, 0,
               0, 1, 3,
               4, 0, 9};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(countZeroRows(m1) == 1 && countZeroRows(m2) == 0);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

/// выводит матрицы массива матриц ms размера nMatrix,
/// имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *a = (int *) malloc(sizeof(int) * nMatrix);

    int max = countZeroRows(ms[0]);
    a[0] = max;
    for (size_t i = 1; i < nMatrix; i++) {
        a[i] = countZeroRows(ms[i]);
        if (a[i] > max)
            max = a[i];
    }
    for (size_t i = 0; i < nMatrix; i++)
        if (a[i] == max)
            outputMatrix(ms[i]);

    free(a);
}

void test_task14() {
    test_countValues();
    test_countZeroRows();
}

// NUM 15
/// возвращает максимальную абсолютную величину матрицы m
float getMaxAbs(matrixf m) {
    float max = fabsf(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++) {
            float a = fabsf(m.values[i][j]);
            if (max - a < FLT_EPSILON)
                max = a;
        }

    return max;
}

void test_getMaxAbs() {
    float a[] = {1.2f, 2.2f, 33.222f,
                 12.2f, 22.2f, 33.2f,
                 10.2f, 21.2f, 33.2221f};
    matrixf m1 = createMatrixFromArrayF(a, 3, 3);

    float b[] = {-100.22f, -100.2221f, 21,
                 21.22f, 76.4f, 45.3f,
                 9.9f, 8.9f, 7.6f};
    matrixf m2 = createMatrixFromArrayF(b, 3, 3);

    assert(fabsf(getMaxAbs(m1) - 33.2221f) < FLT_EPSILON && fabsf(getMaxAbs(m2) - 100.2221f) < FLT_EPSILON);

    freeMemMatrixF(m1);
    freeMemMatrixF(m2);
}

/// выводит матрицы массива матриц ms размера n с наименьшем значение abs
void printMatrixWithMinAbsOfElement(matrixf *ms, int n) {
    float *a = (float *) malloc(sizeof(float) * n);
    float min = getMaxAbs(ms[0]);
    a[0] = min;
    for (size_t i = 1; i < n; i++) {
        a[i] = getMaxAbs(ms[i]);
        if (min - a[i] > FLT_EPSILON)
            min = a[i];
    }

    for (size_t i = 0; i < n; i++)
        if (fabsf(a[i] - min) < FLT_EPSILON)
            outputMatrixF(ms[i]);

    free(a);
}

void test_task15() {
    test_getMaxAbs();
}

// NUM 16
/// возвращает меньшее значение из a и b
int min2(int a, int b) {
    return a < b ? a : b;
}

void test_min2() {
    assert(min2(2, 3) == 2);
}

/// возвращает true, если элемент под индексом indexCols особый в массиве a
bool isSpecialElement(const int *a, int n, int indexCols) {
    for (int i = 0; i < indexCols; i++)
        if (a[indexCols] <= a[i])
            return false;
    for (int i = indexCols + 1; i < n; i++)
        if (a[indexCols] >= a[i])
            return false;

    return true;
}

void test_isSpecialElement() {
    int a[] = {2, 3, 5, 5, 4};

    assert(isSpecialElement(a, 5, 0) &&
           isSpecialElement(a, 5, 1) &&
           !isSpecialElement(a, 5, 2) &&
           !isSpecialElement(a, 5, 3) &&
           !isSpecialElement(a, 5, 4));
}

/// возвращает количество особых элементов в матрице m
int getNSpecialElement2(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (isSpecialElement(m.values[i], m.nCols, j))
                count++;

    return count;
}

void test_getNSpecialElement2() {
    int a[] = {2, 3, 5, 5, 4,
               6, 2, 3, 8, 12,
               12, 12, 2, 1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 5);

    int b[] = {5, 5, 5,
               1, 1, 1,
               3, 3, 3};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(getNSpecialElement2(m1) == 4 && getNSpecialElement2(m2) == 0);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task16() {
    test_min2();
    test_isSpecialElement();
    test_getNSpecialElement2();
}

// NUM 17
/// возвращает значение скалярного произведения векторов a и b
/// в n-ом пространстве
double getScalarProduct(int *a, int *b, int n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i] * b[i];

    return sum;
}

void test_getScalarProduct() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 3, 1};
    assert(getScalarProduct(a, b, 4) == 21);
}

/// возвращает значение длины вектора a в n-ом пространстве
double getVectorLength(int *a, int n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

void test_getVectorLength() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 3, 1};
    assert(getVectorLength(a, 4) - sqrt(30) < DBL_EPSILON
           && getVectorLength(b, 4) - sqrt(23) < DBL_EPSILON);
}

/// возвращает значение косинуса угла между векторами a и b в n-ом пространстве
double getCosine(int *a, int *b, int n) {
    return getScalarProduct(a, b, n) / (getVectorLength(a, n) * getVectorLength(b, n));
}

void test_getCosine() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 3, 1};
    assert(getCosine(a, b, 4) - 21 / (sqrt(30) * sqrt(23)) < DBL_EPSILON);
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int indexMax = 0;
    double minCosine = getCosine(m.values[0], b, m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        double cos = getCosine(m.values[i], b, m.nCols);
        if (cos - minCosine < DBL_EPSILON) {
            minCosine = cos;
            indexMax = i;
        }
    }

    return indexMax;
}

void test_getVectorIndexWithMaxAngle() {
    int c[] = {1, 2, 3, 4, 5};
    int a[] = {2, 3, 5, 5, 4,
               6, 2, 3, 8, 12,
               12, 12, 2, 1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 5);

    int d[] = {1, 2, 3};
    int b[] = {5, 5, 5,
               1, 1, 1,
               3, 22, 3};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(getVectorIndexWithMaxAngle(m1, c) == 2 && getVectorIndexWithMaxAngle(m2, d) == 2);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task17() {
    test_getScalarProduct();
    test_getVectorLength();
    test_getCosine();
    test_getVectorIndexWithMaxAngle();
}

// NUM 18
/// возвращает скалярное произведение строки i и столбца j матрицы m
long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long mul = 0;
    for (size_t k = 0; k < m.nRows; k++)
        mul += m.values[i][k] * m.values[k][j];

    return mul;
}

void test_getScalarProductRowAndCol() {
    int a[] = {5, 2, 1,
               3, 5, 6,
               4, 3, 2};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    assert(getScalarProductRowAndCol(m1, 1, 2) == 45 && getScalarProductRowAndCol(m1, 1, 0) == 54);

    freeMemMatrix(m1);
}

/// возвращает скалярное произведение строки, в которой находится наибольший
/// элемент матрицы, на столбец с наименьшим элементом
long long getSpecialScalarProduct(matrix m) {
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);

    return getScalarProductRowAndCol(m, max.rowIndex, min.colIndex);
}

void test_getSpecialScalarProduct() {
    int a[] = {5, 22, 1,
               55, 3, 6,
               4, 21, 2};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    assert(getSpecialScalarProduct(m1) == 85);

    freeMemMatrix(m1);
}

void test_task18() {
    test_getScalarProductRowAndCol();
    test_getSpecialScalarProduct();
}

void test_tasks_Matrix() {
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12();
    test_task13();
    test_task14();
    test_task15();
    test_task16();
    test_task17();
    test_task18();
}

int main() {
    testVector();
    testMatrix();
    test_tasks_Matrix();
    testString_();
    test_tasks_String_();

    return 0;
}