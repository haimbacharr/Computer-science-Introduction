#include <stdio.h>
#include<conio.h>
void inputpoint(float* a, float* y);
void inputsug(float* a, float* b, float* c, float* d);
void setmidseq(float x1, float y1, float x2, float y2, float* a, float* b);
void main()
{
	float x1, x2, y1, y2, xm, ym;
	printf("Enter a line segment in the plane,please.enter a point in the plane,please(x and y coord,respectively):");//the user will enter 4 numbers to calculate the mid line.
	inputsug(&x1, &y1, &x2, &y2);//fucnction call
	setmidseq(x1, y1, x2, y2, &xm, &ym);//fucnction call
	printf("The Midpoint of a the line segment is:(%f %f)", xm, ym);//will printf the mid line x and y.
	getch();
}


void inputpoint(float* a, float* b)//the function will recived 2 value of a and b (it is address for  x and y)
{
	scanf("%f %f", a, b);

}
void inputsug(float* a, float* b, float* c, float* d)//the function will recived the adresses for 2 point of x and y.
{
	inputpoint(a, b);
	inputpoint(c, d);
}
void setmidseq(float x1, float y1, float x2, float y2, float* a, float* b)//the function will calculate the mid line points (x and y) of 2 points (x and y)
{
	*a = (x1 + x2) / 2;
	*b = (y1 + y2) / 2;

}
