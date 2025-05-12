/* altnames.c — переносимые имена для целочисленных типов */ 
#include <stdio.h> 
#include <inttypes.h> // поддерживает переносимые типы 
int main(void) 
{ 
 int16_t me16; // me16 - это 16-разрядная переменная со знаком
 me16 = 4593; 
 printf("First, let's assume that int16_t has the type short: "); 
 printf("me16 = %hd\n", me16); 
 printf("We will not make any further assumptions.\n"); 
 printf("Instead, use the \"macrocommand\" from the inttypes.h: "); 
 printf("me16 = %" PRId16 "\n", me16);
 printf("me16 = %" "hd" "\n", me16);
 return 0; 
} 