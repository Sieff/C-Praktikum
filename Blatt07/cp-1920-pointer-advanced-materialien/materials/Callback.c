#include <assert.h>
#include <stdlib.h>
#include<stdio.h>

double foo(double x, double y) {
	return x*x + y;
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
	const size_t height = 2, width = 3;
	double data[height][width];
	const double x_min = -1, x_max = 1;
	const double y_min = 1, y_max = 3;

	fillMatrixWithResults(height, y_min, y_max,
	                      width, x_min, x_max,
	                      data, &foo);

	//may be used, is not required for grading
	//print2dArray(height, width, data);

	/* assert(data[0][0] == 2);
	assert(data[0][1] == 1);
	assert(data[0][2] == 2);
	assert(data[1][0] == 4);
	assert(data[1][1] == 3);
	assert(data[1][2] == 4); */
	print2dArray(height, width, data);
}
