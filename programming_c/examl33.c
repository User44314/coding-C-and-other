/* Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the
equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared
to handle case like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally. */

#include <stdio.h>
#include <string.h>

#define MAXIMUM 1000

void expand(char s1[], char s2[]); // function prototype

int main()
{
    char s1[MAXIMUM] = "-0-9 What the -A-F-S-Z The hell, R-W, W-Z , -a-z , 0-9";
    char s2[MAXIMUM];
    printf("%s\n", s1);
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, c, t = 0; // c is a temporary variable
    for (i = 0; i < strlen(s1); i++) // strlen() returns the length of the string
    {
        c = s1[i + 2];  // c is the character after the '-' character in s1; '-' is 45 in ASCII
        if ((s1[i] >= 'A' && s1[i + 1] == '-' && s1[i + 2] <= 'Z') || (s1[i] >= 'a' && s1[i + 1] == '-' && s1[i + 2] <= 'z') || (s1[i] >= '0' && s1[i + 1] == '-' && s1[i + 2] <= '9')) // if s1[i] is a letter or a digit and s1[i + 1] is '-' and s1[i + 2] is a letter or a digit then
        {
            for (j = s1[i]; j <= c - 1; j++) // j is the character between s1[i] and c
            {
                s2[t] = j; // add the characters between s1[i] and c to s2
                t++;
            }
            s1[i + 1] = '\a'; // replace '-' with '\a' to avoid adding the characters between s1[i] and c again
        }
        else
        {
            s2[t] = s1[i]; // add s1[i] to s2
            t++; // increment t
        }
    }
    s2[t] = '\0'; // add the null character to the end of s2
}

// Output: -0-9 What the -A-F-S-Z The hell, R-W, W-Z , -a-z , 0123456789
// The output is correct

