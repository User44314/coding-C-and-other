/* Write the function htoi(s), which converts a s tring of hexadecimal digits
(including an option 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a throught f, and A through F. */
#include <stdio.h>
#include <string.h>

int htoi(char s[]);
int powerOfHex(int n);
int toUpperCase(int c);

int main()
{
  printf("%d\n", htoi("0x43F2Abc"));
  return 0;
}

int htoi(char s[])
{
  int n = 0, i, j = 0;
  for (i = strlen(s) - 1; i >= 0; --i)
  {
    if (s[i] >= '0' && s[i] <= '9')
      n += (s[i] - '0') * powerOfHex(j);
    else if ((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
    {
      if ((s[i] >= 'a' && s[i] <= 'f'))
        n += (toUpperCase(s[i]) - '7') * powerOfHex(j);
      else
        n += (s[i] - '7') * powerOfHex(j);
    }
    else
      i = 0;
    j++;
  }

  return n;
}

int powerOfHex(int n)
{
  int p;
  for (p = 1; n > 0; --n)
    p = p * 16;

  return p;
}

int toUpperCase(int c)
{
  if (c >= 'a' && c <= 'z')
    c -= 'a' - 'A';
  return c;
}