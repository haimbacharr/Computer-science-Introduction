#include <stdio.h>
#include <conio.h>
#include <string.h>
void replaceSubstring(char*, char*);
void main()
/*Function name: main
Input: 2 strings that the user puts
Output: print the string after changes
Algorithm: while loop untul the user doesnt type a string, if condition*/
{
	char str[100], substring[100];
	int flag = 1;
	while (flag == 1)
	{
		printf("enter text :");
		gets(str);
		if (*str != '\0')
		{
			printf("enter substring:");
			gets(substring);
			if (*substring != '\0')
			{
				replaceSubstring(str, substring);// function call send 2 strings
				puts(str);
			}
			else
				flag = 0;
		}
		else flag = 0;
	}
	printf("finish!");
	getch();
}

void replaceSubstring(char* str, char* substring)
/*Function name: replaceSubstring
Input: 2 pointer to a strings
Output: send to the main function the string after changes
Algorithm: while loop, if condition*/

{
	char* p; char*q;
	p = strstr(str, substring);
	q = substring;
	if (p != NULL)
	{
		while (*p != NULL)
		{
			if (*p >= 'a' && *p <= 'z') //the functuion will work only on small letters//
			{
				if (*p == *q)
				{
					if (*(p + 1) == *(q + 1) || *(p + 1) == ' ' || *(q + 1) == '\0')// the letters will change only if the lettrs in the first string will be exactly like the second
					{
						*p = *p - 32;
						p++; q++;
					}
					else p++;
				}
				else p++;
			}
			else p++;
			if (*q == NULL)// if the second string will get to the last letter reset until there is no smilar letter in the first array.
				q = substring;
		}
	}

}
