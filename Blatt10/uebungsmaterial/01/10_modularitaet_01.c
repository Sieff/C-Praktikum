#include "include/matrixOps.h"

int main()
{

	const int matrixDim = 3;

	// Matrix Initialisierung
	matrix mA = newMatrix(matrixDim);
	matrix mB = newMatrix(matrixDim);

	// Addition
	matrix mc1 = addMatrices(ma, mb, matrixDim);
	printCalculation(ma, mb, mc1, "+");

	// Multiplikation
	// // Addition
	matrix mc2 = mulMatrices(ma, mb, matrixDim);
	printCalculation(ma, mb, mc2, "*");

	// Gib Matrix-Speicher wieder frei
	freeMatrix(mA);
	freeMatrix(mB);
	freeMatrix(mc1);
	freeMatrix(mc2);
}
