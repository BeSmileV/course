#include "matrix.h"
#include "../../algorithms/array/array.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nCols; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nCols; i++)
        free(m.values[i]);
    m.nRows = 0;
    m.nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        inputArray_(m.values[i], m.nCols);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        outputArray_(m.values[i], m.nCols);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (size_t i = 0; i < m.nCols; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for(size_t i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    for(int i = 1; i < m.nRows; i++){
        int j = i;
        while(j > 0 && a[j - 1] > a[i]){
            swapRows(m, j, j - 1);
            j--;
        }
        swapRows(m, i, j);
    }
    free(a);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)){
    int *buffer = (int *) malloc(sizeof(int) * m.nRows);
    int *a = (int *) malloc(sizeof(int) * m.nCols);
    for(size_t i = 0; i < m.nCols; i++) {
        for(size_t j = 0; j < m.nRows; j++)
            buffer[j] = m.values[j][i];
        a[i] = criteria(buffer, m.nRows);
    }
    free(buffer);
    for(int i = 1; i < m.nCols; i++){
        int j = i;
        while(j > 0 && a[j - 1] > a[i]){
            swapRows(m, j, j - 1);
            j--;
        }
        swapColumns(m, i, j);
    }
    free(a);
}