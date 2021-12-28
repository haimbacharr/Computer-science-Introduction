#include<stdio.h>
#include<conio.h>
#include<time.h>

#define COLUMNS 10
#define ROW 5

void initRandomArray(int p[][COLUMNS]);
void sortArry(int arr[][COLUMNS]);
void SortInColumn(int arr[][COLUMNS], int col);
int compqreColumns(int arr[][COLUMNS], int col1, int col2);
void SortColumns(int arr[][COLUMNS]);
void swapColumns(int arr[][COLUMNS], int col1, int col2);
void swap(int* p, int* q);
void printArray(int arr[][COLUMNS]);

void main()
{
	int Mat[ROW][COLUMNS] = { 0 };
	initRandomArray(Mat);
	printf("Before sorting:\n");
	printArray(Mat);
	sortArry(Mat);
	printf("Sorting columns:\n");
	printArray(Mat);
	getch();
}
void initRandomArray(int Matrix[][COLUMNS])
/*/func name : initRandomArray
input int** value (matrix)
output: None. but rendoize numbers in to the matrix
algorithem : two for loops one for the raws one for the columns/*/
{
	int i, j;
	time_t seconds;
	srand(time(NULL));
	seconds = time(NULL);

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			Matrix[i][j] = rand() % 21;
		}
	}
}

void sortArry(int arr[][COLUMNS])
/*/
func name: sortArry
intput: int** value (matrix)
output: None. but sort and print the the arry that its get (the adress of the matrox)
algorithem: one for loop and call to 2 functions "SortInColumn"  "printArray" /*/
{
	int i;
	for (i = 0; i < COLUMNS; i++)
	{
		SortInColumn(arr, i);
	}
	printf("Sorting elements in each column:\n");
	printArray(arr);
	SortColumns(arr);
}

void SortInColumn(int arr[][COLUMNS], int col)
/*/
func name: sortArry
intput: int** value (matrix)
output: None. but sort and print the the arry that its get (the adress of the matrox)
algorithem: one for loop and call to 2 functions "SortInColumn"  "printArray" /*/
{
	int k, i;
	for (k = ROW; k > 1; k--)
	{
		for (i = 0; i < k - 1; i++)
		{
			if (arr[i][col] > arr[i + 1][col])
				swap(&arr[i][col], &arr[i + 1][col]);
		}
	}
}



void swapColumns(int arr[][COLUMNS], int col1, int col2)
/*/
func name: swapColumns
intput: int** value (matrix), int value int value
output:None. but swap the columns index
algorithem: one for loop and call to the func "swap" in the loop for swiping /*/
{
	int i;
	for (i = 0; i < ROW; i++)
		swap(&arr[i][col1], &arr[i][col2]);
}

void SortColumns(int arr[][COLUMNS])
/*/
func name: SortInColumns
input : int** value (matrix), int value (num of the col)
output: None. but sort the arry
algorithem: two for loops and one if condition for sorting the arry/*/
{
	int k, i;
	for (k = COLUMNS; k > 1; k--)
	{
		for (i = 0; i < k - 1; i++)
		{
			if (compareColumns(arr, i, (i + 1)))
				swapColumns(arr, i, (i + 1));
		}
	}


}

int compareColumns(int arr[][COLUMNS], int col1, int col2)
/*/
func name: compareColumns
intput: int** value (matrix), int value int value
output: int value 1 for TRUE 0 for FALSE
algorithem: one for loop and three if's conditions for compare btween the columns
and returing 1 for TRUE and 0 for FALSE accordind to the condition/*/
{
	int i = 0;


	for (i; i < ROW; i++)
	{
		if (arr[0][col1] > arr[0][col2]) return 1;
		if (arr[i][col1] == arr[i][col2])
			if (arr[i + 1][col1] > arr[i + 1][col2]) return 1;
		return 0;
	}




}

void swap(int* p, int* q)
/*/
func name: swap
input:2 int* values (pointer)
output None.
algorithem swaping the numbers (by pointers to the adress)/*/
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}

void printArray(int arr[][COLUMNS])
/*/
func name: printArry
intput: int** value (matrix),
output: None.
algorithem: two for loops for printing the matrix/*/
{
	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
