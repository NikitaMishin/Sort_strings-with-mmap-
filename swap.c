#include "swap.h"

void swap(char **a,char **b)
{
	char *t = *a;
  *a = *b;
  *b = t;
 }
