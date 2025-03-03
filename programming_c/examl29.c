/* Write a function escape(s,t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the string t to s.
Use a switch. Write a function for the other direction as well, converting esacpe sequences into the real characters. */

#include <stdio.h>

#define MAXIMUM 1000

int main()
{
    int c, i = 0;
    char s[MAXIMUM];
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\n':
            printf("\\n");
            break;
        case '\t':
            printf("\\t");
            break;
        default:
            putchar(c);
            break;
        }
        s[i] = c;
        i++;
    }
    printf("\n%s\n", s);
    return 0;
}