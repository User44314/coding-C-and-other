#include <stdio.h> //include information about standard

int main()
{
    /* count lines in input */
    int c1, nl;
    nl = 0;
    while ((c1 = getchar()) != EOF)
        if (c1 == '\n')
            ++nl;
    printf("%d\n", nl);
}
