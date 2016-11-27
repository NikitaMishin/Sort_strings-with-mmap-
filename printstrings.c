#include <stdlib.h>
#include <stdio.h>
#include "printstrings.h"


void printstrings(char **strings,int size)
{
  int h ;
  for ( h = 0 ;h < size; h++)
  { 
    int i = 0; 
    while(strings[h][i] != '\n')
    {
      printf("%c",strings[h][i++]);
    } 
    printf("\n");
 	}
}
