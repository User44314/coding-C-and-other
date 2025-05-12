/* bases.c — распечатывает число 100 в десятичной, восьмеричной
и шестнадцатеричной системах счисления */
#include <stdio.h>
int main(void)
{
	int x = 100;
	printf("Decimal = %d; Octal = %o; Hexadecimal = %x\n", x, x, x);
	printf("Decimal = %d; Octal = %#o; Hexadecimal = %#x\n", x, x, x);
	return 0;
}
