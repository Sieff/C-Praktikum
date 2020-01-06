#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int **data;
	int dim;
} matrix;

matrix newMatrix(int matrixDim)
{
	int ** ptr = malloc(sizeof(int) * matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		ptr[i] = malloc(sizeof(int) * matrixDim);
	}

	for(int x = 0; x < matrixDim; x++)
	{
		for(int y = 0; y < matrixDim; y++)
		{
			ptr[x][y] = rand() %10 +1;
		}
	}

	matrix m;
	m.data = ptr;
	m.dim = matrixDim;
	return m;
}

matrix addMatrices(matrix m1, matrix m2, int matrixDim)
{
	int ** ptr = (int**) malloc(sizeof(int) * matrixDim * matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		ptr[i] = malloc(sizeof(int) * matrixDim);
	}

	for(int x = 0; x < matrixDim; x++)
	{
		for(int y = 0; y < matrixDim; y++)
		{
			ptr[x][y] = m1.data[x][y] + m2.data[x][y];
		}
	}

	matrix m;
	m.data = ptr;
	m.dim = matrixDim;
	return m;
}

int berechneZelle(int * zeile, matrix m2, int spaltenIndex, int matrixDim)
{
	int sum = 0;
	for(int i = 0; i < matrixDim; i++)
	{
		sum += zeile[i] * m2.data[i][spaltenIndex];
	}
	return sum;
}

void print2dArray(size_t matrixDim, int **data) {
	for(int x = 0; x < matrixDim; x++)
	{
		for(int y = 0; y < matrixDim; y++)
		{
			printf("%d ", data[x][y]);
		}
		printf("\n");
	}
}

void printCalculation(matrix m1, matrix m2, matrix ergebnis, char* operator)
{
	print2dArray(m1.dim, m1.data);
	printf("%s\n", operator);
	print2dArray(m2.dim, m2.data);
	printf("=\n");
	print2dArray(ergebnis.dim, ergebnis.data);
	printf("\n");
}



matrix mulMatrices(matrix m1, matrix m2, int matrixDim)
{
	int ** ptr = (int**) malloc(sizeof(int) * matrixDim * matrixDim);

	for(int i = 0; i < matrixDim; i++)
	{
		ptr[i] = malloc(sizeof(int) * matrixDim);
	}

	for(int x = 0; x < matrixDim; x++)
	{
		for(int y = 0; y < matrixDim; y++)
		{
			ptr[x][y] = berechneZelle(m1.data[x], m2, y, matrixDim);
		}
	}

	matrix  m;
	m.data = ptr;
	m.dim = matrixDim;
	return m;
}

void freeMatrix(matrix m)
{
	for(int i = 0; i < m.dim; i++)
	{
		free(m.data[i]);
	}
	free(m.data);
}