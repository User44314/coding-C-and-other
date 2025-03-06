#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* atof: convert string s to double */
double my_atof(char s[])
{
    double val, power; // val is the integer part of the number, power is the fractional part of the number
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1; // determine the sign of the number

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++) // integer part of the number 
        val = 10.0 * val + (s[i] - '0'); // convert the string to a number
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) // fractional part of the number
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int main()
{
    double sum, my_atof(char []);
    char s[] = "123.45";
    printf("%f\n", my_atof(s));
    return 0;
}

// Output:
// 123.450000 
// Explanation:
// The function my_atof() converts a string of digits to a floating-point number. The function uses two variables, val and power, to store the integer and fractional parts of the number, respectively. The function iterates over the string, converting each digit to a number and updating the val and power variables accordingly. Finally, the function returns the floating-point number by dividing the integer part by the power of 10.

/* (s[i] - '0') -> Это потому, что значение внутри s[i] является charтипом.
Чтобы преобразовать символ «1» в целое число, нужно выполнить операцию «1» - «0», чтобы получить 1. Это определяется позицией в таблице ASCII, 
символ «0» имеет код 48, а символ «1» — код 49. */