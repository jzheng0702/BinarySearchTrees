#include "name.h"

/*The get_name function will take a string as an argument
that is the directory path to the files.
It will return a pointer to an array of struct name_basics.*/

struct name_basics* get_name (char* path) {
  /*Declating my variables*/
  struct name_basics * strptr;
  static char myPath [100];
  char buffer[MAX_LENGTH];
  char * ptr;
  FILE * fp;


  /*The full-path name*/
  strcat(myPath,path);
  strcat(myPath,"/name.basics.tsv");
  ptr = malloc(strlen(myPath) + 1);/*malloc enough space for my pointer +1 for \0*/
  ptr = myPath;/*point to my string*/

  fp = fopen(ptr,"r");
  if (fp == NULL){
    fprintf(stderr,"File doesn't exist\n");
  }

  /*Then, inside a while loop, I will fgets into a buffer
  string of length 256.  I will check the return value of
  the fgets function and print an error message if something goes wrong.*/
  while(!(feof(fp))){
    if (fgets(buffer,MAX_LENGTH,fp) == NULL){
      break;
    }

    if(strlen(buffer) == MAX_LENGTH - 1){ /*检查buffer会不会太长，比设置的buffer_size要长*/
      fprintf(stderr,"Error: BUFFER TOO SMALL\n");
      exit(-1);
    }

    printf("%s",buffer);/*Printing out the buffer*/

  }
  fclose(fp);
  free(ptr);

  return NULL;
}
