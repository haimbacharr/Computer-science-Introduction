#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double num; //The floating number
	int i = 0;//Used as a degree for calculating the sum of the left number.
	int sum = 0;//Calculating the sum of the left number.
	int left_num;//Left number from the period.
	float right_num;//Right number from the period.
	printf("Enter floating number: ");
	scanf_s("%lf", &num);
	printf("%.05lf (10) = ", num);
	left_num = (int)num; //Placment the integer num value into left_num variable.
	right_num = num - left_num;//Calculating the right number after the period.

	while (left_num > 0) //Loop that helps to Calculate the value from the left side of the period.
	{
		if (left_num % 2 == 1)
		{
			sum = sum + (int)(pow(10, i));//Calculating the left number.
		}
		i++;
		left_num = left_num / 2;
	}
	printf("%d.", sum);//Printing the left side of the period of the floating number.
	
	i = 0;//Reset  i variable.
	while(i<8)//Loop that calculate the right side of the period of the floating number.
	{
		right_num = right_num * 2;
		printf("%d", (int)right_num);
		if ((int)right_num == 1)
			right_num = right_num - 1;
		i++;
	}
	printf(" (2)\n");
	_getch();
	return 0;
}