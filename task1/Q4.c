#include<stdio.h>
/*
The program ask the user to insert the date of today, or any day that he knows what is the equivalent day in the week.
Then the program will ask the user to insert his Birthday date <day and month>.
The program will calculate in which day in the week is upcoming birthday.
*/
 void main()
{
	int day, month, week, bd_day, bd_month, year = 2019, i;
	printf("Please enter the current date(date-month-day of the week) repectievly:");
	scanf("%d%d%d", &day, &month, &week);
	if (day > 31 || day < 1 || month < 1 || month >12 || week < 1 || week>7)//check if the numbers are correct.
	{
		printf("Illegal numbers!");
	}
	else
	{
		printf("Please enter your birthday date and month:");
		scanf("%d%d", &bd_day, &bd_month);
		if (bd_day > 32 || bd_day < 1 || bd_month> 13 || bd_month < 1)
		{
			printf("Illegal numbers!");
		}
		else
		{
			//check if upcoming birthday is on the same here
			if (bd_month > month)
			{
				for (i = month; i < bd_month; i++)
				{
					switch (i)
					{
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						while (day <= 31)
						{
							if (week < 7)
							{
								week++;
							}
							else
							{
								week = 1;
							}
							day++;
						}
						day = 1;
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						while (day <= 30)
						{
							day++;
							if (week < 7)
							{
								week++;
							}
							else
							{
								week = 1;
							}
						}
						day = 1;
						break;
					case 2:
						if (year % 4 == 0)
						{
							while (day <= 29)
							{
								day++;
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
							}
							day = 1;
						}
						else
						{
							while (day <= 28)
							{
								day++;
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
							}
							day = 1;
						}
						break;
					}
				}
				for (i = day; i < bd_day; i++)
				{
					day++;
					if (week < 7)
					{
						week++;
					}
					else
					{
						week = 1;
					}
				}
			}
			else
			{
				//checks if the birthday is on the same year and month
				if (bd_month == month && bd_day > day)
				{
					for (i = day; i < bd_day; i++)
					{
						day++;
						if (week < 7)
						{
							week++;
						}
						else
						{
							week = 1;
						}
					}
				}
				//checks if the birthday is in the upcoming year.
				else
				{
					for (i = month; i <= 12; i++)
					{
						switch (i)
						{
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							while (day <= 31)
							{
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
								day++;
							}
							if (i == 12)
							{
								month = 1;
							}
							day = 1;
							break;
						case 4:
						case 6:
						case 9:
						case 11:
							while (day <= 30)
							{
								day++;
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
							}
							day = 1;
							break;
						case 2:
							if (year % 4 == 0)
							{
								while (day <= 29)
								{
									day++;
									if (week < 7)
									{
										week++;
									}
									else
									{
										week = 1;
									}
								}
								day = 1;
							}
							else
							{
								while (day <= 28)
								{
									day++;
									if (week < 7)
									{
										week++;
									}
									else
									{
										week = 1;
									}
								}
								day = 1;
							}
							break;
						}
					}
					year++;
					for (i = month; i < bd_month; i++)
					{
						switch (i)
						{
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							while (day <= 31)
							{
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
								day++;
							}
							day = 1;
							break;
						case 4:
						case 6:
						case 9:
						case 11:
							while (day <= 30)
							{
								day++;
								if (week < 7)
								{
									week++;
								}
								else
								{
									week = 1;
								}
							}
							day = 1;
							break;
						case 2:
							if (year % 4 == 0)
							{
								while (day <= 29)
								{
									day++;
									if (week < 7)
									{
										week++;
									}
									else
									{
										week = 1;
									}
								}
								day = 1;
							}
							else
							{
								while (day <= 28)
								{
									day++;
									if (week < 7)
									{
										week++;
									}
									else
									{
										week = 1;
									}
								}
								day = 1;
							}
							break;
						}
					}
					for (i = day; i < bd_day; i++)
					{
						day++;
						if (week < 7)
						{
							week++;
						}
						else
						{
							week = 1;
						}
					}
				}
			}

			printf("The day in the week is:%d", week);
		}
	}
}
