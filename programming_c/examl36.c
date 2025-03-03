/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
In particular, itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b); // n = number, s = string, b = base
void reverse(char s[]);

#define MAXIMUM 50

int main()
{
    int b = 16;
    char s[MAXIMUM];
    itob(123456, s, b);
    printf("Base %d = %s\n", b, s);
    return 0;
}

void itob(int n, char s[], int b) // n = number, s = string, b = base
{
    int i = 0;
    do
    {
        if (n % b > 9) 
            s[i++] = n % b + 'A' - 10; // for hexadecimal
        else
            s[i++] = n % b + '0'; // for decimal
    } while ((n /= b)); // n = n/b 
    reverse(s);
}

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}