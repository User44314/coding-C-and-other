#include <stdio.h>

#define TAB 5 // Number of spaces of one tab.
      
int main()
{
  int c, i = 0, j;
	
  while((c = getchar()) != EOF){
		
    if(c == ' '){
			
      ++i; // This is a counter of white spaces.
		
      if((i % TAB) == 0) // Every group of a number of 'TAB'
        putchar('\t');   // spaces is replaced by a tab.
    }
		
    else{
			
      for(j = 0; j < (i % TAB); ++j) 	// Every group smaller than
        putchar(' ');		        // 'TAB' spaces is untouched.
				
      putchar(c); // Well, there exist other characters but spaces.
			
      if(i != 0)	// Once some text is found, the counter is reset.
        i = 0;
    }	
  }
}



























// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_BUFFER 1024 // maximum buffer size
// #define space ' '
// #define tab '\t'

// int sumnumberofspaces(int offset, int spacesize) 
// {
//     return spacesize - (offset % spacesize);
// }

// /* getline: read a line into s, return length */
// int getline(char s[], int lim)
// {
//     int c, i;
//     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//         s[i] = c;
//     if (c == '\n')  //new line character
//     {
//         s[i] = c;
//         ++i;
//     }
//     s[i] = '\0'; // null character to end the string
//     return i;
// }

// int main()
// {
//     char  Buffer[MAX_BUFFER];
//     int TabSize = 4; /* A good test value */
//     int SpaceSize = 8; /* A good test value */
  
//     int i, j, k, l;
  
//     while(getline(Buffer, MAX_BUFFER) > 0)
//     {
//       for(i = 0, l = 0; Buffer[i] != '\0'; i++)
//       {
//         if(Buffer[i] == space)
//         {
//           j = sumnumberofspaces(l, TabSize);
//           for(k = 0; k < j; k++)
//           {
//             putchar(tab);
//             l++;
//           }
//         }
//         else
//         {
//           putchar(Buffer[i]);
//           l++;
//         }
//       }
//     }
  
//     return 0;
// }
