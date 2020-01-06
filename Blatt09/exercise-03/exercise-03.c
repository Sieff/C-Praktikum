#include<stdio.h>

double compute(double d,unsigned n)
{
	double x = 1.0;
	unsigned j;
	for(j = 1; j <= n; j++) 
	{
 		x *= d;
	}

	return x;
}

int main (void)
{
	double result = 0.0;
	unsigned i;

	for(i = 1; i < 999999999; i++) 
	{
		result += compute(i, i % 7);
	}

	printf ("result = %g\n", result);
	return 0;
}