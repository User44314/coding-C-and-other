#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* Упражнение 5-3. Напишите указательную версию функции strcat, которую мы показали в Главе 2:
strcat(s,t) копирует строку t в конец s. */

void strcpy1(char *s, char *t)
{
  while (*s++ = *t++)
    ;
}

void strcat1(char *s, char *t)
{
  while (*s)
  {
    ++s;
  }
  strcpy1(s, t);
}

int main(void)
{
  char testbuff[128];

  char *test[] =
      {
          "",
          "1",
          "12",
          "123",
          "1234"};

  size_t numtests = sizeof test / sizeof test[0]; // 5
  size_t thistest; // 0, 1, 2, 3, 4
  size_t inner; // 0, 1, 2, 3, 4

  for (thistest = 0; thistest < numtests; thistest++)
  {
    for (inner = 0; inner < numtests; inner++)
    {
      strcpy1(testbuff, test[thistest]);
      strcat1(testbuff, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
    }
  }

  return 0;
}
