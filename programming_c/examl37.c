/* Write a version of itoa that accepts three arguments instead of two.
The third argument is a minimum field width; the converted number must be padded with
blanks on the left if necessary to make it wide enough. */
#include <stdio.h>
#include <string.h>

#define MAXIMUM 50

void my_itoa(int n, char s[], int width); // n = number, s = string, width = minimum field width
void reverse(char s[]);

int main()
{
    char s[MAXIMUM];
    int n = -123456;
    int width = 15;
    my_itoa(n, s, width);
    printf("%s\n", s);
    return 0;
}

void my_itoa(int n, char s[], int width)
{
    int i = 0, sign, gap; // gap = difference between width and strlen(s)
    if ((sign = n) < 0) // record sign
        n = -n; // make n positive
    do
    {
        s[i++] = n % 10 + '0'; // get next digit
    } while (n /= 10); // delete it 
    if (sign < 0) // if negative
        s[i++] = '-'; // add sign
    gap = width - strlen(s); // calculate gap
    if (gap > 0) // if gap is positive
        while (gap > 0) // add spaces
        {
            s[i++] = ' '; // add space
            gap--;      // decrement gap
        }
    else
    {
        while (gap < 0) // if gap is negative
        {
            i--; // decrement i
            s[i] = '\b'; // remove space
            gap++; // increment gap
        }
    }
    reverse(s);
}

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}