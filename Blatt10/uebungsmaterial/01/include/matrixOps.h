#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int **data;
	int dim;
} matrix;

matrix newMatrix(int matrixDim);

matrix addMatrices(matrix m1, matrix m2, int matrixDim);

int berechneZelle(int * zeile, matrix m2, int spaltenIndex, int matrixDim);

void print2dArray(size_t matrixDim, int **data);

void printCalculation(matrix m1, matrix m2, matrix ergebnis, char* operator);



matrix mulMatrices(matrix m1, matrix m2, int matrixDim);

void freeMatrix(matrix m);