#include<stdio.h>
#include<math.h>	
void main()
{
	int num, u, t, h, T;
	printf("Please enter a 4 postive digits number:");
	scanf("%d", &num);
	u = (num % 10);//separte the units
	t = ((num / 10) % 10);//separte the tens
	h = ((num / 100) % 10);//separte the hunderds
	T = (num / 1000);//separte the thousends
	if (num < 0)//check if the number is negative
	{
	printf("%d is a negative number,bye bye\n", num);
	}
	else
		if (num <= 999 || num >= 10000)//check if the number is 4 digits
		{
			printf("%d is not a 4 digit number,bye bye\n", num);
		}
	else 
	if (T == h && h == t && t == u)//check if the digits are equal
	{
		printf("all 4 digits are the same.");
	}
	else
	{
if (T - h == h - t && h - t == t - u && T - h >= 1)//check if the number is a dicreasing arithmetic sequence
printf("dicreasing arithmetic sequence<from left to right>\n");
else if (T - h == h - t && h - t == t - u && T - h < 1)//check if the number is a Increasing arithmetic sequence
printf("Increasing arithmetic sequence<from left to right>\n");
else if (T - h >= 0 && h - t >= 0 && t - u >= 0)//check if the number is a descending sequence 
printf("descending sequence<from left to right>\n");
else if (T - h <= 0 && h - t <= 0 && t - u <= 0)//check if the number is a Increasing sequence
printf("Increasing sequence<from left to right>\n");
else 
 printf("no dicreasing and no increasing\n");// check if the number is no dicreasing and no increasing
	}
}	
