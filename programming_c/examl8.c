/* Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXIMUM 1000

int getLine(char s[], int lim);
void removeBlanks(char s[], int len);

int main()
{
    int len;
    char line[MAXIMUM];
    while ((len = getLine(line, MAXIMUM)) > 0)
    {
        removeBlanks(line, len);
        printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void removeBlanks(char s[], int len)
{
    for (int i = 0; i <= len; i++)
    {
        if (s[i] == ' ' || s[i] == '\t')
            s[i] = '\b';
        else
            i = len + 1;
    }
}