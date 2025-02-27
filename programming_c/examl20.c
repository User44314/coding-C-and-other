/* Write the function any (s1, s2), which returns the first location in the string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the locaiton.) */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello I'm a programmer";
    printf("%d\n", any(s1, "ammer")); // 10  a a m m m e e r r r 
    strpbrk(s1, "ello"); // ello I'm a programmer
    printf("%s\n", strpbrk(s1, "ello"));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = 0; s1[j] != '\0'; j++)
            if (s1[j] == s2[i])
                return j;
    }

    return -1;
}

 

/* int any(char s1[], char s2[])
{
    int i, j;
    int ret = -1;
    for (j = 0; s2[j] != '\0'; j++)
        for (i = 0; s1[i] != '\0'; i++)
            if (s1[i] == s2[j])
                if (ret < 0)
                    ret = i;
                else if (i < ret)
                    ret = i;
    return ret;
} */