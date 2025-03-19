/* Exercise 2-2 discusses a for loop from the text. Here it is:

  for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
Write a loop equivalent to the for loop above without using && or || . */

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_STRING_LENGTH 100
/* atoi: convert s to integer */
int my_atoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
}

int main(void)
{
  /*
  for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
  */

  int i = 0, lim = MAX_STRING_LENGTH, c;
  char s[MAX_STRING_LENGTH];

  while (i < (lim - 1))
  {
    c = getchar();

    if (c == EOF)
      break;
    else if (c == '\n')
      break;

    s[i++] = c;
  }

  s[i] = '\0'; /* terminate the string */

  printf("The string is: %s\n", s);
  int a = my_atoi(s);
  printf("The integer is: %d\n", a); 
  
  double xx = 2.2;
  sqrt((double) xx);
  printf("The square root of %f is %f\n", xx, sqrt((double) xx));
  return 0;
}