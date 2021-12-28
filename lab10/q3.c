#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


int **Get_Mat(unsigned int  r, unsigned int c);
void Set_Mat(int **p, unsigned r, unsigned c);
void Print_Mat(int **p, unsigned r, unsigned c);
void Mat_Mul(int **a, int **b, int **c, unsigned m, unsigned n, unsigned s);
void Free_Mat(int **m);

void main()
{
	unsigned int m, s, o;
	int **m1, **m2, **m3;
	printf("enter three integer unnegative numbers: \n");
	scanf("%u%u%u", &m, &s, &o);

	m1 = Get_Mat(m, o);
	m2 = Get_Mat(o, s);
	m3 = Get_Mat(m, s);

	Set_Mat(m1, m, o);
	Set_Mat(m2, o, s);

	Mat_Mul(m1, m2, m3, m, o, s);
	printf("\nm1:\n");
	Print_Mat(m1, m, o);
	printf("\nm2:\n");
	Print_Mat(m2, o, s);
	printf("\nm3:\n");
	Print_Mat(m3, m, s);


	Free_Mat(m1);
	Free_Mat(m2);
	Free_Mat(m3);

	getch();
	return 0;



}
int **Get_Mat(unsigned int r, unsigned int c)/*Function name: Get_Mat
Input: unsigned int value, unsingend int value
Output: int** matrix (double pointer )
Algorithm: "creat a mtrix" buy int** variable, memory allocation to the matrix
and checking if the alloaction is sucsses or fail, for loop to intelize the
matrix by '0' and return pointer to the matrix
*/

{
	int i, j = 1;
	int **p;
	if (!(p = (int*)malloc(r * sizeof(int))))
	{
		printf("Allocation Fail!");
		exit(1);
	}
	if (!(p[0] = (int*)malloc(r*c * sizeof(int)))) {
		printf("Allocation Fail!");
		exit(1);
	}
	for (i = 0; i < c*r; i++) {
		*(p[0] + i) = 0;
		if ((i + 1) % c == 0) {
			p[j] = p[0] + i;
			j++;
		}
	}

	return p;
}
void Set_Mat(int **p, unsigned r, unsigned c)/*Function name: Set_Mat
Input: int**, unsigned, unsigend
Output: the fuctions return nothing, the function set random numbers to the matrix
Algorithm: two for loops for randomize numbers between -50 and 50 to the matrix.
*/

{
	int i, j;
	time_t seconds;
	srand(time(NULL));
	seconds = time(NULL);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{

			p[i][j] = rand() % 101 - 50;
		}
}
void Print_Mat(int **p, unsigned r, unsigned c) /*Function name: Print_Mat
Input: int**, unsigned, unsigned
Output: the function return nothing
Algorithm: two for loops to printing the matrix*/

{
	int i, j;
	for (i = 0; i < r; i++)

	{
		printf("\n");
		for (j = 0; j < c; j++)
			printf("%5d\t", p[i][j]);
	}
	printf("\n");
}
void Mat_Mul(int **a, int **b, int **c, unsigned m, unsigned n, unsigned s)
/*Function name: Mat_Mul
Input: int** ,int** ,int** , unsigned,unsigned,unsigned
Output: the fuction return nothing. the functuin multiply two matrixs
to the third
Algorithm: three for loop the reach the variables and mul it one by one
to the third matrix*/

{
	int i, j, t;
	for (i = 0; i < m; i++)
		for (j = 0; j < s; j++)
			for (c[i][j] = 0, t = 0; t < n; t++)
				c[i][j] += a[i][t] * b[t][j];


}
void Free_Mat(int **m)/*Function name: Free_Mat
Input: int**
Output: nothing
Algorithm: free the memory that allocated.
*/
{
	free(m[0]);
	free(m);
}
