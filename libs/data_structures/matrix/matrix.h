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

matrix getMemMatrix(int nRows, int nCols);

#endif
