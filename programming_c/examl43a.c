
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <stdio.h>


double atof(char s[]);

int main(void)
{
    printf("%f\n", atof("123.45e-6"));
}

double atof(char s[])
{
    double val, power, base, p; // val is the integer part of the number, power is the fractional part of the number 
    int i, sign, exp; // i is the index of the string, sign is the sign of the number, exp is the exponent of the number

    for (i = 0; isspace(s[i]); i++) // skip white space
        ; 

    sign = (s[i] == '-') ? -1 : 1; // determine the sign of the number

    if (s[i] == '-' || s[i] == '+')
        ++i;

    for (val = 0.0; isdigit(s[i]); i++) // integer part of the number
        val = 10.0 * val + (s[i] - '0'); // convert the string to a number

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) // fractional part of the number
    {
        val = 10.0 * val + (s[i] - '0'); // convert the string to a number
        power *= 10.0; // calculate the power of 10
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    else
        return sign * val / power; // return the number if there is no exponent
    
    base = (s[i] == '-') ? 0.1 : 10.0; // determine the base of the exponent (10^(-n) or 10^n)
    i++; // 10^(-n) = 1/10^n = (1/10)^n = (0.1)^n

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exp = 0; isdigit(s[i]); i++) // exponent of the number
        exp = 10 * exp + (s[i] - '0'); // convert the string to a number
        
    for (p = 1; exp > 0; --exp) // calculate the exponent
        p = p * base; // calculate the exponent

    return (sign * (val / power)) * p; // return the number with the exponent
}