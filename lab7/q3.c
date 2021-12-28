#include <stdio.h>
#define N 10
void main()
{
	int ar[N] = { 0 }, num, i, most = 0; //the array  will begin from zero 
	printf(" Please enter a number: ");
	scanf("%d", &num);
	if (num < 0)
	{
		num = num * (-1); //the negative number will be positive
	}
	while (num != 0) //the loop check all until received number that different from zero
	{
		ar[num % 10]++;//check the units.
		num = num / 10;
	}
	for (i = 0; i < N; i++) //the loop will run on the array again,and check where the highest sum.
	{
		if (ar[i] > 0)
		{
			printf("The number %d shows up %d times\n", i, ar[i]);
		}
		if (ar[i] > most)
		{
		most = i;
	    }
	}
	printf("The number %d shows up the most times!\n", most);
}
