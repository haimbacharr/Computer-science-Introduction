#include <stdio.h>
#include<conio.h>
int isPalindrom(int arr[], int n);
int main()
{
	int n, *arr, i, res;
	printf("Enter a length of an array(bigger from 0),please:");
	scanf("%d", &n);
	while (n > 0)
	{
		arr = (int*)malloc(n * sizeof(int));//memory allocation for the array.
		if (arr == NULL)//check if the memory allocation succeeded.
		{
			printf("no memory");
			return 0;
		}
		printf("Enter %d elements,please:", n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		res = isPalindrom(arr, n);
		if (res == 0)
		{
			printf("The array isn't a Palindrom\n");
		}
		if (res == 1)
		{
			printf("The array is a Palindrom\n");
		}
		free(arr);
		printf("Enter a length of an array,please:");
		scanf("%d", &n);
	}
	printf("Thank you for exploring palindrome arrays.");
	getch();
	return 0;
}

int isPalindrom(int arr[], int n)/*function name:isPalindrom
input:pointer to array,length of the array.
output:1 or 0.
algoritm:this is a recursive function that recived array and check if the array is palindrom by compare the number
from the start to the number in the same n spot from the end until n is 1.
if it is palindrom,the function return 1,else return 0.
if n is equal to 1 or under 1 the funtion will send back 1.*/
{
	if (n <= 1)
	{
		return 1;
	}
	if (arr[0] == arr[n - 1])
	{
		return isPalindrom(arr + 1, n - 2);
	}
	return 0;
}
