#include<stdio.h>
#include<conio.h>
#define N 30
char is_tripple(char *str);

void main()
{
	char str[N],*p,result;
	printf("String:");
	gets(str);
	p = str;
	result = is_tripple(p);
	if (result != '\0')
	{
		printf("In \"%s\" there is \"%c%c%c\"!",str,result,result,result);
	}
	else
	{
		printf("In \"%s\" there is no Triple!",str);
	}
	getch();
}

char is_tripple(char *str)/*/function name:is_tripple
input:pointer to string
output:a char or '\0'
algoritm:a recrucive function that recived string and check if theres a char that appears 3 time in a row
if yes,it will return the char.
if not,it will return '\0'/*/
{
	if (*str == '\0')
	{
		return '\0';
	}
	if (*str == *(str + 1) && *(str + 1) == *(str + 2))
	{
		return *str;
	}
	else
	{
		is_tripple(str+1);
	}
}