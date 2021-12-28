#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	int day, month, year, switch1;//Variables declaration(first visit).
	int visit_day;//Next day of visit.
	printf("Enter the date of your first visit:");
	scanf_s("%d%d%d", &day, &month, &year);
	if (((day > 0 && day <= 31) && (month > 0 && month <= 12) && (year == 2018)))//Check if date is correct
	{
		if ((!(day > 28) && (month == 2)) || (!(day > 30) && ((month == 4) || (month == 6) || (month == 9) || (month == 11))))//Check if the number of days in a month  is correct.
		{
			switch (month)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12://If the month have 31 days,calculate when the next visit day.
				if (day > 17) {
					visit_day = (day + 14) - 31;
					month++;
				}
				else
					visit_day = day + 14;
				break;
			case 2://If the month have 28 days, calculate when the next visit day.
				if (day >= 15) {
					visit_day = (day + 14) - 28;
					month++;
				}
				else
					visit_day = day + 14;
				break;
			case 4:case 6:case 9:case 11://If the month have 30 days,calculate the visit day.
				if (day >= 17) {
					visit_day = (day + 14) - 30;
					month++;
				}
				else
					visit_day = day + 14;
				break;
			default:;
			}
			printf("Your next visit is at: %02d %02d %04d\n", visit_day, month, year);//Printing the next visit.
		}
		else
			printf("Date is incorrect\n ");//in case of incorrect day/month/year.
	}
	else
		printf("Date is incorrect\n ");//in case of incorrect day in month/
	_getch();
	return 0;
}