#include <stdio.h>

void fib_while()
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
	printf("\n");
}

void fib_do_while()
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
	printf("\n");
}

void fib_for()
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
    fib_while();
    fib_do_while();
    fib_for();

    return 0;
}
