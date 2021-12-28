#include <stdio.h>
#include <conio.h>
#define N 4
#define M 5

shift(int, int, int);

void main()
{
	//Function name: main
	//Input: a matrix
	//Output: print 3 matrix after changes
	//Algorithm: 2 for loop- scan and print matrix.

	int i, j, matrix[N][M], flag = 1;
	printf("please enter 4x5 matrix element:\n");
	for (i = 0; i < N; i++)//scan
	{
		for (j = 0; j < M; j++)
			scanf("%d", &matrix[i][j]);
	}
	while (flag <= 3)// with every print the flag count +1 ,a total of 3 prints 
	{
		shift(matrix, N, M);// function call
		printf("shift %d :\n", flag);
		flag++;
		for (i = 0; i < N; i++)//print
		{
			for (j = 0; j < M; j++)
				printf("%3d", matrix[i][j]);
			printf("\n");
		}
		printf("\n");


	}
	getch();
}
shift(int matrix[][M], int rows, int coulns)
//Function name: shift
//Input: a matrix, and her size
//Output: matrix after changes
//Algorithm: 3 for loop- for copy values and moving values.

{
	int i, j, arr[4];// create an array that keeps all the last coulns values
	for (i = 0; i < rows; i++)
	{
		arr[i] = matrix[i][coulns - 1];// copy the values to the array
		for (j = coulns - 1; j > 0; j--)
		{
			matrix[i][j] = matrix[i][j - 1]; //move values to the right
		}
	}
	for (i = 0; i < 4; i++)
	{
		matrix[i + 1][0] = arr[i];//put all the valus in the array to the first coulns from the secont row
	}
	matrix[0][0] = arr[i - 1];// put in the 1st place in the matrix the last values in the matrix that we keepd in the last place in the array.
}
