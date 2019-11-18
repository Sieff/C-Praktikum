#include <stdio.h>
#include <stdlib.h>

void change(int* pi) {  //explicit pointer
	*pi = 5;  //explicitly dereferenced
}

int main(int argc, char** argv) {
	int a = 4;
	printf("before: a = %d\n", a);
	change(&a); //explicit taking of address
	printf("after : a = %d\n", a);
	return 0;
}
