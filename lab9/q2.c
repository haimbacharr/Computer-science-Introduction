#include <stdio.h>
#include <conio.h>
#include <string.h>
int emptyString(str);
void main()
{
	char str[100] = { '0' };
	int i = 0;
	printf("enter a string please:");
	gets(str);//Input: a string that the user typed in
	while (emptyString(str) != 0)//Algorithm:while loop - endless loop until we get to an empty string that contain \t or space. 
	{
		while (str[i] != NULL)
			//Algorithm:while loop - endless loop until we get to /0 
		{
			if (str[i] != '\t'&&str[i] != ' ')
			{
				printf("%c", str[i]);//Output: print each letter in the string that doesnt contains a space or tab
				if (str[i + 1] == '\t' || str[i + 1] == ' ' || str[i] != '\t'&&str[i] != ' '&&str[i + 1] == NULL)
					printf("\n");//Output: with every space of tab we start a new line
				i++;
			}
			else i++;// if the string start with tab or space we advanced to the next place in the string and see if he stand with the condition.
		}
		printf("\nenter a string please:");
		gets(str);//Input: a string that the user typed in input inside the loop
		i = 0;	//resate the index for new string
	}
	printf("finish !");
}

int emptyString(char str[])// a function that return 0 if the str lenght is enpty- the user typed in /t or space.
{
	int j, count = 0;
	for (j = 0;str[j] != NULL; j++)
	{
		if (str[j] == ' ' || str[j] == '\t')
			count++;
	}
	if (count == strlen(str))
		return 0;
}
