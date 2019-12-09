#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double convertTemperature(double* fahrenheit) {
	return (*fahrenheit - 32)/1.8;
}


int main() {
	void* buffer = (void*)malloc(33);
	printf("%f\n", convertTemperature(buffer));
}
