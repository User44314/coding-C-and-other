#include <stdio.h>
int main() /* count digits, white space, others */
{
    int c, i, nwhite, nother, ndigit[10]; // c is an integer, i is an integer
    // nwhite is an integer, nother is an integer, ndigit is an array of size 10
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0; // ndigit is an array of size 10
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ndigit[c - '0']++; // c - '0' is used to convert character to integer
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]); // %d is used to print integer values
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}
// Output: digits = 0 0 0 0 0 0 0 0 0 0, white space = 0, other = 0
// Explanation: The program counts the number of digits, white spaces, and other characters in the input. Since there is no input provided in the code, the initial values of ndigit, nwhite, and nother are all 0. Therefore, the output will show that there are 0 occurrences of digits, white spaces, and other characters.