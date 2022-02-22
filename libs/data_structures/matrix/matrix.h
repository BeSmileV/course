#ifndef COURSE__MATRIX_H
#define COURSE__MATRIX_H

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct matrix {
    int **values;   // элементы матрицы
    int nRows;      // количество рядов
    int nCols;      // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

typedef struct matrixf {
    float **values;     // элементы матрицы
    int nRows;          // количество рядов
    int nCols;          // количество столбцов
} matrixf;

/// выделяет память под матрицу размера nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

/// размещает в динамической памяти массив из nMatrices матриц
/// размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

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

/// выполняет сортировку вставками строк матрицы m по неубыванию
/// значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

/// выполняет сортировку вставками столбцов матрицы m по неубыванию
/// значения функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

/// возвращает true, если матрица m является квадратной, иначе - false
bool isSquareMatrix(matrix m);

/// возвращает true, если матрицы m1 и m2 равны, иначе - false
bool twoMatricesEqual(matrix m1, matrix m2);

/// возвращает true, если матрица m является единичной, иначе - false
bool isEMatrix(matrix m);

/// возвращает зекгу, если матрица m является симметричной, иначе - false
bool isSymmetricMatrix(matrix m);

/// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

/// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

/// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

/// возвращает матрицу, равной произведению матриц m1 и m2
matrix mulMatrices(matrix m1, matrix m2);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols);

/// выделяет память под матрицу размера nRows на nCols
matrixf getMemMatrixF(int nRows, int nCols);

/// размещает в динамической памяти массив из nMatrices матриц
/// размером nRows на nCols
matrixf *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols);

/// освобождает память выделенную под матрицу m
void freeMemMatrixF(matrixf m);

/// освобождает память выделенную под массив матриц ms размера nMatrices
void freeMemMatricesF(matrixf *ms, int nMatrices);

/// вводит матрицу m
void inputMatrixF(matrixf m);

/// вводит массив матриц s размера nMatrices
void inputMatricesF(matrixf *ms, int nMatrices);

/// выводит матрицу m
void outputMatrixF(matrixf m);

/// выводит массив матриц s размера nMatrices
void outputMatricesF(matrixf *ms, int nMatrices);

matrixf createMatrixFromArrayF(const float *a, int nRows, int nCols);

matrixf *createArrayOfMatrixFromArrayF(const float *values, int nMatrices, int nRows, int nCols);

#endif
