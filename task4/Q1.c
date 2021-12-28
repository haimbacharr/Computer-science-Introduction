#include<stdio.h>
#include<conio.h>
int A(int m, int n);

void main()
{
	int m, n,result;
		printf("Please insert m and n:");
		scanf("%d%d", &m, &n);
		if (n > 0 && m > 0)//check if the numbers and non negatives.
		{
			result = A(m, n);
			printf("Ackermann<%d,%d>=%d.", m, n, result);
		}
		else
		{
			printf("one of the numbers are negative!");
		}
		getch();
}

int A(int m, int n)/*/function name:A
input:two numbers
output:ackermann number
algoritm:this is a recurcive function that recived two numbers and act According to a conditions of the ackermann number until m=0
and the function returns n to the main./*/
{
	if (m == 0)
	{
		n++;
		return n;
	}
	if (m > 0 && n == 0)
	{
		A(m - 1, 1);
	}
	if (m > 0 && n > 0)
	{
		A(m - 1, A(m, n - 1));
	}
}
