#include <stdio.h>
#include <string.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // non-leap year
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; // leap year

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap; // leap year
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
		
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		
	for (i = 1; yearday > daytab[leap][i]; i++) // find month
		yearday -= daytab[leap][i];				// subtract days in month
	*pmonth = i;								// set month
	*pday = yearday;							// set day
}

int main(void)
{
	int day, month, year, yearday;
	year = 2021;
	month = 2;
	day = 28;
	yearday = day_of_year(year, month, day);
	printf("day of year: %d\n", yearday);
	month_day(year, yearday, &month, &day);
	printf("month: %d, day: %d\n", month, day);
	return 0;
}
