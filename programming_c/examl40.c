/* Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);        // function prototype
int strindex(char source[], char searchfor[]); // function prototype
char pattern[] = "long";                       // pattern to search for

int getline(char s[], int lim) // this function is similar to the getline() function in the stdio.h library
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
} 
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])// this function is similar to the strstr() function in the string.h library
{
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        for (j = 0; s[i + j] == t[j] && t[j]; j++);
		if (!t[j])
			return i;
    }
    return -1;
}

/* find all lines matching pattern */
int main()
{
    //printf("%d\n", strindex("I stopped dreaming a long long time ago", "long"));  1-st test
	//return 0;
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
        {
            printf("%d\n", strindex(line, pattern));

        }
    return 0;
}