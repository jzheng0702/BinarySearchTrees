#include "name.h"
#include "common.h"

/*The get_name function will take a string as an argument
that is the directory path to the files.
It will return a pointer to an array of struct name_basics.*/
struct name_basics* get_name (char* path) {
  /*Declating my variables*/
  struct name_basics * structptr;
  static char myPath[100];
  char *strptr = NULL;
  char buffer[MAX_LENGTH];
  char bufferWord[100];
  char * ptr;
  FILE * fp;
  int numOfLines = 0;


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

    if(strlen(buffer) == MAX_LENGTH - 1){
      fprintf(stderr,"Error: BUFFER TOO SMALL\n");
      exit(-1);
    }

    strptr = get_column(buffer,4);
    if (strstr(strptr,"actor") != NULL) {
      strcpy(bufferWord,"actor");
      numOfLines++;
      /*printf("[%s]\n",bufferWord);*/
    } else if (strstr(strptr,"actress") != NULL) {
      strcpy(bufferWord,"actress");
      numOfLines++;
    }
    free(strptr);

  }
  printf("lines = %d\n",numOfLines);/*Printing out the buffer*/
  fclose(fp);

  return NULL;
}
