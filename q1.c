#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,num,sum=0;                             //Variables declaration.
	printf("Enter a  positive integer please:"); //Asking positive number from the user.
	scanf_s("%d", &num);
	for (n = 1; n <= num; n++) {                 //Loop that shows all the members from the first memberr until the value of num.
		sum += n;                                //Calculating the next members.
			printf("%d\n",sum);                   //Printing the members.
	}
	return 0;
}