#include "merge.h"
#include "comparer.h"

void merge(char **a,int fir, char **b ,int sec,char **c) 
{ 
	int l = 0;
	int r = 0;
	int i = 0;
	while(l<fir&&r<sec)
	{
		if (comparer(a[l],b[r])) {c[i] = b[r++];	}
		else {c[i] =a[l++];}
		i++;
	}
	while(l<fir) c[i++] =a[l++];
	while(r<sec) c[i++] = b[r++];			
	
}

