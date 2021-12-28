#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define LEN 256
int recursiveHasPrefix(char *str, char *prefix);
int main() {
	char str[LEN + 1];
	char pre[LEN + 1];
	int isPrefix = 1;
	while (isPrefix) /* As long as pre is a predix of str */
	{
		printf("Please enter a string: "); /*input two strings*/
		gets_s(str, LEN);
		printf("Please enter a prefix string: ");
		gets_s(pre, LEN);
		isPrefix = recursiveHasPrefix(str, pre);/*check whether pre is a prefix of str.*/
		if (isPrefix) printf("The specific text has the prefix.\n\n");
		else printf("No prefix.\n\n");
	}
	getch();
	return 0;
}

int recursiveHasPrefix(char *str, char *prefix)/*/function name:recursiveHasPrefix
input:two pointers for two strings.
output:1 or 0
algoritm:this is a recursive function that recived two strings and compare the first letters until they dont equal and return 1 if
the strings has the same letters in the begining or 0 if no./*/
{
	if (prefix[0] == '\0') return 1;
	if (*str == '\0') return 0;
	if (*str == *prefix)
		return recursiveHasPrefix(str + 1, prefix + 1);
	return 0;
}
