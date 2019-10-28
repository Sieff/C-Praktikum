#include <stdio.h>

void fibWhile()
{
	int a = 0, b= 1, i = 0;
	int tmp;
	while(i <= 21)
	{
		
		printf("%d ", a);
		tmp = b;
		b = a+b;
		a = tmp;	
		i++;
	}
}

void fibDoWhile()
{
	int a = 0, b= 1, i = 0;
	int tmp;
	do
	{
		printf("%d ", a);
		tmp = b;
		b = a+b;
		a = tmp;			
		i++;
	} while(i <= 21);
}

void fibFor()
{
	int a = 0, b= 1, i = 0;
	int tmp;
	for(int i = 0; i<= 21; i++)
	{
		printf("%d ", a);
		tmp = b;
		b = a+b;
		a = tmp;			
	}
}

int main()
{
	fibWhile();
	printf("\n");
	fibDoWhile();
	printf("\n");
	fibFor();
	printf("\n");
	return 0;	
}
