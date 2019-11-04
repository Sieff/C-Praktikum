#include <stdio.h>

struct foo
{
	int a;
	int b;
};

struct bar
{
	float a;
	float b;
};

int main (void)
{
	struct foo a = { 42, 23 };
	printf("foo: %d %d\n", a.a, a.b);
	struct bar b = { 23.0, 42.0 };
	printf("bar: %f %f\n", b.a, b.b);
	return 0;
}
