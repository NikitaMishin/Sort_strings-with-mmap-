#include <stdlib.h>
#include <stdio.h>
#include "setstrings.h"



void setstrings (unsigned char *mmapfile, char **strings ,long int filesize, int quantitystrings)
{  
  int carrigereturn = 1;
  strings[0] = &(mmapfile[0]);
  long int i = 0;
  for (i ; i < filesize &&
                         carrigereturn < quantitystrings; i++ )
  {
    if ( mmapfile[i] == '\n') 
    {   
      carrigereturn++;
      strings[carrigereturn-1] = &(mmapfile[i+1]);  
    }
  }
}  
