#include "include/matrixOps.h"

int main()
{

	const int matrixDim = 3;

	// Matrix Initialisierung
	matrix mA = newMatrix(matrixDim);
	matrix mB = newMatrix(matrixDim);

	// Addition
	matrix mc1 = addMatrices(mA, mB, matrixDim);
	printCalculation(mA, mB, mc1, "+");

	// Multiplikation
	matrix mc2 = mulMatrices(mA, mB, matrixDim);
	printCalculation(mA, mB, mc2, "*");

	// Gib Matrix-Speicher wieder frei
	freeMatrix(mA);
	freeMatrix(mB);
	freeMatrix(mc1);
	freeMatrix(mc2);
}
