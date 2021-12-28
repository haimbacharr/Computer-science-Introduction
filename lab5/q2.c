#include<stdio.h>
#include<math.h>
void main()
{
	int i, j, a, b;//i,j for the 2 loops,a and b for the dimensions sizes.
	printf("insert dimensions:");
	scanf("%d%d", &a, &b);
	if (a < 0 || b < 0)//check if the submitted numbers are postive.
	{
		printf("wrong dimensions");
	}
	else
	{
		for (i = 1;i <= a;i++)// a loop that raws.
		{
			for (j = 1;j <= b;j++)// a loop for Columns
			{
				printf("%4d", i*j);//caculate the product between the raws and cloumns
			}
			printf("\n");
		}
	}
}
