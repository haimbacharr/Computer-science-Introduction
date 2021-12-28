#include <stdio.h>
#include <string.h>
#define N 200
int hidden(char str1[], char srt2[]);
void main()
{
	char str1[N + 1] = { "optic" }, str2[N + 1] = { "Computer Science" }, str3[N + 1] = { "option" },str4[N+1]={"nirto"};//3 string recived
	if (hidden(str1, str2) == 1)
		printf("The string %s hidden in %s\n", str1, str2);//if str1 hidden in str2 will print
	if (hidden(str4, str2) == 1)
		printf("The string %s hidden in %s\n", str4, str2);//if str4 hidden in str2 will print
	if (hidden(str3, str2) == 0)
		printf("The string %s isnt hidden in %s\n", str3, str2);//if str3 is hidden in str2 will print

	getch();
}
/*/function name:hidden
input:two str to compare
output:1 or 0
algoritm:the function recives two str,one is the main str and the second is for the function to compare the if their letters is in the main str 
from start to end or from end to start in chronological order.
if yes,it well send back 1,0 if not./*/

int hidden(char str1[], char str2[])
{
	char *p, *q;//pointers for the strs.
	int count = 0;//to count the letters.
	p = str2;
	q = str1;
	while (*p)//the loop will continue untill 1 if the string will end. 
	{
		if (*p == *q)
		{
			p++;
			q++;
			count++;
			if (!(*q))
				return 1;
		}
		else
		{
			p++;
			count++;
		}

	}
	p = str2;
	p += (count - 1);
	q = str1;
	while (*p)//the loop will continue untill 1 if the string will end. this while is for backwards letters.
	{
		if (*p == *q)
		{
			p--;
			q++;
		}
		if (!(*q))
		{
			return 1;
		}
		else
		{
			p--;
		}

	}
	return 0;
}
int hidden(char str1[], char str2[])
{
	char *p, *q;//pointers for the strs.
	int count = 0;//to count the letters.
	p = str2;
	q = str1;
	while (*p)//the loop will continue untill 1 if the string will end. 
	{
		if (*p == *q)
		{
			p++;
			q++;
			count++;
			if (!(*q))
				return 1;
		}
		else
		{
			p++;
			count++;
		}

	}
	p = str2;
	p += (count - 1);
	q = str1;
	while (*p)//the loop will continue untill 1 if the string will end. this while is for backwards letters.
	{
		if (*p == *q)
		{
			p--;
			q++;
		}
		if (!(*q))
		{
			return 1;
		}
		else
		{
			p--;
		}

	}
	return 0;
}
