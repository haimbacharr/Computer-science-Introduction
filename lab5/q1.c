#include<stdio.h>
#include<math.h>

void main()
{
	int x,count=0,i;//x for number,i for loop,count for counting the divisors.
	printf("Enter an Integer number,please:");
	scanf("%d", &x);
	if (x == 0)//check if the number that submitted is 0.
	{
		printf("infinity.");
	}
	else if (x < 0)//check if the number is negative
	{
		x = x * (-1);//change the number to postive.
		for (i = 1;i <=x;i++)//a loop that runs until x.
		{
			if (x%i == 0)//check which numbers diverse until the x.
			{
				count++;//count the divisors.
				printf("%d ", i);
			}
		}
		printf("\ncount=%d", count);
	}
	else if (x > 0)
	{
		for (i = 1;i < x;i++)//a loop that runs until x.
		{
			if (x%i == 0)//check which numbers diverse until the x.
			{
				count++;//count the divisors.
				printf("%d ", i);
			}
		}
		printf("\ncount=%d", count);
	}
}
