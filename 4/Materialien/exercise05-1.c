#include<math.h>
#include<stdio.h>

struct point_t {
	double x;
	double y;
};

double distance (struct point_t *p1, struct point_t *p2) {
	double d1 = p1->x - p2->x;
	double d2 = p1->y - p2->y;
	d1 = pow(d1, 2);
	d2 = pow(d2, 2);
	
	double distanz = sqrt(d1+d2);
	return distanz;
}

int main (int argc, char ** argv) {
	struct point_t p = {5, 2};
	struct point_t q = {4, 3};
	struct point_t * pp = &p;
	struct point_t * pq = &q;
	printf("%f\n", distance(pp, pq));
	return 0;
}
