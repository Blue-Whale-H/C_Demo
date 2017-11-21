#include <stdio.h>
#include <math.h>

struct point
{
	float x;		// x axis
	float y;		// y axis
	char test;
};

typedef struct point point_t;

float calculate(point_t p, point_t p2);

int main(void)
{
	point_t p;
	point_t p2 = {1.5, 2.5};
	float distance;
	//float dx, dy;

	printf("demo structure!\n");

	//p = p2;
	scanf("%f %f", &p.x, &p.y);

	printf("sizeof struct point = %lu\n", sizeof(point_t));
	printf("p.x = %.1f, p.y = %.2f\n", p.x, p.y);

	distance = calculate(p, p2);
	printf("distance = %f\n", distance);

#if 0
	printf("sizeof float = %lu\n", sizeof(float));
	printf("sizeof double = %lu\n", sizeof(double));
#endif

	return 0;
}

float calculate(point_t p, point_t p2)
{
	float dx, dy;

	dx = p.x - p2.x;
	dy = p.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}
