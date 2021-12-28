#include <stdio.h>
#include <math.h>
void main()
{
	int i, n, dec = 0, hex, power, fal = 0; /* i = counter, n= number of digits, dec= converted number from hex to dec.
							 hex = converting from hex to dec base, power is a decreasing value
							 that we use to convert from base 16 to 10, fal will be used to determine if the user entered illegal chars.*/
	long dec_total = 0; // dec total will be the converted number in the end.
	char ch; // we use char variable to store the letters a-f and then convert them to an intiger 0-15.
	printf("Enter the number of digits in the Hexadecimal number(max 7): ");
	scanf("%d", &n);
	while (n <= 0 || n > 7) //this while loop checks if the user entered a true amount of digits (>0) or passed the limit (7) if not, telling him to input a new number.
	{
		printf("Illegal input.\nPlease enter the amount of digits: ");
		scanf("%d", &n);
	}
	rewind(stdin);//this order erase the enter that press in the previous order.
	power = n - 1; // from now, we determine the value of power that will be the number of digits - 1 so we can use it later to convert.
	printf("Enter the Hexadecimal number:");
	for (i = 0; i < n; i++) // do that loop "n" times.
	{
		ch = getchar();
		switch (ch) // this long switch command converts numbers 0-9 and letters a-f,A-F to numbers 0-15 or shows wrong input for any other char.
		{
		case '0':
			dec = 0;
			break;
		case '1':
			dec = 1;
			break;
		case '2':
			dec = 2;
			break;
		case '3':
			dec = 3;
			break;
		case '4':
			dec = 4;
			break;
		case '5':
			dec = 5;
			break;
		case '6':
			dec = 6;
			break;
		case '7':
			dec = 7;
			break;
		case '8':
			dec = 8;
			break;
		case '9':
			dec = 9;
			break;
		case 'a':
		case'A':
			dec = 10;
			break;
		case 'b':
		case 'B':
			dec = 11;
			break;
		case 'c':
		case 'C':
			dec = 12;
			break;
		case 'd':
		case 'D':
			dec = 13;
			break;
		case 'e':
		case 'E':
			dec = 14;
			break;
		case 'f':
		case 'F':
			dec = 15;
			break;
		default: // we use fal=99 so we can set it to have any condition to show or: converted number or: illegal input.
			fal = 99;
		}
		hex = dec * pow(16, power); // converting from left to right number*16/^n-1
		dec_total = hex + dec_total; //adding all convertions to a different intiger that in the end hold the converted number.
		power--; //decreasing the power after every letter.
	}
	if (fal != 99) //if fal is set to 99 it means the user had typed illegal characters.
		printf("\nThe decimal number is:%d\n", dec_total);
	else
		printf("\nIllegal input!\n");

}