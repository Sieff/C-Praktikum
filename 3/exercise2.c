#include <stdio.h>
#include <stdlib.h>

int * extendByOne(int array[], int arraySize)
{	
	int *ret = (int *) malloc(sizeof(int *) * (arraySize + 1));
	printf("%d\n", array[0]);
	ret = array;
	printf("%d\n", ret[0]);
	ret[arraySize] = 0;
	return ret;
}

int main()
{
	int array[10];
	array[0] = 5;
	int *newArray = extendByOne(array, sizeof(array) / sizeof(array[0]));
	free(newArray);
	return 0;
}
