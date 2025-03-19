#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 10 // size of the array
#define BUFSIZE 100 // buffer for ungetch function
char buf[BUFSIZE]; // buffer for ungetch
int sp = 0; // next free stack position
int getch1(void); // get a (possibly pushed back) character
void ungetch(int); // push character back on input
// 1. Write a function that takes two arguments, a pointer to an integer and a pointer to a double. The function should set the double to the value of the integer pointed to by the first argument, and the integer to the value of the double pointed to by the second argument.
void swap(int *px, int *py)
{
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}

int main()
{
  int a = 5, b = 10;
  swap(&a, &b);
  printf("a=%d b=%d\n", a, b);

  int x = 1, y = 2, z[10];
  int *ip;                       /* ip is a pointer to int */
  ip = &x;                       /* ip now points to x */
  y = *ip + 10; /* y is now 1 */ // y = 1 + 10 = 11
  *ip = 0;                       /* x is now 0 */
  ip = &z[0];                    /* ip now points to z[0] */
  printf("x=%d y=%d z[0]=%d\n", x, y, z[0]);

  int n, array[SIZE], getint(int *);
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
  for (n = 0; n < SIZE; n++)
    printf("array[%d]=%d\n", n, array[n]);
  return 0;
}

int getint(int *pn)
{
  int c, sign; // sign is +1 or -1 for the number sign 0 for no sign

  while (isspace(c = getch1())) /* skip white space  */
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') // if c is not a digit, not EOF, not + and not -
  {
    ungetch(c); /* it is not a number */
    return 0;
  }

  sign = (c == '-') ? -1 : 1;  // if c is - then sign is -1 else sign is 1
  
  if (c == '+' || c == '-')
  {
    c = getch1(); // get the next character
  } 
  for (*pn = 0; isdigit(c); c = getch1()) // while c is a digit get the number and multiply by 10
    *pn = 10 * *pn + (c - '0'); // convert the character to a number
  *pn *= sign; // multiply by the sign

  if (c != EOF)
    ungetch(c); // put the character back
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
// gcc -c cs50.c
//  ar rcs libcs50.a cs50.o
