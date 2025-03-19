#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* Упражнение 5-4. Напишите функцию strend(s,t), которая возвращает 1,
если строка t встречается в конце строки s, и ноль в противном случае. */

int strlen1(char *s) /* added by RJH; source: K&R p99 */
{
  int n;

  for (n = 0; *s != '\0'; s++)
  {
    n++;
  }
  return n;
}

int strcmp1(char *s, char *t) /* added by RJH; source: K&R p106 */
{
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int strend1(char *s, char *t)
{
  int Result = 0;
  int s_length = 0;
  int t_length = 0;

  /* get the lengths of the strings */
  s_length = strlen1(s);
  t_length = strlen1(t);

  /* check if the lengths mean that the string t could fit at the string s */
  if (t_length <= s_length)
  {
    /* advance the s pointer to where the string t would have to start in string s */
    s += s_length - t_length;

    /* and make the compare using strcmp */
    if (0 == strcmp1(s, t))
    {
      Result = 1;
    }
  }

  return Result;
}

int main(void)
{
  char *s1 = "some really long string.";
  char *s2 = "ng.";
  char *s3 = "ng";

  if (strend1(s1, s2))
  {
    printf("The string (%s) has (%s) at the end.\n", s1, s2);
  }
  else
  {
    printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
  }
  if (strend1(s1, s3))
  {
    printf("The string (%s) has (%s) at the end.\n", s1, s3);
  }
  else
  {
    printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
  }

  return 0;
}