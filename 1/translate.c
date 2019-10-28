#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */


int main(int argc, char *argv[])
{
	int val = (argc > 1) ? atoi(argv[1]) : 0;
	// Erweitere fuer die Zahlen 0-9
	if (val == 0)
	{
		printf("null");
	}
	else if (val == 1)
	{
		printf("eins");
	}
}
