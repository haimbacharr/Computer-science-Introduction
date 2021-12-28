#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define M 12
#define N 8
int checkfunc(char mat[N][M], int rowbegin, int rowend, int colbegin, int colend, char sym);
void print_metrix(char mat[][M],int n,int m);
void check_rec(char mat[][M],int n,int m);
void main()
{
	char mat[N][M] = {
		{ '#','#','#','.','.','.','?','?','.','.','+','.' },
		{ '#','#','#','.','=','.','?','?','.','.','+','.' },
		{ '#','#','#','.','.','.','.','.','.','.','+','.' },
		{ '.','.','.','.','.','?','?','?','.','.','.','.' },
		{ '?','?','?','.','.','?','?','?','.','.','=','=' },
		{ '?','.','?','.','.','.','.','.','.','.','=','=' },
		{ '?','?','?','.','+','+','+','.','.','.','.','.' },
		{ '?','?','?','.','+','+','+','.','#','#','.','#' } };
	print_metrix(mat,N,M);
	printf("\n");
	check_rec(mat,N,M);
	_getch();
}

//function name : check_rec
//input: matrix with its sizes of rows and coluns.
//output:nothing
//alogaritem: 2 for loops that checks the sizes of the rectangle, check if the reactangle full with the same char(in case thay are similar we count them)
// to progress faster in the matrix and not count what we checked already we reset every rectangle that cheked into dots.
//after all the checks we print the char and the full reactangle in the matrix
void check_rec(char mat[][M],int n,int m)
{
	int startR, endR, startC, endC, i, j, check = 0;
	char Char;
	char arr[N][M];
	int ABC[128] = { 0 };//we create a counter array of the ascci chart code.
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			arr[i][j] = mat[i][j];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			if (arr[i][j] != '.')
			{
				Char = arr[i][j];
				startR = i;
				startC = j;
				while (arr[i][j] != '.' && j < M)
					j++;
				endC = j;
				j = startC;
				while (arr[i][j] != '.' &&i < N)
					i++;
				endR = i;
				i = startR;
				check = checkfunc(arr, startR, endR, startC, endC, Char);
				if (check)
				{
					ABC[Char]++; 
				}

				int t, k; 
				for (t = startR ; t < endR; t++)
					for (k = startC; k < endC; k++)
						arr[t][k] = '.';
			}
	}
	printf("\n");

	for (i = 0; i < 128; i++)//according to the array counter of the ascci char we print all the full reactangle char.
		if (ABC[i] != 0)
			printf("\n%c    %d\n", i, ABC[i]);
}
//function name : check_func
//input: matrix with its sizes of rows and coluns,the start and end of coluns and rows.
//output:1 for good reactangle 0 for not .
//alograitem: one constructive loop- cheacking the fullnes of the reactangle with the char that the function recived.

int checkfunc(char mat[N][M], int startr, int endr, int startc, int endc, char Char)
{
	int i, j, check = 1;
	for (i = startr; i < endr; i++)
		for (j = startc; j < endc; j++)
			if (mat[i][j] != Char)
			{
				check = 0;
				return check;
			}
	return check;
}
//function name : print metrix
//input: a matrix and its sizes
//output: the metrix
//alograitem: one for loop.
void print_metrix(char mat[][M],int n,int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%c ", mat[i][j]);
		printf("\n");
	}
}