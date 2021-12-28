#include<stdio.h>
#include<conio.h>
int inputThree(int*, int*, int*);
void sortTwo(int *, int*);
void sortThree(int*, int*, int*);

int main()
{
	int x,y,z,res=1;
	while (res != 0)//a while loop that runs until res get 0.
	{
		printf("enter a 3 numbers,please:");
		res = inputThree(&x, &y, &z);//function call
		sortThree(&x, &y, &z);//function call
		if (res != 0)
		{
			printf("%d %d %d\n", x, y, z);
		}

	}
	printf("bye bye :)");//end of the program.
	getch();
}

int inputThree(int*a, int*b,int*c)//the function recieved 3 pointers from the main and scan to them a values,return and int number of 1 if the numbers are not 0 and if not,return 0.
{
	scanf("%d%d%d", a, b, c);
	if (*a == 0 && *b == 0 && *c == 0)//if the pointers gets 0,the function return 0 and the while is end.
	{
		return 0;
	}
	else//if not,the function will return 1 and proceed.
	{
		return 1;
	}
}

void sortTwo(int *a, int*b)//the function recieved 2 pointers from sortThree and dont return a value, the function check if the numbers are in rising segment  
{
	int temp;
	if (*a > *b)// a condition- if the pointer a  is greater than b, b gets the a's value and the opposite.
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
void sortThree(int*a, int*b, int*c)//the function recieved 3 pointers from the main,dont return value and check the arrange sequences by funtion sort two.
{
	sortTwo(a, b);
	sortTwo(b, c);
	sortTwo(a, b);
}
