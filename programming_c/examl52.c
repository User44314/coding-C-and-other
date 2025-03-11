#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

int main(void)
{
    int n = -234567890;
    printd(n);
    putchar('\n');
    return 0;
}
// Output: -12345678901