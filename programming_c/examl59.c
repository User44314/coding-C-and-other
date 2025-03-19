#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getfloat(float *fp) // get next float from input into *fp
{
  int ch; // character read from input .
  int sign;   // sign of the number
  int fraction; // fraction part of the number
  int digits; // number of digits read so far 

  while (isspace(ch = getch())) /* skip white space */
    ;

  if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.')
  {
    ungetch(ch); /* it's not a number */
    return 0;
  }

  sign = (ch == '-') ? -1 : 1;

  if (ch == '+' || ch == '-')
  {
    ch = getch();
    if (!isdigit(ch) && ch != '.')
    {
      if (ch == EOF)
      {
        return EOF;
      }
      else
      {
        ungetch(ch); /* it's not a number */
        return 0;
      }
    }
  }

  *fp = 0; // reset the float
  fraction = 0; // reset the fraction part
  digits = 0; // reset the number of digits
  for (; isdigit(ch) || ch == '.'; ch = getch()) // read the number
  {
    if (ch == '.') // check if the number has a fraction part
    {
      fraction = 1;
    }
    else
    {
      if (!fraction)
      {
        *fp = 10 * *fp + (ch - '0'); // integer part
      }
      else
      {
        *fp = *fp + ((ch - '0') / pow(10, fraction)); // fraction part 
        fraction++;
      }
      digits++;
    }
  }

  *fp *= sign;

  if (ch == EOF)
  {
    return EOF;
  }
  else
  {
    ungetch(ch);
    return (digits) ? ch : 0;
  }
}

int main(void)
{
  int ret; // return value
  do
  {
    float f; // float number
    fputs("Enter a number: ", stdout);
    fflush(stdout);
    ret = getfloat(&f);
    if (ret > 0)
    {
      printf("You entered: %f\n", f);
    }
  } while (ret > 0);

  if (ret == EOF)
  {
    puts("Stopped by EOF.");
  }
  else
  {
    puts("Stopped by bad input.");
  }

  return 0;
}