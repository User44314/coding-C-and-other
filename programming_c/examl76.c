/* This is a category 0 Solution. December 20, 2019.
Unix-like systems have two commands called expand and unexpand. These commands do exactly what
detab and entab do respectivelly (but with a different syntax for the arguments).
So, I wrote my solutions to be operationally equivalent to these UNIX commands.
If you run ./detab 3 9 10 20 < file > out1, then run expand -t 3,9,10,20 < file > out2,
and compare the output of both commands with diff out1 out2; you will see that both outputs are equal.
Therefore, both my detab and UNIX expand are equivalent. I used GNU's and openBSD's expand to test it.
My implementation of entab is not fully equivalent with GNU unexpand, for some certain weird input combinations
of spaces between tabs (but I think this is because GNU unexpand uses some "smart guesses" in those situations).
They both have a limit of 100 arguments, and all the arguments must be positive integers listed in ascending order.
They return 2 if they get more than 100 arguments; return 1 if the arguments are not in the correct format;
and returns 0 if it runs successfully. The argument limit can be eliminated by using malloc (and turning it
into an category 1 solution) or by defining stop[] as unsigned char stop[argc+1] (and turn it into an category 2
solution, since C99 accepts defining arrays with variable size). */

// detab:

#include <stdio.h>

#define DEFSTOP 8
#define MAXSTOPS 100

int getstop(char *s);

/* detab: replace tabs with the proper number of blanks to space to the next tabstop */
int main(int argc, char *argv[])
{
	int c, n;
	unsigned char col;			  /* column after previous tabstop or beginning of line */
	unsigned char stop[MAXSTOPS]; /* list of tabstops */

	if (argc-- > MAXSTOPS)
		return 2; /* too many arguments */
	for (c = n = 0; n < argc; n++)
	{
		int temp;
		temp = getstop(*++argv);
		if (temp <= c)
			return 1; /* tabstop is not a positive integer or not in ascending order */
		stop[n] = temp - c;
		c = temp;
	}
	if (n == 0)
		stop[n++] = DEFSTOP;
	stop[n] = 0; /* the number of tabstops is n-1, where stop[n]==0 */
	col = n = 0;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '\t':
			do
			{
				putchar(' ');
			} while (stop[n] > ++col);
			if (stop[n] && stop[1])
				n++;
			col = 0;
			break;
		case '\n':
			putchar(c);
			col = n = 0;
			break;
		default:
			putchar(c);
			if (col == stop[n] - 1)
			{
				col = 0;
				if (stop[n] && stop[1])
					n++;
			}
			else
				++col;
			break;
		}
	}
	return 0;
}

/* getstop: return tabstop if valid, -1 if invalid */
int getstop(char *cp)
{
	int n;

	for (n = 0; *cp != '\0'; cp++)
	{
		if (*cp < '0' || *cp > '9')
			return -1;
		n = 10 * n + *cp - '0';
	}
	return n;
}


                                                           // entab:

// #include <stdio.h>

// #define DEFSTOP 8
// #define MAXSTOPS 100

// int getstop(char *s);

// /* entab: replace spaces by the least number of tabs/spaces to get the same spacing */
// int main(int argc, char *argv[])
// {
// 	int c, n;
// 	unsigned char col, spc;
// 	unsigned char stop[MAXSTOPS];

// 	if (argc-- > MAXSTOPS)
// 		return 2;     /* too many arguments */
// 	for (c = n = 0; n < argc; n++) {
// 		int temp;
// 		temp = getstop(*++argv);
// 		if (temp <= c)
// 			return 1; /* tabstop is not a positive integer or not in ascending order */
// 		stop[n] = temp - c;
// 		c = temp;
// 	}
// 	if (n == 0)
// 		stop[n++] = DEFSTOP;
// 	stop[n] = 0;      /* the number of tabstops is n-1, where stop[n]==0 */
// 	spc = col = n = 0;
// 	while ((c = getchar()) != EOF) {
// 		/* print blanks */
// 		if (col == 0) {
// 			if (spc > 1 || (spc == 1 && (c == ' ' || c == '\t')))
// 				putchar('\t');
// 			else if (spc == 1)
// 				putchar(' ');
// 		}
// 		else if (c != '\t' && c != ' ')
// 			while (spc--)
// 				putchar(' ');
// 		/* print character, if non-space; and count spaces */
// 		if (c != ' ') {
// 			putchar(c);
// 			spc = 0;
// 		}
// 		else
// 			(col == 0) ? (spc = 1) : spc++;
// 		/* count columns and stops */
// 		switch (c) {
// 		case '\t':
// 			if (stop[n] && stop[1])
// 				++n;
// 			col = 0;
// 			break;
// 		case '\n':
// 			n = col = 0;
// 			break;
// 		default:
// 			if (col == stop[n] - 1) {
// 				col = 0;
// 				if (stop[n] && stop[1])
// 					++n;
// 			}
// 			else
// 				++col;
// 			break;
// 		}
// 	}
// 	return 0;
// }

// /* getstop: return tabstop if valid, -1 if invalid */
// int getstop(char *cp)
// {
// 	int n;

// 	for (n = 0; *cp != '\0'; cp++) {
// 		if (*cp < '0' || *cp > '9')
// 			return -1;
// 		n = 10 * n + *cp - '0';
// 	}
// 	return n;
// }