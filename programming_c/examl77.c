/*
 * entab.c (Exercise 5-12)
 * Author   :   Franz Fritsche
 * About    :   Replaces strings of blanks with the minimum number
 *              of tabs and blanks to achieve the same spacing.
 * Usage    :   entab -m +n
 *              (tab stops every n columns, starting at column m)
 * Date     :   March 23, 2007
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 4 /* default tab size */

int main(int argc, char *argv[])
{
	int c, pos, spaces, i;
	int tabsize[2] = {TABSIZE, TABSIZE};

	while (--argc > 0 && (**++argv == '-' || **argv == '+'))
		switch (**argv)
		{
		case '-':
			if ((pos = atoi(*argv + 1)) > 0)
				tabsize[0] = pos;
			break;
		case '+':
			if ((pos = atoi(*argv + 1)) > 0)
				tabsize[1] = pos;
			break;
		}

	pos = 0; // initial position
	spaces = 0; // number of spaces to be converted to tabs
	i = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (pos < tabsize[i] - 1)
			{
				++pos;
				++spaces;
			}
			else
			{
				putchar('\t');
				pos = 0;
				spaces = 0;
				if (i < 1)
					i++;
			}
		}
		else
		{
			if (c != '\t')
				while (spaces)
				{
					putchar(' ');
					--spaces;
				}

			putchar(c);

			if (c == '\n')
			{
				pos = 0;
				spaces = 0;
				i = 0;
			}
			else if (c == '\t')
			{
				pos = 0;
				spaces = 0;
				if (i < 1)
					i++;
			}
			else /* normal character */
			{
				++pos;

				if (pos == tabsize[i])
				{
					pos = 0;
					if (i < 1)
						i++;
				}
			}
		}
	}

	while (spaces) /* may be left to do */
	{
		putchar(' ');
		--spaces;
	}

	return 0;
}






// /*
//  * detab.c (Exercise 5-12)
//  * Author   :   Franz Fritsche
//  * About    :   Replaces tabs in the input with the proper number 
//  *              of blanks to space to the next tab stop.
//  * Usage    :   detab -m +n
//  *              (tab stops every n columns, starting at column m)
//  * Date     :   March 23, 2007
//  */

//  #include <stdio.h>
//  #include <stdlib.h>
 
//  #define TABSIZE 4    /* default tab size */
 
//  int main(int argc, char *argv[])
//  {
// 	 int c, pos, i;
// 	 int tabsize[2] = {TABSIZE, TABSIZE};
 
// 	 while (--argc > 0 && (**++argv == '-' || **argv == '+'))
// 		 switch (**argv)
// 		 {
// 			 case '-':
// 				 if ((pos = atoi(*argv + 1)) > 0)
// 					 tabsize[0] = pos;
// 				 break;
// 			 case '+':
// 				 if ((pos = atoi(*argv + 1)) > 0)
// 					 tabsize[1] = pos;
// 				 break;
// 		 }
	 
// 	 pos = 0;
// 	 i = 0;
// 	 while ((c = getchar()) != EOF)
// 	 {
// 		 if (c == '\t')
// 		 {
// 			 while (pos < tabsize[i])
// 			 {
// 				 putchar(' ');
// 				 ++pos;
// 			 }
// 			 pos = 0;
// 			 if (i < 1)
// 				 i++;
// 		 }
// 		 else  
// 		 {
// 			 putchar(c);
			 
// 			 if (c == '\n')
// 			 {
// 				 pos = 0;
// 				 i = 0;
// 			 }
// 			 else /* normal character */
// 			 {
// 				 ++pos;
			 
// 				 if (pos == tabsize[i])
// 				 {
// 					 pos = 0;
// 					 if (i < 1)
// 						 i++;
// 				 }
// 			 }
// 		 }
// 	 }
 
// 	 return 0;
//  }