#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/array/array.h"

#define ERROR_RATE 10e-7

void outputArray_LL(const long long *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%lld ", a[i]);
    printf("\n");
}


///// возвращает наибольший элемент массива a
int getMax(int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];

    return max;
}

/// упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/// возвращает наименьший элемент массива a
int getMin(int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];

    return min;
}

/// упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m){
    insertionSortColsMatrixByColCriteria(m, getMin);
}

int getMulOfRowAndCol_(matrix m1, matrix m2, int indexRow, int indexCol, int n){
    int mul = 0;
    for(size_t i = 0; i < n; i++)
        mul += m1.values[indexRow][i] * m2.values[i][indexCol];

    return mul;
}



//int main() {
//    int nRows, nCols;
//    scanf("%d %d", &nRows, &nCols);
//
//    matrix m = getMemMatrix(nRows, nCols);
//    inputMatrix(m);
//
//    if(isSymmetricMatrix(m) && isSquareMatrix(m)){
//        m = mulMatrices(m, m);
//    }
//
//    outputMatrix(m);
//
//    return 0;
//}

/// возвращает суммы массива a размера n
long long getSum(int *a, int n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

bool isUnique(long long *a, int n) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols) {
    long long *a = (long long *) malloc(sizeof(long long) * nRows);
    for (size_t i = 0; i < nRows; i++)
        a[i] = getSum(m.values[i], nCols);
    if (isUnique(a, nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mul = mulMatrices(m1, m2);
    bool isE = isEMatrix(mul);
    freeMemMatrix(mul);
    return isE;
}

int max(int a, int b) {
    return a > b ? a : b;
}

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

int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int range = 1;
    int indexRow = max.rowIndex;
    int indexCol = max.colIndex;
    int min = m.values[max.rowIndex][max.colIndex];
    while (indexRow > 0 || indexCol > 0) {
        if (indexCol > 0)
            indexCol--;
        if (indexRow > 0)
            indexRow--;
        if (range <= m.nCols - 2)
            range += 2;
        for (size_t i = 0; i < range; i++)
            if (min > m.values[indexRow][i + indexCol])
                min = m.values[indexRow][i + indexCol];
    }

    return min;
}

float getDistance(int *a, int n) {
    float sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += (float) a[i];

    return sqrtf(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *a = (float *) malloc(sizeof(float) * m.nRows);
    for (size_t i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        float t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] - t > ERROR_RATE) {
            a[j] = a[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        a[j] = t;
    }
    free(a);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long *a = (long long *) pa;
    long long *b = (long long *) pb;
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

int countNUnique(long long *a, int n) {
    int count = 0;
    for (size_t i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            count++;

    return count + 1;
}

int countEqClassesByRowsSum(matrix m) {
    int n = m.nRows;
    long long *a = (long long *) malloc(sizeof(long long) * n);
    for (size_t i = 0; i < n; i++)
        a[i] = getSum(m.values[i], m.nCols);

    qsort(a, n, sizeof(long long), cmp_long_long);

    free(a);

    return countNUnique(a, n);
}

void getSumOfColsElements(matrix m, long long *a) {
    for (size_t j = 0; j < m.nCols; j++)
        for (size_t i = 0; i < m.nRows; i++)
            a[j] += m.values[i][j];
}

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

void swapPenultimateRow(matrix m) {
    position min = getLeftMin(m);
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t i = 0; i < m.nRows; i++)
        a[i] = m.values[i][min.colIndex];
    for (size_t i = 0; i < m.nRows; i++)
        m.values[m.nRows - 2][i] = a[i];

    free(a);
}

bool isNonDescendingSorted(int *a, int n){
    for(size_t i = 1; i < n; i++)
        if(a[i] < a[i - 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m){
    for(int i = 0; i < m.nRows; i++)
        if(!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){
    int count = 0;
    for(size_t i = 0; i < nMatrix; i++)
        count += hasAllNonDescendingRows(ms[i]);

    return count;
}

int getMaxAbs(matrix m){
    int max = abs(m.values[0][0]);
    for(size_t i = 0; i < m.nRows; i++)
        for(size_t j = 0; j < m.nCols; j++) {
            int a = abs(m.values[i][j]);
            if (max < a)
                max = a;
        }

    return max;
}

void printMatrixWithMinAbsOfElement(matrix *ms, int n){
    int *a = (int *) malloc(sizeof(int) * n);
    for(size_t i = 0; i < n; i++)
        a[i] = getMaxAbs(ms[i]);

    int min = a[0];
    for(size_t i = 1; i < n; i++)
        if(min > a[i])
            min = a[i];

    for(size_t i = 0; i < n; i++)
        if(a[i] == min)
            outputMatrix(ms[i]);

    free(a);
}

int main() {
    int n, nRows, nCols;
    scanf("%d %d %d", &n, &nRows, &nCols);

    matrix *ms = getMemArrayOfMatrices(n, nRows, nCols);
    inputMatrices(ms, n);

    printMatrixWithMinAbsOfElement(ms, n);

    return 0;
}