#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getline(char line[], int max);
double my_atof(char s[]);

#define MAXLINE 100
/* rudimentary calculator */
int main()
{
    double sum, my_atof(char[]);
    char line[MAXLINE];
    int getline(char line[], int max);
    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += my_atof(line)); // %g is used to print floating-point numbers in either fixed or exponential notation, depending on the value
    // and the precision of the number.
    return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof: convert string s to double */
double my_atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    return sign * val / power;
}

// Output:
// 1

/* % g % g представляет десятичный формат ответа, в зависимости от того, чья длина меньше,
    сравнивая между % e и % f.Также удаляет последующие нули.Используя эти спецификаторы формата, вы можете просто распечатать свои данные в разных форматах,
    в зависимости от ваших потребностей. */