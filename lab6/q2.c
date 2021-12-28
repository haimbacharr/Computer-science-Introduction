#include <stdio.h>//for standart input/output
#include <math.h>//for math functions
#define G 9.81//define G as a gravitational pull 9.81 m/s^2
float deg2rad(float);//function declaration of returned type float
float horizontal(float, float, float);//function declaration returned of type float
float height(float, float, float);//function declaration of returned type float
int main()
{
	float v, t = 0;//declare on 2 float variables for velocity and time,time = 0
	int a;//declare on an integer variable for an angle
	while (1)//loop with condition of (TRUE)
	{
		printf("Enter velocity (0.0-100.0) m/s and angle (0-90 degrees): ");//user instructions
		scanf_s("%f", &v);//input - 1 float value to variable v
		if (v < 0 || v>100)//condition1 - if v value is not within permitted range
		{
			printf("Finish");//output - Finish message
			return 0;//return value 0 /end main
		}
		scanf_s("%d", &a);//input - 1 integer value to variable a
		if (a < 0 || a>90)//condition2 - if a value is not within permitted range
		{
			printf("Finish");//output - Finish message
			return 0;//return value 0 /end main
		}
		do//loop do-while,do before the condition check
		{
			t = t+ 0.1;//t takes value of t+0.1
			printf("Time: %.1f....S=%.2f  H=%.2f\n", t, horizontal(a, t, v), height(v, a, t));//prints result via functions call of horizontal and height
			if (height(v, a, t) <= 0)//condition if height value is 0 or less
				printf("\nFallen!\n");//print Fallen
		} while (height(v, a, t) > 0);//condition for loop,while height is a positive number
		t = 0;//t takes value of 0
	}
}
float deg2rad(float a)/*Function definition: Name:deg2rad~~Input:value of a(angle,integer)
~~Output:value of an converted a(float)~~Algorithm:recieves a value of an angle(a-integer),converts it to radians,then returns the value of an angle in radians a(float)*/
{
	a = ((a*3.14159) / 180);//(a) takes value of a convertion of (a) into radians
	return a;//returns value of an (a) float
}
float horizontal(float a, float t, float v)/*Function definition: Name:horizontal~~Input:value of a(angle,float),value of t(time,float),value of v(velocity,float)
~~Output: value of an s(float)~~Algorithm:recieves a value of an angle in radians(a-float),
a value of time (t-float),a value of velocity(v-float),declare on 1 float variable s(float),s takes value of a calculation of v and cos(call for function deg2rad(value of a)),
returns value of s(float)*/
{
	float s;//declare on 1 float variable
	s = v * cos(deg2rad(a))*t;//s takes value of v*cosinus(call for function deg2rad(value of a))
	return s;//return value s(float)
}
float height(float v, float a, float t)/*Function definition: Name:height~~Input:value of v(velocity,float),value of a(angle,float),value of t(time,float)
~~Output: value of an h(float)~~Algorithm:recieves a value of velocity(v-float),a value of an angle in radians(a-float),
a value of time (t-float),declare on 1 float variable h(float),h takes value of a calculation of via formula:v*sin(deg2rad(a))*t - G*t^2 / 2,
returns value of h(float)*/
{
	float h;//declare on 1 float variable h
	h = v * sin(deg2rad(a))*t - G * pow(t, 2) / 2;//h takes value of calculation of height via formula of physics
	return h;//return value of h(float)
}
