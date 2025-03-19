#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define ALLOCSIZE 10000          /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position static pointer char *allocp = &allocbuf[0]; */

char *alloc(int n)               /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) //проверяет, достаточно ли места для удовлетворения запроса на n символов.
  {
    allocp += n;
    return allocp - n; /* old p */
  }
  else /* not enough room */
    return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c))
  {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (!isalnum(*w = getch()))
    {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

int main()
{
  char *p = alloc(10);
  printf("p = %p\n", p);
  afree(p);
  printf("p = %p\n", p);
  return 0;
}


