#include <stdio.h>
#include<conio.h>
int lengthOfString(char *s);

int main()
{
	char *text = "Experimental text to test recursive function.";
	printf("Length of string: \n%s\n is %d.\n", text, lengthOfString(text));
	getch();
	return 0;
}
int lengthOfString(char *s)/*/function name:lengthOfString
input:pointer to string.
output:the number of the chars in the string.
algoritm:this is a recursive function that recived string and check the length of the stirng until the string end with '\0'./*/
{
	if (s[0] == '\0')
		return 0;
	return 1 + lengthOfString(s + 1);
}
