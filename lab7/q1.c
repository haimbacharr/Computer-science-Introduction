#define N 20
#include <stdio.h>

int addNums(int  array[N]);
int main()
{
	int i, array[N];  /*1*/
	printf("Enter 20 integers separated by  \ spaces: ");
	for (i = 0; i<N; i++)
		scanf("%d", &array[i]); /*2*/
	printf("\n The sum is:%d\n", addNums(array));/*3*/
	return 0;
}
int addNums(int array[])/*4*/
{
	int i, sum = 0;
	for (i = 0; i < N; i++)
		sum = sum + array[i];      /*5*/

	return sum; /*6*/
}

