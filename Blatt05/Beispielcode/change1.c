#include <stdio.h>
#include <stdlib.h>

void no_change(int i) {
	i = 5;
}

int main(int argc, char** argv) {
	int a = 4;
	printf("before: a = %d\n", a);
	no_change(a);
	printf("after : a = %d\n", a);
	return 0;
}
