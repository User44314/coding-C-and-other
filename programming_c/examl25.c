/* Rewrite the function lower, which convers upper case letters to lower case,
with a conditional expression instead of if-else. */
#include <stdio.h>

// Function prototype of lower
int lower(int c);

int main()
{
    // Test lower function
    int c = 'Q'; // ASCII value of Q is 81
    printf("%c", lower(c)); // q 
    return 0;
}

// Function that converts UPPER case character to lower case character
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c; // 81 >= 65 && 81 <= 90 ? 81 += 97 - 65 : 81
}