#include <stdio.h>
#include <conio.h>
int perfect_matrix(int **mat, int n);

void main()
//Function name: void main
//Input: mtrix dementios, and matrix elements 
//Output: print the matrix,print if the matrix perfect or not, in case the user doesnt type a postive value the itrion stops.
//Algorithm: for loop- description in the function.
{
	int n, i, j,flag=1;
	int **matrix;
	while (flag)
	{
		printf("Enter n,please;");
		scanf("%d", &n);
		if (n <= 0)
		{
			flag = 0;
		}
		else
		{
			printf("Enter %dx%d matrix elements,please\n", n, n);
			matrix = (int*)malloc(n * sizeof(int));//create a memory alloction 
			if (matrix == NULL) printf(" the alloction faild");//check if the aloction sucseed
			for (i = 0; i < n; i++)
				matrix[i] = (int *)malloc(n * sizeof(int));
			for (i = 0; i < n; i++)//scan the elemnts
			{
				for (j = 0; j < n; j++)
				{
					scanf("%d", &matrix[i][j]);
				}
			}
			printf("the metrix:\n");//print the matrix
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%3d", matrix[i][j]);

				}
				printf("\n");
			}
			if (perfect_matrix(matrix, n) == 1)
			{
				printf("is perfect\n\n");
			}
			else printf("\nis not perfect! \n");

		}
	}
	printf("Thank you for exploring perfect Matrixs");
	for (i = 0;i < n;i++)
		free(matrix[i]);//free alloction
	free(matrix);

	getch();
}
int perfect_matrix(int **mat, int n)
//Function name: perfect_matrix
//Input: matrix and its dementios
//Output: 1 for perfect matrix 0 for not
//Algorithm: for loop- description in the function.
{
	int i, j, count = 0, count1 = 0, k, t;
	int *arr;
	arr = (int*)calloc((n + 1), sizeof(int));//create an array and reset it.
	if (arr == NULL)
		printf("the alloction faild");//checking for alloction
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (mat[i][j] > 0 && mat[i][j] <= n)//if every number in the matrix is smallest fron the n and gerater than 0 its a good number
				count++;// count all the good numbers

	if (count == n * n)// in case the matrix is perfect we need to get n*n good numbers
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				arr[mat[i][j]]++;// turn to the counter array and count all the numbers in the matrix
			for (k = 1; k < n + 1; k++)
			{
				if (arr[k] == 1)// if the array conclude 1 
				{
					count1++;// please count all the 1 that shown in the array
				}
			}
			for (t = 0; t < n + 1; t++)// reset the array for the next itrion
				arr[t] = 0;
		}
	}
	if (count1 == n * n)// in case we count n*n 1 that mean the matrix is perfect.
		return 1;
	return 0;
}
