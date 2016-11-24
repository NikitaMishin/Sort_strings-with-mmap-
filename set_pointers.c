


 strings[0] = &mmapfile[0];
   printf("%c",*strings[0]);
  for (long int i = 0; i < filesize &&
                         carrigereturn < quantitystrings; i++ )
  {
    if ( mmapfile[i] == '\n') 
    {
      carrigereturn++;
      strings[carrigereturn] = &(mmapfile[i+1]);
      printf ("%c",*strings[carrigereturn]);
    }
  }
    
    
   printf("%d",carrigereturn);
