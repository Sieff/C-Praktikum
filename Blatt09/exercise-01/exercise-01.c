#include<stdio.h>
#include<math.h>
#define SQUARE(x) (x*x)

int main (void)
{
	int i = 2;
	int j = 9;
	printf("%d, %f\n", SQUARE(i), sqrt(j));
	return 0;
}