#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols){
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for(size_t i = 0; i < nCols; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix){values, nRows, nCols};
}

void freeMemMatrix(matrix m){
    for(size_t i = 0; i < m.nCols; i++)
        free(m.values[i]);
    m.nRows = 0;
    m.nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for(size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}
