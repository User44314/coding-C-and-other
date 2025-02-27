/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why.
Use this observation to write a faster version of bitcount. */

#include <stdio.h>

// Function prototype for bitcount
int bitcount(int x);
// Function prototype to print binary of a given integer
void print_binary(unsigned x);

int main()
{
    int test = 102; // 102 = 00000000000000000000000001100110
    print_binary(test); // 102 = 00000000000000000000000001100110
    printf("%d\n", bitcount(test)); // 4
    return 0;
}

// Function that counts the number of 1-bit in the given integer
int bitcount(int x)
{
    int i;
    for (i = 0; x != 0; x &= (x - 1)) // 102 & 101 = 102 & 100 = 100 & 011 = 0
        i++;
    return i;
}

// Function that prints binary of a given integer
void print_binary(unsigned x)
{
    int n = sizeof(x) * 8; // 32 bits for integer x // 102 * 8 = 32
    // 102 = 00000000000000000000000001100110
    for (int i = n - 1; i >= 0; i--)
    {
        int curr_bit = (x >> i) & 1; // 102 >> 31 & 1 = 0 & 1 = 0
        printf("%d", curr_bit);
    }
    printf("\n");
}