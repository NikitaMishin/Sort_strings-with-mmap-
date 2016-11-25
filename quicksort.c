#include "quicksort.h"
#include "swap.h"
#include "comparer.h"
#include "time.h"

//quicksort function sorting massive of strings

void quicksort( char **s,  int size)
{	
		//srand(time(NULL));
	int l_pointer = 0;			// pointer on first string
	int r_pointer = size; // pointer on last string
	 int p = 0;
	 
	while(l_pointer <= r_pointer)
	{
		while ( comparer( s[p], s[l_pointer] ) ) ++l_pointer; //l<x
		while ( comparer( s[r_pointer],s[p] ) ) --r_pointer; //x<r
 		if (l_pointer<=r_pointer)
		{
		swap(&s[l_pointer++],&s[r_pointer--]);
		}	
	}
	if(r_pointer > 0) quicksort(s, r_pointer);
	if (l_pointer<size) quicksort(s+l_pointer,size-l_pointer);
}

