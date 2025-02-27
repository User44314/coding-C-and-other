 /* Write a function invert (x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 change to 0 and vice versa), leaving the others unchanged */
#include<stdio.h>

unsigned invert(int x, int p, int n);
void printBinary(int n);

int main(){
    int test = 85;
    printBinary(test); // 85 = 00000000000000000000000001010101 
    printBinary(invert(test,4,3)); // 42 = 00000000000000000000000000101010  85 & 42 = 42
    return 0;
}

unsigned invert(int x, int p, int n){
    int h = ~(~(~0<<n)<<(p+1-n)); // ~(~(~0<<3)<<(4+1-3)) = ~(~7<<1)<<3 = ~(~7<<1)<<3 = ~(~14)<<3 = ~13<<3 = -14<<3 = -112
    return (x&h)|(~x&~h); // 85 & -112 | ~85 & 112 = 42
}

void printBinary(int n){
    int h = sizeof(n) * 8; // 32 bits
    for (int i = h-1; i >= 0; i--) // 31 to 0
    {
        int curBit = (n >> i) & 1; // 85 >> 31 & 1 = 0
        printf("%d",curBit); // 0
    }
    printf("\n");
}
// Output:
// 00000000000000000000000001010101 // 85
// 00000000000000000000000000101010 // 42   85 & 42 = 42
