#include<stdio.h>
#include<conio.h>
#define N 5
int sumofrow(int mat[5][5],int n,int x);
int diagonal(int mat[5][5],int n);
void main()
{
	int i,j,mat[5][5],res1,res2,row=0,count=0;
	printf("please enter 5x5 matrix element:\n");
	for (i = 0;i < 5;i++)//scan the matrix.
	{
		for (j = 0;j < 5;j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	printf("the matrix that you typed in is :\n");
	for (i = 0; i <5; i++)
	{
		for (j = 0; j <5; j++)
			printf("%3d", mat[i][j]);
		printf("\n");

	}
	while (row < 5)//while row is under 5(the size of row of the matrix),the function will check if the sum of the row ,that sent to the function, is equal to the number of row.
	{
		res1 = sumofrow(mat,N, row);//function call
		if (res1 == 1)
		{
			count++;
		}
		row++;
	}
	res2=diagonal(mat,N);//function call
	if (count>0 && res2 == 1)//if count is more than 0,the matrix have at least one row that the sum of it is equal to the number of the row and the diagonal numbers is positives it print ok.
	{
		printf("\nmatrix\n");
			for (i = 0;i < 5;i++)
			{
				for (j = 0;j < 5;j++)
				{
					printf("%d ", mat[i][j]);
				}
				printf("\n");
			}
			printf("is OK.");
	}
	else//if not,it prints isnt ok.
	{
		printf("\nmatrix\n");
		for (i = 0;i < 5;i++)
		{
			for (j = 0;j < 5;j++)
			{
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		printf("isn't OK.");
	}
	getch();
}
int sumofrow(int mat[][5],int n,int x)
//input:matrix,size of matrix and number of row,output: 1 or 0,algoritm:the function check the sum of the row and if is equal to row,it send back 1. 
{
	int i, j,count=0,sum=0;
	for (i = 0;i < n;i++)
	{
		sum = sum + mat[x][i];
	}
	if (sum == x)
	{
		return 1;
	}
	else
		return 0;
}
int diagonal(int mat[][5],int n)
//input:matrix and her size,output:1 or 0,algoritm:the function check the numbers of the elite diagonal of matrix and return 0 if one of them is negative,if not it send back 1.
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (mat[i][i] < 0)
		{
			return 0;
		}
	}
	return 1;
}
