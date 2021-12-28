#include<stdio.h>
void main()
{
	int i;//define an integer for the loop
	for (i = 1;i < 101;i++)//a loop to print the numbers from 1 to 100
	{
		if (i%7==0 || i%10==7 ||i/10==7)// conditioning to check if the number is a distribution of 7 or include 7
		{
			printf("BOOM ");
		}
		else// if the number is not divine of 7 or inculde him,the program will print the number as is 
			printf("%d ", i);
	}
}
