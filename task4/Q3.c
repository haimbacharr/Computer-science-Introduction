#include <stdio.h>
#include <conio.h>
#define N 6

int minOddLast(int* arr, int n);
int minMatrixOdd(int mat[][N], int n);

void main()
//Function name:void main
//Input: matrix
//Output: print the minimal odd number in the array
//Algorithm: calling to minMatrixOdd
{
	int matrix[N][N] = { { 8, 2, 6, 3, 7, 11 },
	{ 22, 12, 5, 21, 21, 33 },
	{ 4, 80, 1, 1, 7, 9 },
	{ 120, 12, 2, 10, 15, 27 },
	{ 2, 5, 13, 17, 57, 111 },
	{ 54, 14, 3, 111, 111, 113 } };

	printf("the minimal odd number is: %d", minMatrixOdd(matrix, N));
	getch();
}
int minOddLast(int* arr, int n)
//Function name: minOddLast
//Input: array with its sizes
//Output: minimal odd number in the given array
//Algorithm: binary search in recrusive way

{
	if (n == 2) return arr[n - 1];//if the length of the array contain 2 number return the last number in the array
	if (arr[n / 2] % 2 == 0)//else, if the middle value in the array is even(not odd)
	{
		if (arr[(n / 2) + 1] % 2 != 0) return arr[(n / 2) + 1];//and the right value from the middle is odd,return the odd
		else return minOddLast((arr + (n / 2)), n / 2);//in case the middle number and the right number are even please contiue the binary search
	}
	else
	{
		if (arr[(n / 2) - 1] % 2 == 0) return arr[n / 2];//else- if the middle number is odd and the left number is even return the middle number
		else return minOddLast(arr, n / 2);// in case the middle number is odd and the left number also a odd please continue the binary search
	}
}
int minMatrixOdd(int mat[][N], int n)
{
	//Function name:  minMatrixOdd
	//Input: matrix with its sizes
	//Output:  retrun minimal odd number in the given matrix
	//Algorithm: recrusive function that use the minOddLast function

	int MinARR, MinMAT;
	if (n == 1) return (minOddLast(*mat, N));//  if we got to one row please call the minOddLast function that return the smallest number in the array
	else
	{
		if ((MinARR = (minOddLast(*(mat + (n - 1)), N))) <= (MinMAT = minMatrixOdd(mat, n - 1))) return MinARR;//if the last row in the given matrix contain the smallest odd number compare to the matrix without the last row please return the minArr(the value from the arr)
		else return MinMAT;// if the recrusive call with matrix without the last row in every itraion contain the smallest odd number please return the MinMat (the value from the matrix without the last row)
	}
}