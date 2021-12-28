#include <stdio.h>
void f(char, int);//function that recieved a char and n for print
void main()
{
	int n;//number of rows
	char ch;//char to print
	printf("Enter character and integer,please:");
	scanf("%c %d", &ch, &n);
	f(ch, n);//send to the function
}
void f(char ch, int n)
{
	int i, j, temp;//i,j for the double loop ,temp for the inner loop
	temp = n;//temp is equal to n for the inner loop would start from the highest number
	for (i = 0;i < n;i++)//loop that start from 0 and run until n
	{
		for (j = temp; j > 0; j--)//loop that run from temp (n) until 1.
			printf("%c", ch);//print the char - n times in row according to the loop.
		printf("\n");
		temp--;//temp is dwindling every time until 1
	}
}

void f(char ch, int n)
{
	int i, j, temp;//i,j for the double loop ,temp for the inner loop
	temp = n;//temp is equal to n for the inner loop would start from the highest number
	for (i = 0;i < n;i++)//loop that start from 0 and run until n
	{
		for (j = temp; j > 0; j--)//loop that run from temp (n) until 1.
			printf("%c", ch);//print the char - n times in row according to the loop.
		printf("\n");
		temp--;//temp is dwindling every time until 1
	}
}
