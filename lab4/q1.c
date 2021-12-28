#include<stdio.h>
#include<math.h>	
void main()
{
	double BMI;
	int kg, h;
	printf("Please enter weight(kg) and height (in cm),respectively:");
	scanf("%d%d", &kg, &h);
	BMI = (kg / pow(h * 0.01, 2));
	if (BMI < 18.5)
	{
		printf("\n Underweight");
	}
	else
	if ( 18.5<= BMI && BMI < 25)
		{
			printf("\n Noraml weight");
		}
	else 
	if (25 <= BMI && BMI < 30)
	{
		printf("\n increased weight");
	}
	else 
	if (30 <= BMI && BMI < 40)
	{
		printf("\n Obese");
	}
	else
	if (40 <= BMI)
	{
		printf("\n Very high obese");
	}
}
