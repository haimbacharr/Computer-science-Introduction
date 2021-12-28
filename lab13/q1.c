#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 4
void printReversedFromTo(char* str, int start, int end);
//Function name:main
//Input:given str
//Output: print the values with help of the recrusive function
//Algorithm: for loop and calling to recrusive function
int main() {
	char *text = "Experimental text to print reversed fragment.";
	int i, len = strlen(text);
	int From_Vec[4] = { 0, 0, 10, 22 },
		To_Vec[N] = { len - 1, len / 2, len - 1, 33 };
	for (i = 0; i < N; i++) {
		printf("*** Reversed from %d to %d:\n", From_Vec[i], To_Vec[i]);
		printReversedFromTo(text, From_Vec[i], To_Vec[i]);
		printf("\n");
	}
	printf("\n*** Finish.\n");
	getch();
	return 0;

}
void printReversedFromTo(char* str, int start, int end)
//Function name: printReversedFromTo
//Input:str,start and end index
//Output: print the str from end to start
//Algorithm: recrusive function
{
	if (*str == '\0')return;//if the given str already empty
	else
	{
		if (start == end) printf("%c", *(str + start));//if the index are equale please print the value in the index
		else printReversedFromTo(str, start + 1, end);
		printf("%c", *(str + start - 1));//explantion below the function
	}
}
//explation- after the start memory box always rise until she get value equal to the end in every call to the function
// we print the value in the start+1 index- but when the function return we want conction to the previous function
// that conction print the start-1 value - thats mean- with every call the function open memory for the start+1 value but when she
//come back from where she called she need to print the value in the cuurent start/

