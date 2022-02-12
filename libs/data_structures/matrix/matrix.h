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

/// вводит матрицу m
void inputMatrix(matrix m);

/// вводит массив матриц s размера nMatrices
void inputMatrices(matrix *ms, int nMatrices);

/// выводит матрицу m
void outputMatrix(matrix m);

/// выводит массив матриц s размера nMatrices
void outputMatrices(matrix *ms, int nMatrices);

/// обменивает строки с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

/// обменивает столбцы с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

#endif
