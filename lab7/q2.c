#include <stdio.h>
#define N 10
float avg(float[]);
void main()
{
	int i, count = 0;
	float array[N];//array in float numbers
	printf("Enter the round time of 10 compitators:");
	for (i = 0; i < N; i++)
	{ 
		scanf("%f", &array[i]);//will absorb 10 results.
    }
	avg(array);//the function will calculate the average of the 10 results.
	for (i = 0; i < N; i++)
	{ 
		if (avg(array) > array[i])//we will check every result if the result under than the average we will count her.
		count++;
    }
	printf("the number of runners,runnig below the averge time is: %d", count);
}

float avg(float array[])
{
	int i;
	float sum = 0;
	for (i = 0; i < N; i++)
		sum = sum + array[i];//calculate the sum of the 10 results/
	return sum / N;//calculate the average of the 10 results
}
