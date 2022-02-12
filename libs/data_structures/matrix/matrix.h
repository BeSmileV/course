#ifndef COURSE__MATRIX_H
#define COURSE__MATRIX_H

#include <malloc.h>

typedef struct matrix {
    int **values;   // элементы матрицы
    int nRows;      // количество рядов
    int nCols;      // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

/// выделяет память под матрицу размера nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

/// освобождает память выделенную под матрицу m
void freeMemMatrix(matrix m);

/// освобождает память выделенную под массив матриц ms размера nMatrices
void freeMemMatrices(matrix *ms, int nMatrices);

#endif
