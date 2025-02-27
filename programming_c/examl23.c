/* Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit position. */

#include <stdio.h>

// Function prototype for rightrot
unsigned rightrot(unsigned x, int n);
// Function prototype for printing integers in binary form
void print_binary(unsigned x);

// Main Function
int main()
{
    print_binary(245);
    print_binary(rightrot(245, 5));
    return 0;
}

// Function that rotates x to the right by n bit position.
unsigned rightrot(unsigned x, int n)
{
    return (x >> n) | ((x & ~(~0 << n)) << (sizeof(x) * 8 - n)); // (x >> n) | ((x & ~(~0 << n)) << (sizeof(x) * 8 - n))
    // (245 >> 5) | ((245 & ~(~0 << 5)) << (4 * 8 - 5))
    // 7 | (5 << 27)
    // 7 | 1342177280
    // 1342177287
}

// Function to print binary of unsigned integer
void print_binary(unsigned x) // 245
{
    int n = sizeof(x) * 8; // 32 bits
    for (int i = n - 1; i >= 0; i--)
    {
        int curBit = (x >> i) & 1; // 245 >> 31 & 1 = 0
        printf("%d", curBit);
    }
    printf("\n");
}

// Output:
// 00000000000000000000000011110101 // 245
// 10100000000000000000000000000111 // 1342177287