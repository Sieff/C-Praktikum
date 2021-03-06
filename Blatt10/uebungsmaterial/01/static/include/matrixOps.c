#include <stdlib.h>
#include <stdio.h>

//Matrix Datenstruktur
typedef struct
{
	int **data;
	int dim;
} matrix;

//Erzeugt eine Neue Matrix, gibt Matrix zurück
//Matrix gefüllt mit Zufallszahlen von 1-10
//Matrix ist quadratisch, Dimension ist wie wählbar
//Die Daten sind auf dem Heap, das Struct im Stack
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

//Addiert zwei quadratische Matrizen
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

//berechnet eine Zelle für die Multiplikation zweier Matrizen
int berechneZelle(int * zeile, matrix m2, int spaltenIndex, int matrixDim)
{
	int sum = 0;
	for(int i = 0; i < matrixDim; i++)
	{
		sum += zeile[i] * m2.data[i][spaltenIndex];
	}
	return sum;
}

//gibt eine Matrix auf der Konsole aus
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

//gibt eine Rechenanweisung und das Ergebnis auf der Konsole aus
void printCalculation(matrix m1, matrix m2, matrix ergebnis, char* operator)
{
	print2dArray(m1.dim, m1.data);
	printf("%s\n", operator);
	print2dArray(m2.dim, m2.data);
	printf("=\n");
	print2dArray(ergebnis.dim, ergebnis.data);
	printf("\n");
}


//Multipliziert zwei Matrizen
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

//Gibt den Speicherplatz für eine Matrix frei
void freeMatrix(matrix m)
{
	for(int i = 0; i < m.dim; i++)
	{
		free(m.data[i]);
	}
	free(m.data);
}