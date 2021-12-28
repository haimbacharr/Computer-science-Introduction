#include<stdio.h>
void main()
{
	int A, B, C, sum=0,Final,i;//A = final grade integer,B = homeworks integer, C = grades of homeworks integer,sum = couting the grades,final = calculation for final grade,i = counter for loop
	printf("Please give me your final test grade:");
	scanf("%d", &A);
	printf("\nHow much homework did you sumbit(0-6)?");
	scanf("%d", &B);
	switch (B)//for checking how many homeworks submitted
	{
	case 0:case 1: case 2: case 3: case 4:
		printf("\nYour score is 0");
		break;
	case 5:
		printf("\nEnter your grades:");
		for (i = 0;i < 5;i++)// a loop that gets the grades and sum them up for 5 grades
		{
			scanf("%d", &C);
			sum = sum + C;
	     } 
		Final = ((sum / B)*0.2) + (A * 0.8);//calculation for final grade
		printf("The Final Grade is %.1lf", (double)Final);
		break;
	case 6:
		printf("\nEnter your grades:");
		for (i = 0;i < 6;i++)//a loop that gets the grades and sum them up for 5 grades
		{
			scanf("%d", &C);
			sum = sum + C;
		}
		Final = ((sum / B)*0.4) + (A * 0.6);//calculation for final grade
		printf("The Final Grade is %.1lf", (double)Final);
		break;
	default:printf("the amount of %d homeworks doesn't exist",B);

	}
	
}