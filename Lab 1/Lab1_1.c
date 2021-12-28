#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int main()
{
   int i, Arr[SIZE]={3,5,10,1,2,7,6,9,0,8};
   int **parr;
   parr = (int**)malloc(SIZE * sizeof(int*));
   if (parr == SIZE)
   {
	   parr = Arr;
   }
   else
   {
	   printf("allocation faild");
	   free(arr);
   }
   printf("my array is:");
   for (i = size;i >= 0;parr--)
   {
	   printf("%d ", parr[i]);
   }
   return 0;
}

