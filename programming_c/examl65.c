#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* Упражнение 5-5. Напишите версии библиотечных функций strncpy,
strncat и strncmp, которые
обрабатывают не более первых n символов своих строк аргументов.
Например, strncpy(s,t,n) копирует не более n символов t в s.
Полные описания приведены в Приложении B. */

#include <stdio.h>
#include <string.h>
#define SIZE 100
char *my_strncpy(char *s, char *t, unsigned int n);
char *my_strncat(char *s, char *t, unsigned int n);
int my_strncmp(char *s, char *t, unsigned int n);

int main()
{
  char s[SIZE] = "Aomine Daiki", t[SIZE] = "Kise Ryota";
  char *ps = "Aomine Daiki", *pt = "Kise Ryota";
  printf("my_strncmp(%s, %s, %d) = %d\n", ps, pt, 10, my_strncmp(s, t, 10));
  printf("my_strncat(%s, %s, %d) = %s\n", ps, pt, 8, my_strncat(s, t, 8));
  printf("my_strncpy(%s, %s, %d) = %s\n", ps, pt, 5, my_strncpy(s, t, 6));
  return 0;
}

// Function description: http://www.cplusplus.com/reference/cstring/strncpy/
char *my_strncpy(char *s, char *t, unsigned int n)
{
  int i, tlen = strlen(t);
  for (i = 0; i < n; i++)
  {
    if (i < tlen)
      s[i] = t[i];
    else
      s[i] = 0;
  }
  s[i] = 0;
  return s;
}

// Function description: http://www.cplusplus.com/reference/cstring/strncat/
char *my_strncat(char *s, char *t, unsigned int n)
{
  int i, tlen = strlen(t), slen = strlen(s); 
  for (i = 0; i < n; i++)
  {
    if (i < tlen)
      s[slen + i] = t[i];
    else
      break;
  }
  s[slen + i] = '\0';
  return s;
}

// Function description: http://www.cplusplus.com/reference/cstring/strncmp/
int my_strncmp(char *s, char *t, unsigned int n)
{
  int i;
  for (i = 0; i < n; i++)
    if (s[i] != t[i] || s[i] == 0 || t[i] == 0)
      return s[i] - t[i]; // if s[i] != t[i] then return the difference between the two characters at position i in s and t respectively.
  return 0;
}