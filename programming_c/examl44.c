#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

/* In reverse Polish notation, each operator follows its operands; an infix expression like
(1 - 2) * (4 + 5)
is entered as
1 2 - 4 5 + * 
*/


#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
/* reverse Polish calculator */

int main()
{
    int type;                        // type of the input
    double op2;                      // second operand
    char s[MAXOP];                   // input strings
    while ((type = getop(s)) != EOF) // getop() returns EOF when the end of the input is reached
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s)); // atof() converts the string to a number
            break;
        case '+':
            push(pop() + pop()); // the order of the operands is not important for the addition and multiplication operations
            break;
        case '*':
            push(pop() * pop()); // the order of the operands is not important for the addition and multiplication operations
            break;
        case '%':
            op2 = pop();
            if (op2)
                push(fmod(pop(), op2));
            else
                printf("\nError: Division by zero!");
            break;
        case '-':
            op2 = pop(); // the order of the operands is important for the subtraction and division operations
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[]) // getop() returns the type of the input
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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