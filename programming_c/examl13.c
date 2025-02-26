#include <stdio.h>

#define MAXLINE 1000 /* max input line size */
char line[MAXLINE];  // current input line
int getline(char line[], int maxline); // read a line into s, return length

/* print the longest input line */
int main()
{
  int t, len; // t is the current character, len is the length of the line
  int location, spaceholder; // location is the current location in the line, spaceholder is the location of the last space
  const int FOLDLENGTH = 70; /* The max length of a line */

  while ((len = getline(line, MAXLINE)) > 0)
  {
    if (len < FOLDLENGTH)
    {
    }
    else
    {
      /* if this is an extra long line then we
      ** loop through it replacing a space nearest
      ** to the foldarea with a newline.
      */
      t = 0;
      location = 0;
      while (t < len)
      {
        if (line[t] == ' ')
          spaceholder = t; // spaceholder is the location of the last space

        if (location == FOLDLENGTH)
        {
          line[spaceholder] = '\n'; // replace the space with a newline
          location = 0;
        }
        location++;
        t++;
      }
    }
    printf("%s", line);
  }
  return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') // new line character
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0'; // null character to end the string
  return i;
}
