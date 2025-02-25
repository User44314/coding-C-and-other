#include <stdio.h> //include information about standard

#define LOWER1 0   /* lower limit of table */
#define UPPER1 300 /* upper limit */
#define STEP1 20   /* step size */

int main()
{
    printf("Hello World\n");

    // The next program uses the formula oC=(5/9)(oF-32) to print the following table of Fahrenheit
    // temperatures and their centigrade or Celsius equivalents:
    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius); //%d указывает целочисленный аргумент, с табуляцией (\t) между числами
        // если мы дополним каждый %d в операторе printf шириной %3d
        fahr = fahr + step;
    }
    // The second version of the program
    int fahr1;
    for (fahr1 = 0; fahr1 <= 300; fahr1 = fahr1 + 20)
        printf("%3d %6.1f\n", fahr1, (5.0 / 9.0) * (fahr1 - 32));
    // the 3 version of the program
    int fahr2;
    for (fahr2 = LOWER1; fahr2 <= UPPER1; fahr2 = fahr2 + STEP1)
        printf("%3d %6.1f\n", fahr2, (5.0 / 9.0) * (fahr2 - 32));
    // next program

    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    /* copy input to output; 2nd version */
    int c1;
    while ((c1 = getchar()) != EOF)
        putchar(c1);

    /* count lines in input */
    int c1, nl;
    nl = 0;
    while ((c1 = getchar()) != EOF)
        if (c1 == '\n')
            ++nl;
    printf("%d\n", nl);
}

/* define a function called main
that received no argument values
statements of main are enclosed in braces
 main calls library function printf
to print this sequence of characters
\n represents the newline character */

/* Спецификация преобразования printf %3.0f говорит,
что число с плавающей точкой (здесь fahr) должно быть напечатано шириной не менее трех символов,
без десятичной точки и дробных цифр. %6.1f
описывает другое число (celsius), которое должно быть напечатано шириной не менее шести символов,
с 1 цифрой после десятичной точки. */