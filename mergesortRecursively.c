#include "mergesortRecursively.h"
#include "merge.h"
#include "swap.h"
#include "comparer.h"
#include "copyarray.h"
#include <stdlib.h>
/*
Auxiliary function for mergesort
*/ 
void mergesortRecursively(char ** a,char **b,int  n , int *whereis)
{
 *whereis = 0;// right now in massive a
	if (n<2) return;
	if (n == 2) if ( comparer(a[0],a[1] ) )
	{ 
		swap(&a[0],&a[1]);	
	}
	 int middle = n/2;
	 int res,res1;
	 mergesortRecursively(a, b,middle,&res);
	 mergesortRecursively(a+middle,b+middle,n-middle,&res1);
	 if (res!=res1)
	 {
	 	if (res ==0) {copyarray(b+middle,n-middle,a+middle);}
	 	else copyarray(a+middle,n-middle,b+middle);
	 }
	 if (res==0)  
	 {
	 	merge(a,middle,a+middle,n-middle,b);
	 	*whereis = 1;
	 }
	 else
	 {
	 	merge(b,middle,b+middle,n-middle,a);
	  *whereis=0;
	 }
}
