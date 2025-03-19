#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* strcpy: copy t to s; array subscript version */
void strcpy1(char *s, char *t)
{
  int i;
  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy: copy t to s; pointer version */
void strcpy2(char *s, char *t)
{
  int i;
  i = 0;
  while ((*s = *t) != '\0')
  {
    s++;
    t++;
  }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy3(char *s, char *t)
{
  while ((*s++ = *t++) != '\0') // copy t to s; pointer version 2 while (*s++ = *t++)
    ;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t)
{
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp2(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int main()
{
  char s[100];
  char *t = "hello, world";
  strcpy1(s, t);
  printf("s1=%s\n", s);
  strcpy2(s, t);
  printf("s2=%s\n", s);
  strcpy3(s, t);
  printf("s3=%s\n", s);
  printf("strcmp1=%d\n", strcmp1("hello", "hello"));
  printf("strcmp1=%d\n", strcmp1("hello", "hello, world"));
  printf("strcmp1=%d\n", strcmp1("hello, world", "hello"));
  printf("strcmp2=%d\n", strcmp2("hello", "hello"));
  printf("strcmp2=%d\n", strcmp2("hello", "hello, world"));
  return 0;
}