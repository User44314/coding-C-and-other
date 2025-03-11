#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int real_itoa(int n, char s[], int base, int p) 
{
    int d = n % base; // remainder остаток
    int r = n / base; // quotient частное
    if (n < 0)
    {
        d = -d;
        r = -r;
    }
    if (r) // if r != 0
        p = real_itoa(r, s, base, p); // recursion call real_itoa with r and p as arguments and assign the result to p 
    s[p++] = "0123456789abcdefghijklmnopqrstuvwxyz"[d]; // 0-9 a-z
    return p; // return p + 1
}

void my_itoa(int n, char s[], int base) // convert n to characters in s
{
    int p = 0; // position in s array 
    if (n < 0)
        s[p++] = '-';
    s[real_itoa(n, s, base, p)] = 0;
}


int main()
{
    char s[100];
    my_itoa(123, s, 10);
    printf("%s\n", s);
    my_itoa(123, s, 16);
    printf("%s\n", s);
    my_itoa(123, s, 8);
    printf("%s\n", s);
    my_itoa(123, s, 2);
    printf("%s\n", s);
    my_itoa(-123, s, 10);
    printf("%s\n", s);
    my_itoa(-123, s, 16);
    printf("%s\n", s);
    my_itoa(-123, s, 8);
    printf("%s\n", s);
    my_itoa(-123, s, 2);
    printf("%s\n", s);
    return 0;
}


/* char *itoa(int n, char s[], int base)
{
  int d = n % base;
  int r = n / base;
  if (n < 0) {
    *s++ = '-';
    d = -d;
    r = -r;
  }
  if (r)
    s = itoa(r, s, base);
  *s++ = "0123456789abcdefghijklmnopqrstuvwxyz"[d];
  *s = 0;
  return s;
} */


// Output:
// 123