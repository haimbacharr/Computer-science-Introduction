#include<stdio.h>
#define N 9
void check_strID(char[]);
int algoritm(char[]);
void main()
{
	char ID[N + 1];// an str for the numbers of ID (N+1 becuase of '\0')
	check_strID(ID);//send the STR to the function.
	if (algoritm(ID))
		printf("Corcect ID!");
	else
	{
		printf("Incorrect ID!\n");
	}
	getch();
}
void check_strID(char id[])//an function for checking if the ID has chars on it (not numbers)
{
	int i, flag = 0;//i for the loop,flag for the while.
	printf("Enter your ID:");
	do {
		for (i = 0; i < N; i++)//a loop to scan the ID.
		{
			scanf("%c", &id[i]);
		}
		id[N] = '\0';
		rewind(stdin);
		for (i = 0; i < N - 1; i++)//a loop to check if the ID has chars on it (not numbers)
			if ((id[i] < '0') || (id[i] > '9'))
			{
				flag = 1;//if one the ID numbers has a char,the loop will run out and send 0 to the main.
			}
	} while (flag = 0);
}
int algoritm(char id[])//an algoritm to check if the ID is correct.
{
	int calc = 0, calcdig = 0, ar_chk[N] = { 1,2,1,2,1,2,1,2,1 }, i;//calc is caculating,calcdig for numbers above 9,ar_chk for weight of the number of the ID (left to right)
	for (i = 0; i < N; i++)//a loop that runs until N ("\0")	
	{
		calc = (id[i] - '0')*ar_chk[i];//a cacluate of the number in the str multiply his weight (left to right)
		if (calc > 9)//if calc is above 9,caldig will be the units plus 1.
			calcdig += (calc % 10) + 1;
		else//if not,caldig will plus calc
			calcdig += calc;
	}
	if (calcdig % 10 == 0)//if the sum of the ID According to the algorithm is divide by 10,the ID is correct,if not the id is incorrect.
		return 1;
	else
		return 0;
}

