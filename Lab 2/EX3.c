#include<stdio.h>
#include<conio.h>
#include<math.h>
#define NUM 3
struct complexnum
{
	float re;
	float im;
}typedef complexnum;
float CRadius(complexnum* num);
complexnum* Cmax(complexnum* arr);
int main()
{
	int i;
	complexnum *max;
	complexnum arr[NUM];
	printf("Enter 3 complex numbers:\n");
	for (i = 0; i < NUM; i++)
		scanf("%f %f", &arr[i].re, &arr[i].im);//the user will enter a complex number
	max = Cmax(arr);
	printf("The max complex number is %.2f+%.2fi", max->re, max->im);//will print the result
	printf("\nThe radius if the max number is %.2f", CRadius(max));//will print the result
	getch();
}
float CRadius(complexnum* num)
{
	return pow((num->re*num->re) + (num->im*num->im), 0.5);//the fucntion will calculate the radius of the complex number
}
complexnum* Cmax(complexnum* arr)
{
	int i, max = 0;
	for (i = 1; i < NUM; i++)
	{
		if (CRadius(arr + max) < CRadius(arr + i)) max = i;//the function will check which of the 3 complex numbers have the biggest radius
	}
	return (arr + max);
}