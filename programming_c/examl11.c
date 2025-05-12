#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024 // maximum buffer size
#define space ' '
#define tab '\t'

int sumnumberofspaces(int offset, int tabsize) 
{
    return tabsize - (offset % tabsize);
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')  //new line character
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; // null character to end the string
    return i;
}

int main()
{
    char  Buffer[MAX_BUFFER];
    int TabSize = 4; /* A good test value */
  
    int i, j, k, l;
  
    while(my_getline(Buffer, MAX_BUFFER) > 0)
    {
      for(i = 0, l = 0; Buffer[i] != '\0'; i++)
      {
        if(Buffer[i] == tab)
        {
          j = sumnumberofspaces(l, TabSize);
          for(k = 0; k < j; k++)
          {
            putchar(space);
            l++;
          }
        }
        else
        {
          putchar(Buffer[i]);
          l++;
        }
      }
    }
  
    return 0;
}
