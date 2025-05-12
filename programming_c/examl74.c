#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
int getline(char *line, int max);
/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE]; // char type is used to store the line
	long lineno = 0; // long type is used to store the line number
	// int type is used to store the number of arguments
	int c, except = 0, number = 0, found = 0; // int type is used to store the character, except, number, and found
	while (--argc > 0 && (*++argv)[0] == '-') // while loop is used to decrement the number of arguments and increment the argument
		// pointer and check if the first character of the argument is '-'
		while (c = *++argv[0])
			switch (c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
		{
			lineno++;
			if ((strstr(line, *argv) != NULL) != except)
			{
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

int getline(char *s, int lim)
{
	int c;
	char *p = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return p - s;
}
