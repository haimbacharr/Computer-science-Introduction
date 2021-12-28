#include<stdio.h>
#include<math.h>
void main()
{
	int num1, num2,finish=0;//num1 + num2 for sumbit two numbers,finish for the loop
	char ch;//for the character in the loop
	while (finish !=1)//a loop that stops when Q or q is sumbit.
	{
		printf("enter a character,please:");
		rewind(stdin);//remove any char that submit during the loop
		ch = getchar();
		switch (ch)//switch for the actions of the loop
		{
		case 'a':
		case 'A':
			printf("\ngive me 2 numbers:");
			scanf_s("%d%d", &num1, &num2);
			printf("\nthe average of %d and %d is:%f ",num1,num2,(num1+num2)/2.0 );//caculate the average of two numbers.
			if ((num1 + num2) % 2 == 0)//check if the average is integer or fraction
			{
				printf(" is an integer\n");
			}
			else
			{
				printf("is an fraction\n");
			}
			break;
		case '*':
			printf("\ngive me 2 numbers:");
			scanf_s("%d%d", &num1, &num2);
			printf("\nthe product of %d and %d is:%d\n",num1,num2, num1*num2);//caculate the product of the two numbers
			break;
		case 'm':
			printf("\ngive me 2 numbers:");
			scanf_s("%d%d", &num1, &num2);
			(num1 > num2) ? printf("\n%d is the minimum number\n", num2) : printf("\n%d is the minimum number\n", num1);//checking which of the two numbers is minumum
			break;
		case 'M':
			printf("\ngive me 2 numbers:");
			scanf_s("%d%d", &num1, &num2);
			(num1 > num2) ? printf("\n%d is the maximum number\n", num1) : printf("\n%d is the maximum number\n", num2);//checking which of the two numbers is minumum
			
			break;
		case '^':
			printf("\nenter 2 numbers please:");
			scanf_s("%d%d", &num1, &num2);
			if (num1 == 0)//check if the number of the base is 0
			{
				printf("%d^%d is undefind\n",num1,num2);
			}
			else
			{
				printf("\nthe pow of %d and %d is:%f ", num1, num2, pow(num1, num2));//caculate the power of the two numbers.
				if (pow(num1, num2) == (int)pow(num1, num2))//check if the power is integer or fraction.
				{
					printf("The number is an integer\n");
				}
				else
				{
					printf("The number is a fraction\n");
				}
			}
			break;
		case 'l':
		case'L':
			printf("\nenter 2 numbers please:");
			scanf_s("%d%d", &num1, &num2);
			if (num2 > 0 && num1 > 0 && num2 != 1)//ceck if the numbers is under the Domain Definition of log
			{
				printf("\nlog(%d) in base of log(%d)is :%f ",num1,num2,log(num1)/log(num2) );//caculate the log of the two numbers.
				if (log(num2) / log(num1) == (int)log(num1) / log(num2))//check if the log is integer or fraction.
				{

					printf("is an integer\n");

				}
				else
				{
					printf("is an fraction\n");
				}
			}
			else
			{
				printf("\nnot availabe to cacluate\n");
			}
			break;
		case 'q':
		case 'Q':
			finish = 1;//if the user submit Q or q the finish will be 1 and the loop will stop.
			break;
		default:
			printf("\nErorr\n");//for any submitted char that is not in part of the program.
			break;
		}
	}
	printf("finish");
}
