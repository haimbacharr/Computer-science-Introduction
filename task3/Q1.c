#include<stdio.h>
#include<string.h>
#include<conio.h>
void sort_str3(char str1[], char str2[],char str3[]);
int check_str(char str[],int n);
char removeDuplicate(char str[]);
void main()
{
	char *str1, *str2, *str3;
	int n,flag=1,flag2=1,res1,res2,sum=0;
	while (flag)
	{
		printf("please enter an integer number of maximum size of string:");
		scanf("%d", &n);
		if (n < 0)//if n is under 0 the program will end.
		{
			printf("the number is not natural number!");
		}
		else
		{
			flag = 0;
		}
	}
	flag = 1;
	while (flag)
	{
		str1 =(char*) malloc(n * sizeof(char));//memory allocation for str1
		printf("please enter the first string containing no more than %d small English letters:",n);
		rewind(stdin);
		gets(str1);
		if (str1 == NULL)//check if memory allocation succeed. 
		{
			printf("the allocation memory faild!");
		}
		else
		{
			res1 = check_str(str1,n);//function call
			if (res1 == 1)//if res 1 recived 1 it means str 1 is ok,else it will print an error.
			{
				while (flag2)
				{
					printf("please enter the second string containing no more than %d small English letters:",n);
					str2 = (char*)malloc(n * sizeof(char));
					gets(str2);
					if (str2 == NULL)//check if memory allocation succeed. 
					{
						printf("the allocation memory faild!");
					}
					res2 = check_str(str2, n);
					if (res2 == 1)//if res 1 recived 1 it means str 1 is ok,else it will print an error.
					{
						flag2 = 0;
					}
					else
					{
						printf("Illegal input:the string must contain only small English letters and no more then %d letters\n", n);
					}
				}
				if (flag2 == 0)
				{
					flag = 0;
				}
			}
			else
			{
				printf("Illegal input:the string must contain only small English letters and no more then %d letters\n",n);
			}
		}
	}
	sum = (strlen(str1) + strlen(str2)+1);//sum is the size of str3 (strlen of str1 + strlen of str2)
	str3 =(char*)malloc(sum * sizeof(char));//memory allocation for str 3
	sort_str3(str1, str2, str3);//function call 
	puts(str3);
	free(str1);
	free(str2);
	free(str3);
	getch();
}

void sort_str3(char str1[], char str2[],char str3[])//input:str1,str2,str3,output:none,algortim: the function recived the string,copy str 1 to str 3 and cat str 2 to the end of str3,then it send it to function that delete the duplicates and then sort them by abc.
{
	int i,j;
	char temp;
	strcpy(str3, str1);
	strcat(str3, str2);
	removeDuplicate(str3);//function call
	for (i = 0; i < strlen(str3) - 1; i++)
	{
		for (j = i + 1; j < strlen(str3); j++)
		{
			if (str3[i] > str3[j])
			{
				temp = str3[i];
				str3[i] = str3[j];
				str3[j] = temp;
			}
		}
	}
}

int check_str(char str[],int n)//input:str and the length of the string,output:1 or 0,algoritm:the function check if the length of the string is more then the number we put to allocate memory,if yes the it reutrn 0,then it check if the the string is composite only with little abc, if yes it will send 1.
{
	int i=0, count = 0;
	if (strlen(str) > n)
	{
		return 0;
	}
	for (i = 0;i < strlen(str);i++)
	{
		if (str[i]<'a' || str[i]>'z')
		{
			return 0;
		}
	}
	return 1;
}
char removeDuplicate(char str[])//input:str3,output:str,algoritm:the function recived str3 and remove the duplicate charcters.
{
	int i, j, k;
	for (i = 0; i < strlen(str); i++)
	{
		for (j = i + 1; str[j] != '\0'; j++)
		{
			if (str[j] == str[i])
			{
				for (k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
			}
		}
	}
	return str;
}
