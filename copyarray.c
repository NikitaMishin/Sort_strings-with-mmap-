#include "copyarray.h"

void copyarray(char **a, int n,char **b)//from to where
{
 for (int i = 0; i != n;i++ )
  b[i] = a[i]; 	
}

