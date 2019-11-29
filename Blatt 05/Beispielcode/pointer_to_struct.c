#include <stdio.h>
#include <stdlib.h>

struct Point {
	double x;
	double y;
};

int main(int argc, char** argv) {
	struct Point p = {1.0, 2.5};
	struct Point * pp = &p;
	pp->x = 10;
	(*pp).y = 15;
	printf("(%f, %f) = (%f, %f)\n", p.x, p.y, (*pp).x, pp->y);
}
