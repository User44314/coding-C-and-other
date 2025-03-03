#include <stdio.h>
#include <string.h>
/* reverse: reverse string s in place */
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
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s);
    return 0;
}