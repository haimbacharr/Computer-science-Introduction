#include<stdio.h>
#include<math.h>	
void main()
{
	int n1, n2;
	printf("Enter 2 integers,please:");
	scanf("%d%d", &n1, &n2);
	printf("\n%d and %d are opposite numbers <1 for true,0 for false>:%d", n1, n2, n1 + n2 == 0);
}
