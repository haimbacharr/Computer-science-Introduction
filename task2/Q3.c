#include<stdio.h>
#include<conio.h>
#define N 6

int add_element_to_start(int[], int, int);
int add_element_to_end(int[], int, int);
int delete_element_by_value(int[], int, int);
void replace_element_by_value(int[], int, int, int);
void print_list(int[], int);

void main()
{
	int arr[N] = { 0 }, num, oldNum, newNum, length = 0, op = 0;//arr for the array of 0,num for recived number,oldnum and newnum for function 4,length is the length of the array,op for choose an option.
	printf("welcome to a program that create your array:");
	printf("\ntheres a copule of option for you!:\nfor add element to start press - 1\nfor add element to end press - 2\nfor delete element by value press - 3\nfor replace element by value press - 4\nfor print list press - 5\nfor exit the program press - 6");
	while (op != 6)
	{
		printf("\n\nthe option is:");
		rewind(stdin);
		scanf("%d", &op);
		switch (op)// we created a 6 options each one contain her own function
		{
		case 1:
			printf("enter a natural number:");
			scanf("%d", &num);
			if (num <= 0) // in case that the user typed Accidentally not a natural number
				printf("pay attention you must enter a natural number - greater than zero!\n");
			else// in case he typed a netural number
			{
				length = add_element_to_start(arr, length, num);// the length get update every time we use the function
				if (length == -1)// in the function we cheaking for a full array if we got -1 that mean the array is full and the length is 6 now
				{
					length = 6;
					printf("The list is full\a");
				}
				else// in case the array doesnt full
				{
					printf("The count of the numbers in the new array is:%d\n", length);
					print_list(arr, length);// we call to the 5th function that print the list
					rewind(stdin);
				}
			}
			break;
		case 2:
			printf("enter a natural number:");
			scanf("%d", &num);
			if (num <= 0)//look in case 1
				printf("pay attention you must enter a natural number - greater than zero!\n");
			else
			{
				length = add_element_to_end(arr, length, num);
				if (length == -1)//look in case 1
				{
					length = 6;
					printf("The list is full\a");
				}
				else
				{

					printf("The count of the Number in the new array is:%d\n", length);
					print_list(arr, length);//look in case 1
					rewind(stdin);
				}
			}
			break;
		case 3:
			printf("enter a natural number:");
			scanf("%d", &num);
			length = delete_element_by_value(arr, length, num);// call to the 3rd function
			printf("the count of the numbers in the new array is:%d\n", length);
			if (length == 0)// because we delete elment there is option that the user will delete all the array , we let the user know that that list now is empty
			{
				printf("the list is empty");
			}
			else
			{
				print_list(arr, length);// if the list isnt empty,call the 5th function
				rewind(stdin);
			}

			break;
		case 4:
			printf("enter a first natural number(oldnum) and a second natural number(new num):");
			scanf("%d%d", &oldNum, &newNum);
			replace_element_by_value(arr, length, oldNum, newNum);// we call to the 4th function
			print_list(arr, length);// call to the 5th function for print our list

			break;
		case 5:
			print_list(arr, length);//call to the 5th function for print our list
			break;
		case 6:
			printf("Finish!\a");
			break;


		default: printf("enter an option between 1-6"); break;// if the user typed in an option that less than 1 and greater than 6
		}

	}
	_getch();
}

//*5 function for 5 option*//
int add_element_to_start(int arr[], int length, int num) //function that add number to the start and move all the other number to the right
{
	int i, count = 0;
	for (i = 0; i < N; i++)// we made a loop that count all the number that not equale to zero if the count is 6 thats mean the array is full and the function return -1/
	{
		if (arr[i] != 0)
			count++;
	}
	if (count == N)
		return -1;

	for (i = length; i > 0; i--)// we made a loop that start from the end to the start with every itertion the numbers move to the right/
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = num;// after all the numbers are moved we put the num that the user typed in the 1st place of the array.
	return (length + 1);//we return the updated length
}

int add_element_to_end(int arr[], int length, int num)//function number 2
{
	int i, count = 0;
	for (i = 0; i < N; i++)//look at function number 1
	{
		if (arr[i] != 0)
			count++;
	}
	if (count == N)
		return -1;
	else
	{
		arr[length] = num;// the place length mean the latest place in the list, in this place we put the number.
	}
	return (length + 1);//we return the updated length
}

int delete_element_by_value(int arr[], int length, int num)//*FUNCTION NUMBER 3- delete number by another number
{
	int i, j, count = 0, arrhelp[N] = { 0 };
	for (i = 0, j = 0; i < length; i++)//we made an extra array that copy all the numbers that not equal to the number that typed in
	{
		if (arr[i] != num)
		{
			arrhelp[j] = arr[i];
			j++; //* the index of the arrhelp grow just if the arrhelp copy the numbers from the original array.
			if (arr[i] != 0)
				count++;
		}
	}
	for (i = 0, j = 0; i, j < N; i++, j++)//we transferd all the numbers from the arrhelp to the original array for print the array after changes.
	{
		arr[i] = arrhelp[j];
	}
	return count;// the function return the count of numbers that show in the new array.
}

void replace_element_by_value(int arr[], int length, int oldNum, int newNum)//4
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == oldNum)
		{
			arr[i] = newNum;
		}
	}
}

void print_list(int arr[], int lentgh)//5
{
	int i;
	printf("the array is:");
	for (i = 0; i < lentgh; i++)
	{
		printf("%d ", arr[i]);
	}

}