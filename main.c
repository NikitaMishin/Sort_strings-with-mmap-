#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h> //for mmap
#include <sys/stat.h> // for flags
#include <unistd.h>	//for close()
#include <sys/types.h>
#include <fcntl.h>	 //for open()
#include "bubblesort.h"
#include "comparer.h"
#include "printstrings.h"
#include "mergesort.h"
#include "setstrings.h"
int main(int argc, char **argv)
{
  int filedescriptor; 
  int quantitystrings;
  long int filesize;
  unsigned char *mmapfile;
  long int quantitysymbols;
  char **strings;
  struct stat st;
  if (argc != 3) 
  {
    printf("Wrong input");
    exit(1);
  }
  quantitystrings = atoi(argv[1]);
  if( (filedescriptor = open(argv[2],O_RDONLY,0)) < 0) 
  {
    printf("Can't open the file");
    exit(1);
  }
  if (fstat (filedescriptor,&st) == -1)
  {
    printf("Bad Descriptor of file");    
    exit(1);
  }
  if ( (filesize = st.st_size) ==0) 
  {
    printf ("Nothing in file");
    exit(1);
  };
  mmapfile = (unsigned char*)mmap(0, filesize+1, PROT_READ | PROT_WRITE,
                                         MAP_PRIVATE, filedescriptor, 0);
  if( mmapfile == MAP_FAILED )
  {
    printf("System error. Can't mmap");
    exit(1);
  }
  mmapfile[filesize-1] = '\n'; //okk
  quantitysymbols = filesize;
  strings = (char**)malloc( sizeof(char*)* (quantitystrings+1)); 
  //if no plus one will be erorrs
  setstrings(mmapfile,strings,filesize,quantitystrings);
  mergesort(strings, quantitystrings);
  printstrings (strings,quantitystrings);
  free(strings);
  if (close(filedescriptor) == -1 )
  {
    printf("Can't close the file");
  }
  return 0;
}
