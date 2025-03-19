#include <stdio.h>
#include <ctype.h>
/* atoi: convert s to integer; version 2 */
int my_atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1; // if s[i] is '-' then sign = -1 else sign = 1 
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++) // isdigit() returns non-zero if s[i] is a digit
        n = 10 * n + (s[i] - '0'); // '0' is 48 in ASCII
    return sign * n; // return the integer
}
int main()
{
    char s[] = "  -123";
    printf("%d\n", my_atoi(s));
    return 0;
}
// Output: -123