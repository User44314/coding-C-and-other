// Compiler: This project uses the GCC compiler.
// Compiler version: This project uses GCC version 10.2.0.
#include <stdio.h>


int square(int x) {
    return x * x;
}

int apply(int x, int (*pf)(int)) {
    return pf(x);
}

int main(void) {
    int x = 5;
    int result = apply(x, square);
    printf("The square of %d is %d\n", x, result);
    return 0;
}

