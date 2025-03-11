#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void reverse(char[], int, int); // function prototype

int main(void)
{
  char s[] = "hello";             // example string
  reverse(s, 0, (strlen(s) - 1)); // reverse the complete word
  printf("%s\n", s);
  return 0;
}

void reverse(char s[], int l, int r) 
{ // reverse from l(left) to r(right) in array s
  int c; // временная переменная для хранения символа, который нужно заменить
  if (l < r)
  {
    reverse(s, l + 1, r - 1);
    c = s[l];
    s[l] = s[r];
    s[r] = c;
  }
}