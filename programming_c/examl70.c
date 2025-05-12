#include <stdio.h>
#include <string.h>

/* month_name: return name of n-th month */
char *month_name(int n)
{
	
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"};
	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main()
{
	int n;
	printf("Enter month number: ");
	scanf("%d", &n);
	printf("Month name: %s\n", month_name(n));
	return 0;
}