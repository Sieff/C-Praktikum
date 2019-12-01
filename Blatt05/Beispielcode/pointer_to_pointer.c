#include <stdio.h>

int main() {
	int i = 5;
	int * pi = &i;
	int ** ppi = &pi;

	printf("%d\n",  i);
	printf("%d\n",  * pi);
	printf("%d\n",  ** ppi);
}
