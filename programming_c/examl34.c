#include <stdio.h>
#include <string.h>
/* itoa: convert n to characters in s */
void itoa(int n, char s[]);
/* reverse: reverse string s in place */
void reverse(char s[]);
 
void itoa(int n, char s[])
{
    int i, sign; // sign is used to record the sign of the number
    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    do
    {                          /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j; // c is a temporary variable
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) // strlen() returns the length of the string
    {
        c = s[i]; // swap s[i] and s[j]
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    int n = -123;
    char s[100];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}