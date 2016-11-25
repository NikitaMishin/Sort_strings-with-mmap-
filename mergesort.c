#include "mergesort.h"
#include "mergesortRecursively.h"
#include "copyarray.h"
#include "comparer.h"
#include "swap.h"
#include <stdlib.h>
void mergesort(char ** a,int n)
{
	if (n<=1) return;
	if (n==2) 
	{
		if (comparer(a[0],a[1]))
		{
		 swap(&a[0],&a[1]);
		}
		return;
	}
	int where_m = 0;//  0== in massive a
	char **b = (char**)malloc(sizeof(char*)*n);
	mergesortRecursively(a,b,n,&where_m);
	if (where_m!=0) copyarray(b,n,a); //(from,where)
	free(b);
}

