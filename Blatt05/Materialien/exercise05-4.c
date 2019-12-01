#include <stdio.h>
#include <stdlib.h>


void summary (int *arr, size_t size, int *max, int *min, int *mean) {
	int sum = 0;
	*min = arr[0];
	for(int i = 0; i < size; i++){
		sum += arr[i];
		if(arr[i] < *min)
		{
			*min = arr[i];
		}
		if(arr[i] > *max)
		{
			*max = arr[i];
		}
	}
	*mean = sum/size;


}


int main (int argc, char ** argv) {
	
	int cars_speed[50] = {
		4  , 4  , 7  , 7  , 8  , 9  , 10 , 10 , 10 , 11   , 
		11 , 12 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 14   , 
		14 , 14 , 14 , 15 , 15 , 15 , 16 , 16 , 17 , 17   , 
		17 , 18 , 18 , 18 , 18 , 19 , 19 , 19 , 20 , 20   , 
		20 , 20 , 20 , 22 , 23 , 24 , 24 , 24 , 24 , 25
	};

	int car_dist[50] = {
		2  , 10 , 4  , 22 , 16 , 10 , 18 , 26 , 34  , 17   , 
		28 , 14 , 20 , 24 , 28 , 26 , 34 , 34 , 46  , 26   , 
		36 , 60 , 80 , 20 , 26 , 54 , 32 , 40 , 32  , 40   , 
		50 , 42 , 56 , 76 , 84 , 36 , 46 , 68 , 32  , 48   , 
		52 , 56 , 64 , 66 , 54 , 70 , 92 , 93 , 120 , 85
	};

	int* max = malloc(sizeof(int));
	int* min = malloc(sizeof(int));
	int* mean = malloc(sizeof(int));

	summary(cars_speed, (sizeof(cars_speed)/ sizeof(cars_speed[0])), max, min, mean);

	printf("%d\n", *min);
	printf("%d\n", *max);
	printf("%d\n", *mean);

	summary(car_dist, (sizeof(car_dist)/ sizeof(car_dist[0])), max, min, mean);

	printf("%d\n", *min);
	printf("%d\n", *max);
	printf("%d\n", *mean);

	free(max);
	free(min);
	free(mean);
	return 0;
}
