#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define N 7
void gets_arr1(int arr1[]);
int condition(int maxvalue);
void random_arr2(int arr2[], int maxvalue);
int check_arr1and2(int arr1[], int n);
int check_double_axist(int num, int arr[]);
void print_arrs(int arr1[], int n);

int main()
{
	int arr1[N], arr2[N], arr3[N], maxvalue, i, k = 0;//arr1 for the user,arr2 for random,arr 3 for the new array,maxvalue for the random.
	gets_arr1(arr1);//function call for insert array from the user.
	printf("enter max value greater than zero:");
	scanf("%d", &maxvalue);
	while (condition(maxvalue) == 0)//function call for user insert 0 in the maxvalue.
	{
		printf("error\nenter maxvalue:");
		scanf("%d", &maxvalue);
	}
	random_arr2(arr2, maxvalue);//fucntion call for random arr2.
	for (i = 0; i < N; i++)
	{
		if (check_arr1and2(arr2, arr1[i]))//a condition to check if the number of arr1 in i index is equal to the arr2 number in the same index. 
		{
			if (check_double_axist(arr1[i], arr3) == 7)//we copy the value in arr1 just if the number doesnot exist alredy in the arr3- we dont want duplications
			{
				arr3[k] = arr1[i];
				k++;
			}
		}
	}

	printf("\nArray 1:");
	print_arrs(arr1, N);//function call for sending arr1 for print.
	printf("\nArray 2:");
	print_arrs(arr2, N);//function call for sending arr2 for print.
	if (k == 0)// a condition that check if theres no matching numbers in arr1 and arr2 and print no.
	{
		printf("\nno!");
	}
	else
	{
		printf("\nArray 3:");
		print_arrs(arr3, k);//function call for sending arr3 for print.
	}
	getch();
	return 0;
}
void gets_arr1(int arr1[])// input:arr1,output:none,algoritm: recivied arr from the main and ask the user for numbers.
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("enter arr[%d]:", i);
		scanf("%d", &arr1[i]);
	}
}
int condition(int maxvalue)//input:maxvalue,output:1 or 0,algortim : the number recived form the main send to this fuction that check if it 0 or down and send back 1 or 0.
{
	if (maxvalue < 0)//if the number is 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void random_arr2(int arr2[], int maxvalue)//input:arr2,maxvalue - output:none,algortim:a function that recive array and maxvalue and randomely put numbers (up to maxvalue) in the array.
{
	int i;
	srand(time(NULL));//this is a definition for the function to start from 0 (null)
	for (i = 0; i < N; i++)
	{
		arr2[i] = rand() % (maxvalue)+1;
	}

}
int check_arr1and2(int arr[], int n)//input:arr2 and number of arr1,output: 1 or 0,algortim: this function recived arr2 and the a number of arr1 and equl them,if they equal it send back 1 or not it send back 0.
{
	{
		int i;
		for (i = 0; i < N; i++)
		{

			if (n == arr[i])
				return 0;
		}
		return 1;
	}

}

int check_double_axist(int num, int arr[])//we check if the num in the arr1 already exist in arr3- we sent the value in arr1 and check all the values in arr3//
{
	int i, count = 0;

	for (i = 0; i < N; i++)
	{
		if (arr[i] != num)
			count++;// if we check all the arr3 and we didnt recognize even one smilar value we want to see in the final count 7 like the length of the array//
	}
	return count;
}
void print_arrs(int arr[], int n)//input:array and number for the loop,output:none,algortim:this function gets array and print it with loop until the n number she recived.
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
