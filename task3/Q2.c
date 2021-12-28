/*Please note that the program treats a word with comma and word without comma as a different word (like in microsoft word and such programs).So in a show like "ex, ex"
ex is NOT a repeat for ex,*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define N 100 
void spacespointcomma(char, char); //function that fixes invalid spaces,points and commas in a sentence.
void capitalletter(char, char); //function that fixes capital letters in a sentence.
void repeatingwords(char, char); //function that fixes repeating words in a sentence.
void main()
{
	char str[N], fixed[N] = "";
	gets(str);
	while (*str == NULL) //check if user did not enter empty string
	{
		printf("Empty string. Try again!\n");
		gets(str);
	}
	spacespointcomma(str, fixed); //call the function that fixes spaces point and commas.
	capitalletter(str, fixed); //call the function that fixes capital letters.
	repeatingwords(str, fixed); //call the function that fixes repeating words.
	printf("The correct sentence is:\n%s", fixed); //print the fixed sentence.
	getch();
}
void spacespointcomma(char str[], char fixed[]) //the function recieves the original string and an empty string and setting all the fixes to the empty string.
{
	int i = 0, j = 0, start, k = 0, len, flag = 1;//the information about the integers will be explain in the continued
	while (str[i] != '\0'&&str[i] == ' ') //this loop fixes spaces in the beggining by starting the fixed string with the first letter in the original string,len for the length of the fixed string
		if (str[i] == ' ') i++;
	start = i;
	while (str[start] != '\0') fixed[k++] = str[start++];
	while (str[i] != '\0'&&str[i] != '.') //check only things inside the sentence (before the '.')
	{
		if (str[i] == ' ') //this fixed multiple spaces by "ignoring" spaces that come after the first space and setting the fixed string from that position.
		{
			while (str[i] == ' '&&str[i] != '\0') i++;
			i += -1;
			while (str[i] != '\0' && str[i] != ' ')
				fixed[j++] = str[i++];
		}
		if (str[i] != '\0')
			fixed[j++] = str[i++];
	}
	if (fixed[j - 1] == ','&&fixed[j - 2] != ' ') //this replaces ',' in the end of the sentence with '.'
	{
		fixed[j - 1] = '.';
		fixed[j] = '\0';
	}
	else if (fixed[j - 1] == ',' &&fixed[j - 2] == ' ') //this fixes ' ' and then ',' in the end of the sentence.
	{
		fixed[j - 2] = '.';
		fixed[j - 1] = '\0';
	}
	else //if theres no comma in the end of the sentence just add a '.' in the end of it if does not exist.
	{
		fixed[j] = '.'; //this adds '.' in the end of the sentence if does not exist.
		fixed[j + 1] = '\0';
	}
	if (fixed[j - 1] == ' ') //this fixes space before '.'
	{
		fixed[j - 1] = '.';
		fixed[j] = '\0';
	}
	i = 0;
	j = 0;
	while (fixed[i] != '\0') //this loop fixes sapce before comma by "moving" the string backwards if theres space before a comma.
	{
		if (fixed[i] == ',' && fixed[i - 1] == ' ')
		{
			fixed[i - 1] = ',';
			fixed[i] = ' ';
		}
		i++;
	}
	i = 0;
	while (fixed[i] != '\0') //this loop fixes no space after comma by adding one and "moving" the string forward.
	{
		if (fixed[i] == ','&&fixed[i + 1] != ' ')
		{
			j = i;
			while (fixed[j] != '\0') j++;
			fixed[j + 1] = '\0';
			while (j != i)
				fixed[j + 1] = fixed[--j];
			fixed[i + 1] = ' ';
		}
		i++;
	}
	j = 0;
	len = strlen(fixed);//recive the length of the fixed string.
	for (i = 0; i < len; i++) //this loop will check the fixed string,if there is more than 1 space between ',' he will recive only 1 ' ' (space).
	{
		fixed[j] = fixed[i];
		if (fixed[i] == ','&&fixed[i + 1] == ' '&&fixed[i + 2] == ' ')
			i++;
		j++;
	}
	fixed[j] = '\0'; //adding string end in the fixed string
	i = 0;
	while (fixed[i] != '\0') str[i] = fixed[i++]; //setting the strings to be the same.
	str[i] = '\0'; //adding string end in the original string
}
void capitalletter(char str[], char fixed[]) //this function recieves two strings and fixes the capital letters faults in them. then setting in the fixed string and the string itself.
{
	int i = 1;
	if (str[0] >= 'a' && str[0] <= 'z') fixed[0] += -32; //if the first letter is not capital, make it so.
	while (str[i] != '\0')
	{
		if (str[i] >= 'A'&&str[i] <= 'Z') fixed[i] += 32; //if a letter is capital in the middle of the sentence, turn it into small letter.
		i++;
	}
	i = 0;
	while (fixed[i] != '\0') str[i] = fixed[i++]; //set the string to be like the fixed one.
	str[i] = '\0'; //putting string end in the position
}
void repeatingwords(char str[], char fixed[]) //this function recieves two strings and deletes repeating words in it and setting the fixed string to be without repeating words.
{
	int i = 0, j = 0, k = 0, wordstart = 0, secwordend = 0, notsame = 0; /*i,j,k are used for loops. wordstart gets the position of the first letter in the word to check.
																		 secwordend is getting the position of the last letter in the SECOND word (the one we compare with)
																		 notsame is used as a boolean variable that tells if both checked words are the same or not*/
	char temp[N] = "";
	while (str[i] != '\0')
	{
		if (i == 0 || (str[i] != ' ' && str[i - 1] == ' ')) //this basically checks the first word and then "new words" (if theres space before a letters its a new word)
		{
			if (i == 0) str[i] += 32; //when we check the first word, we want to turn it to small letters for the comaprison
			wordstart = i; //get the position of the first letter in a word
			k = i; //setting a new variable to be like "i" so we dont have to change "i".
			while (str[k] != ' '&&str[k] != '\0') //put the word that we check in a temporary string.
			{
				temp[j] = str[k++];
				j++;
			}
			temp[j] = '\0'; //putting an end to the string
			j = 0;
			k++;
			secwordend = k; //getting position of the last letter in the word we compare with
			while (temp[j] != '\0')
			{
				if (str[k++] != temp[j++] && str[k] != '\0') notsame = 1; //compare the words letter by letter, if any letters dont match change value of notsame
			}
			if (notsame == 0 && str[k] != '\0') //if notsame did not change, the words are the same so we need to delete one.
			{
				while (str[secwordend] != '\0')
				{
					str[wordstart++] = str[secwordend]; //changing the string from the position of the last letter of the duplicated (like "skipping" the duplicated word)
					secwordend++;
				}
				str[wordstart] = '\0'; //setting string end
			}
			if (i == 0) str[i] += -32; //if we checked the first word, set its first letter to a capital letter.
		}
		notsame = 0;
		i++;
		j = 0;
	}
	i = 0;
	while (str[i] != '\0') //setting the fixed string
	{
		fixed[i] = str[i++];
	}
	fixed[i] = '\0'; //setting string end to the fixed string.
}