 /* Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverse its input a line at a time. */

#include <stdio.h>
#define MAXIMUM 1000

int getLine(char s[], int lim);
void reverse(char s[], int len);

int main()
{
    int len;
    char line[MAXIMUM];
    while ((len = getLine(line, MAXIMUM)) > 0)
    {
        reverse(line, len);
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

void reverse(char s[], int len)
{
    char temp;
    for (int i = 0; i < len / 2; i++) //reverse the string by swapping the characters from the start and end of the string 
    {
        temp = s[i]; //swap the characters
        s[i] = s[len - i - 1]; 
        s[len - i - 1] = temp; 
    }
}