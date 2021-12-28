#include<stdio.h>
#include<conio.h>
#define N 100
void main()
{
	int a[N];//a for the array.
	int i, j, n, max, flag = 1, location = 1;//i and j for the loop,n for number of integers,max for maximun value in the array,flag for while,location for index of the max value.
	while (flag)//while flag 1 run the loop
	{
		printf("Please enter number of integers:");
		scanf("%d", &n);
		if (n == 0)//if number of integers is 0,flag will be 0 and exit the loop.
			flag = 0;
		else
		{
			int *a = malloc(n * sizeof(int));//memory alloacation under a define of n and the array.
			if (a == NULL)//check if the alloaction memory succed
			{
				printf("the allocation memory faild !");
			}
			else
			{
				printf("enter %d integers:", n);
				for (i = 0;i < n;i++)
				{
					scanf("%d", &a[i]);//recived integers to the array.
				}
				max = a[0];//max is the first number of the array.
				for (i = 0;i < n;i++)
				{
					if (a[i] > max)//if arr[i] is bigger then max,max will get his value and location the index.
					{
						max = a[i];
						location = i + 1;
					}
				}
				printf("the maximum number is at place:%d\n", location);
				free(a);//free the allocation memory for the array.
			}
		}
	}
	printf("Bye Bye...");
	getch();
}
