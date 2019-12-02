#include <assert.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>

double foo(double x, double y) {
	return x*x + y;
}

double f(double x, double y){
	return x*y;
}

double g(double x, double y){
	return sin(x) * sin(y);
}

double h(double x, double y){
	return x < y ? y : x;
}

//Fills a 2D matrix with the results of the given callback function.
//The coordinates that are passed to the callback
//range from (y_min, x_min) to (y_max, x_max), inclusive.
//
//I.e. the call
//
//    fillMatrixWithResults(3, 0.0, 1.0,
//                          4, -1.0, 5.0,
//                          matrix, &callback)
//
//will call the callback with the coordinates
//
//    (0.0, -1.0) (0.0, 1.0) (0.0, 3.0) (0.0, 5.0)
//    (0.5, -1.0) (0.5, 1.0) (0.5, 3.0) (0.5, 5.0)
//    (1.0, -1.0) (1.0, 1.0) (1.0, 3.0) (1.0, 5.0)
void fillMatrixWithResults(int height, double y_min, double y_max,
                           int width, double x_min, double x_max,
                           double data[height][width], double(*foo)(double, double)) {
	double y_range = y_max - y_min;
	double x_range = x_max - x_min;
	double y_step = y_range / (height - 1);
	double x_step = x_range / (width - 1);

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			data[y][x] = (*foo)(y_min + y * y_step, x_min + x * x_step);
		}
	}
}
/*
	fillMatrixWithResults(2, 1, 3,
	                      3, -1, 1,
	                      data, &foo);	

	(1, -1)(1, 0)(1, 1)
	(3, -1)(3, 0)(3, 1)
*/

void print2dArray(size_t height, size_t width, double data[height][width]) {
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			printf("%f ", data[y][x]);
		}
		printf("\n");
	}
}

int main() {
	//Aufruf für Funktion f
	size_t height = 5, width = 5;
	double data[height][width];
	double x_min = -1, x_max = 1;
	double y_min = -1, y_max = 1;

	fillMatrixWithResults(height, y_min, y_max,
	                      width, x_min, x_max,
	                      data, &f);
	print2dArray(height, width, data);
	printf("\n");

	//Aufruf für Funktion g
	x_min = 0, y_min = 0, x_max = M_PI, y_max = M_PI;

	fillMatrixWithResults(height, y_min, y_max,
	                      width, x_min, x_max,
	                      data, &g);
	print2dArray(height, width, data);
	printf("\n");

	//Aufruf für Funktion h
	height = 11, width = 11;
	x_min = 0, y_min = 0, x_max = 10, y_max = 10;
	double dataH[height][width];
	fillMatrixWithResults(height, y_min, y_max,
	                      width, x_min, x_max,
	                      dataH, &h);
	print2dArray(height, width, dataH);


}
