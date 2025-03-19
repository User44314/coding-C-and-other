#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 10 // size of the array
#define BUFSIZE 100 // buffer for ungetch function
char buf[BUFSIZE]; // buffer for ungetch
int sp = 0; // next free stack position

int getch1(void);
void ungetch(int);

/* getint:  get next integer from input into *pn
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 */
int getint(int *pn)
{
  int c, sign, sawsign; // sign is +1 or -1 for the number sign 0 for no sign and sawsign is 1 if we saw a sign

  while (isspace(c = getch1())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1; // save sign

  if (sawsign = (c == '+' || c == '-')) // if we saw a sign
    c = getch1();
  if (!isdigit(c))
  {
    ungetch(c);
    if (sawsign)
      ungetch((sign == -1) ? '-' : '+');
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch1())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getch1() // get a (possibly pushed back) character
{
  return (sp > 0) ? buf[--sp] : getchar();
}
void ungetch(int s) // push character back on input
{
  buf[sp++] = s;
}

int main()
{
  int n, array[SIZE], getint(int *);
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
  for (n = 0; n < SIZE; n++)
    printf("array[%d]=%d\n", n, array[n]);
  return 0;
}