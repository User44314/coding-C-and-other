#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* strlen: return length of string s */
int my_strlen(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

/* strlen: return length of string s */
int strlen1(char *s)
{
  char *p = s; // p is a pointer to the first element of the array s
  while (*p != '\0')
    p++;
  return p - s; // p - s is the number of elements between p and s
  // p - s is the number of elements between p and s, which is the same as the number of elements between the first element of the array s and the first element of the array p. Since p is pointing to the first element of the array s, p - s is the number of elements in the array s.
}

int main()
{
  int a[10];
  int *pa;
  pa = &a[0];
  int x = *pa; // will copy the contents of a[0] into x.
  printf("x=%d\n", x);
  my_strlen("hello, world"); // will return 12
  printf("my_strlen=%d\n", my_strlen("hello, world"));

  strlen1("hello, world"); // will return 12
  printf("strlen1=%d\n", strlen1("hello, world"));
  return 0;
}