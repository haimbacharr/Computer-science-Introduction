#include<stdio.h>
#include<conio.h>
#define N 100
void main()
{
	int num1, i, postfix[N], sum = 0;//num1 for the number of operands,i for the loop,postfix is array of numbers for the operands,sum is caculating the numbers.
	char ope;//ope for operator option.
	printf("enter number of operands<2-100>:");
	scanf("%d", &num1);
	if (num1 < 2 || num1>100)//if the number is under 2 or greater then 100 the program will not proceed.
	{
		printf("wrong number operands\a");
	}
	else
	{
		for (i = 0;i<num1;i++)//a loop that runs until num1 and recieved the numbers by their standing for the array.
		{
			printf("enter operand <%d>:",i);
			scanf("%d",&postfix[i]);
		}
		sum = postfix[num1 - 1];//when the array run until num1,sum will get the last operand the scaned from the array.
				for (i = num1-2;i >= 0;i--)//a loop that runs from the (num1-2) until 0. 
				{
					printf("press operator<+ - *>:");
					rewind(stdin);
					scanf("%c", &ope);//recivied the char for the operator.
					while (ope != '+'&&ope != '-'&&ope != '*')//if the ope isnt (+,-,*) it will get into the while until an Appropriate char will be insert.
					{
						printf("press only <* + ->\n");
						printf("press operator<+ - *>:");
						rewind(stdin);
						scanf("%c", &ope);
					}
					switch (ope)//the options for the opertaors.
					{
					case '+':
						sum = postfix[i]+sum;
						break;
					case '-':
						sum = postfix[i] - sum;
						break;
					case '*':
						sum = postfix[i] * sum;
						break;
					default:
						printf("press only <* + ->\n");
					}
				}
				printf("result:%d", sum);
			}
	getch();
}