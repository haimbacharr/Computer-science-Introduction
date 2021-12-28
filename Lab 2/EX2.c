#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 50
typedef struct stud
{
	char *name;
	int marks[4];
	float avg;
}student;
student* Create_Class(int);
void Avg_Mark(student*);
void Print_One(student*);
int main()
{
	int size, i;
	student *arr;
	printf("Enter the number of students:");
	scanf("%d", &size);
	arr = Create_Class(size);//arr will point to the first element of the structs array that Create_Class returns
	for (i = 0; i < size; i++)
		if (arr[i].avg > 85) Print_One(arr + i); //printing only students with avarage higher than 85
	for (i = 0; i < size; i++) //free every memory allocation of all names one by one
		free(arr[i].name);
	free(arr); //freeing the allocation of the structs array
	getch();
	return 0;
}

student* Create_Class(int size)//Create_Class recieves the size of the class, and returns the address of the first element of the class array. it also sets all the information
{
	student *arr;
	int i, j;
	char str[MAX_LEN];
	arr = (student*)malloc(size * sizeof(student)); //Allocating memory for array of structs
	if (arr == NULL) //if the allocation failed, print that there is not enought memory and exit the program
	{
		printf("Not enough memory");
		exit(1);
	}
	for (i = 0; i < size; i++) //Setting info for each student
	{
		printf("Enter your name: ");
		scanf("%s", str);
		arr[i].name = (char*)malloc((strlen(str) + 1) * sizeof(char)); //allocating memory for the name string. (+1 for '\0')
		if (arr[i].name == NULL) //if allocation failed, print an error and exit the program
		{
			printf("Not enough memory");
			free(arr); //before exiting, freeing the allocation of the array
			exit(1);
		}
		strcpy(arr[i].name, str); //copying the string from str to the allocated string
		printf("Enter your marks:");
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i].marks[j]);
		Avg_Mark(arr + i); //calling Avg_Mark for each student
	}
	return arr;
}
void Avg_Mark(student* s)//The function recieves address of student struct and sets variable avg in it
{
	int i;
	float avg = 0;
	for (i = 0; i < 4; i++)
		avg = avg + s->marks[i];
	s->avg = avg / 4;
}
void Print_One(student* s)//the function recieves address of students and prints its name and average
{
	printf("The average of %s is %.1f\n", s->name, s->avg);
}

