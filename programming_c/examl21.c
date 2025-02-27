 /* Write a function setbits(x,p,n,y) that returs x with the n bits that begin at position p set
to the rightmost n bits of y, leaving the other bits unchanged. */

#include<stdio.h>

unsigned setbits(unsigned x,int p, int n,int y);
void printBinary(int num);

int main(){
    unsigned x = 127;
    unsigned test = setbits(x, 5, 3,12); // 127 & ((12 << 3) | ~(~7 << 3)) 

    printBinary(x); // 127
    printBinary(12); // 12
    printBinary(test); // 220 = 127 + 93 // 93 = 12 *8 - 3 = 96 - 3 = 93
    return 0;
}

unsigned setbits(unsigned x,int p, int n,int y){
    return (x & ((y<<(p+1-n)) | ~(~(~0<<n)<<(p+1-n))));  // 127 & ((12 << (5+1-3)) | ~(~(~0 << 3) << (5+1-3)))
    // 127 & ((12 << 3) | ~(~(~0 << 3) << 3)) 
    // 127 & ((12 << 3) | ~(~7 << 3)) 
    // 127 & ((12 << 3) | ~(~7 << 3)) 
}

void printBinary(int num)
{
    int size = sizeof(num) * 8; // Total bits in a number = size of integer * 8 bits per byte (1 byte = 8 bits)
    for (int i = size - 1; i >= 0; i--)
    {
        int bit = (num >> i) & 1; // Shift the number 'num' by 'i' bits to the right and perform bitwise AND with 1
        printf("%d", bit);
    }
    printf("\n");
}

// Output:
// 00000000000000000000000001111111 // 127
// 00000000000000000000000000001100 // 12
// 00000000000000000000000001101100 // 220