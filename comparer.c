#include "comparer.h" 

/*
 comparator for English letters
*/
 int comparer (char* mas1, char* mas2)  //return 1 when mas1>mas2
{	
  int i = 0;
  int f = 0;
  int s = 0;
  while((mas1[i] !='\n')&& (mas2[i]!='\n'))
  {	
    f = mas1[i];
    s = mas2[i++];
    if (f > s) { return 1;}
    else if(f < s) {return 0;}    	
  }
  if (mas1[i]=='\n')return 0;
  return 1;
}


