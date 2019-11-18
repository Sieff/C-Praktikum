#include <assert.h>

int divide(int a, int b, int * rest) {
	*rest = a%b;
	return a/b;
}

int main() {
	int b = 53;
	int a = 7*b + 42;
	int rest = 0;
	int c = divide(a, b, &rest);
	assert(c == 7);
	assert(rest == 42);
}
