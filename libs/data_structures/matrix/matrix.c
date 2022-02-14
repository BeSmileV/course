#include "matrix.h"
#include "../../algorithms/array/array.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
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
    for (size_t i = 0; i < m.nRows; i++)
        a[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[i]) {
            swapRows(m, j, j - 1);
            j--;
        }
        swapRows(m, i, j);
    }
    free(a);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *buffer = (int *) malloc(sizeof(int) * m.nRows);
    int *a = (int *) malloc(sizeof(int) * m.nCols);
    for (size_t i = 0; i < m.nCols; i++) {
        for (size_t j = 0; j < m.nRows; j++)
            buffer[j] = m.values[j][i];
        a[i] = criteria(buffer, m.nRows);
    }
    free(buffer);
    for (int i = 1; i < m.nCols; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[i]) {
            swapColumns(m, j, j - 1);
            j--;
        }
        swapColumns(m, i, j);
    }
    free(a);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nCols != m2.nCols || m1.nRows != m2.nRows)
        return false;
    for (size_t i = 0; i < m1.nRows; i++) {
        for (size_t j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    }
    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (i == j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0)
                return false;
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = i + 1; j < m.nCols; j++) {
            int t = m.values[i][j];
            m.values[i][j] = m.values[j][i];
            m.values[j][i] = t;
        }
    }
}

position getMinValuePos(matrix m) {
    position min = {0, 0};
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }
    }
    return min;
}

position getMaxValuePos(matrix m) {
    position max = {0, 0};
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[max.rowIndex][max.colIndex]) {
                max.rowIndex = i;
                max.colIndex = j;
            }
    }
    return max;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}