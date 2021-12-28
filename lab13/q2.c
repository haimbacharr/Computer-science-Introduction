#include<stdio.h>
#include <conio.h>
unsigned build(unsigned num, unsigned mask);
void main()
//Function name:main
//Input:2 numbers
//Output: print new number with the legality of mask
//Algorithm: while loop and calling to recrusive function
{
	int flag = 0;
	unsigned int num, mask;
	while (flag < 4)
	{
		printf("Give us the number and the mask?:");
		scanf("%u%u", &num, &mask);
		printf("after applaying mask %u onto %u we got %u\n", mask, num, build(num, mask));
		flag++;
	}
	getch();
}
unsigned build(unsigned num, unsigned mask)
//Function name:build
//Input:2 unsigned numbers
//Output: new number with the legality of mask
//Algorithm: recrisive function
{
	if (num == 0 || mask == 0)return 0;//if the mask or the num are 0 return 0
	else
		return 10 * build(num / 10, mask / 10) + (num % 10 * mask % 10);
	//we multiplay the number from the recrisive function and the unit digit will be as the leality of the mask- in case of 1 we get the number that shown in num in case of 0 we get 0

}
