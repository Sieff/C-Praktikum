#include <stdio.h>
#include <stdlib.h>

int* extendByOne(int array[], int arraySize)
{	
	int *ret;
	ret = malloc(sizeof(int) * (arraySize + 1));
	if (ret == NULL)
	{
		printf("can not allocate memory.");
		exit(0);
	}
	//ret = array; //CAUSES ERROR, functionality removed
	for (int i = 0; i < arraySize; i++)
	{
		*(ret + i) = array[i];
		//printf("%d\n", *(ret+i));
	}
	ret[arraySize] = 0;
	return ret;
}

int main(void)
{
	int array[5] = {0,1,2,3,4};
	int *newArray = extendByOne(array, sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < (sizeof(array) / sizeof(array[0]))+ 1; i++)
	{
		printf("%d\n", newArray[i]);
	}
	free(newArray);
	return 0;
}
