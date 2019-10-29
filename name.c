#include "name.h"

/*The get_name function will take a string as an argument
that is the directory path to the files.
It will return a pointer to an array of struct name_basics.*/

struct name_basics* get_name (char* path) {
  /*Declating my variables*/
  struct name_basics * strptr;
  char myPath [100] = path;
  char * ptr;
  FILE * fp;

  /*The full-path name*/
  strcat(myPath,"/name.basics.tsv");
  ptr = malloc(strlen(myPath) + 1);/*malloc enough space for my pointer +1 for \0*/
  ptr = myPath;/*point to my string*/

  fp = fopen(ptr,"r");


  return strptr;
}
