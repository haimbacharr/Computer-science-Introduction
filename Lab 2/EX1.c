#include<stdio.h>
#include<conio.h>
#include <math.h>
struct point //setting point sturct
{
	float x;
	float y;
}typedef point;
struct circle //setting circle struct
{
	point center; //center is variable with point type
	float radius;
}typedef circle;
int check_circle(point *p, circle *cir);
void main()
{
	point p;
	circle cir;
	printf("Enter the coordinates of your point: ");
	scanf("%f %f", &p.x, &p.y);
	printf("Enter the radius and the center of your circle: ");
	scanf("%f %f %f", &cir.radius, &cir.center.x, &cir.center.y);
	if (check_circle(&p,&cir))//if check_circle returned 1 the point is inside the circle
	{
		printf("\nThe point is included in the circle");
	}
	else//if isinscircle returned 0 the point is not inside the circle
	{
		printf("\nThe point is not in the circle");
	}
	getch();
}
int check_circle(point *p, circle *cir)/*/using the circle formula (x-x0)+(y-y=)=r^2 to check if the point is inside /*/
{
	return (pow(cir->center.x - p->x, 2) + pow(cir->center.y - p->y, 2) <= pow(cir->radius, 2));
}


