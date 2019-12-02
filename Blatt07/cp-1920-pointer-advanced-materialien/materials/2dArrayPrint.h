#include <stdio.h>

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