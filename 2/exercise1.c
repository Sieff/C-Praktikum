#include <stdio.h>

//toplevel struct mit einer union
struct foobar
{
	enum	{
		INT,
		FLOAT
	} type ;
	
	//union aus zwei structs zur Speichersparung
	union barfoo
	{
		struct foo
		{
			int a;
			int b;
		}foo;
		
		struct bar
		{
			float a;
			float b;
		}bar;
	}barfoo;
}foobar;


int main (void)
{
	struct foo a = { 42, 23 };
	printf("foo: %d %d\n", a.a, a.b);
	struct bar b = { 23.0, 42.0 };
	printf("bar: %f %f\n", b.a, b.b);
	printf("sizeof(foobar): %ld\n", sizeof(foobar));
	return 0;
}
