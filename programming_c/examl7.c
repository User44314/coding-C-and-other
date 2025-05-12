#include <stdio.h>
/* Write a program to print all input lines that are longer than 80 characters */
#define MAXLINE 1000 /* maximum input line length */
#define MINLINE 80
int my_getline(char line[], int maxline);


/* print the longest input line */
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > MINLINE)
        {
            printf("%s\n", line);
        }
    return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')  //new line character
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; // null character to end the string
    return i;
}

