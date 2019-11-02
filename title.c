#include "title.h"

struct array_title* get_title (char* path) {
  /*Declating my variables*/
  struct array_title * myArray = malloc(sizeof(struct array_title));
  static char myPath[100];
  char *strptr = NULL;
  char buffer[MAX_LENGTH];
  char *bufferConst = NULL;
  char *bufferTitle = NULL;
  char *strPtr;
  char * ptr;
  FILE * fp;


  /*The full-path name*/
  strcat(myPath,path);
  strcat(myPath,"/title.basics.tsv");
  ptr = malloc(strlen(myPath) + 1);/*malloc enough space for my pointer +1 for \0*/
  ptr = myPath;/*point to my string*/

  fp = fopen(ptr,"r");
  if (fp == NULL){
    fprintf(stderr,"File doesn't exist\n");
  }

  myArray -> num_of_items = 0;
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

    strptr = get_column(buffer,1);
    strPtr = get_column(buffer,4);
    if (strstr(strptr,"movie") && strstr(strPtr,"0")) {
      myArray -> num_of_items++;
    }
    free(strptr);
    free(strPtr);

  }
  printf("lines = %d\n",myArray -> num_of_items);/*Printing out the buffer*/


  /*malloc my array*/
  myArray -> structptr = malloc(sizeof(struct title_basics) * myArray -> num_of_items);
  myArray -> index = 0;
  myArray -> count = 0;

  fseek(fp,0,SEEK_SET);
  while(!feof(fp)){
    if (fgets(buffer,MAX_LENGTH,fp) == NULL){
      break;
    }

    if(strlen(buffer) == MAX_LENGTH - 1){
      fprintf(stderr,"Error: BUFFER TOO SMALL\n");
      exit(-1);
    }

    strptr = get_column(buffer,1);
    strPtr = get_column(buffer,4);
    if (strstr(strptr,"movie") && strstr(strPtr,"0")) {
      bufferTitle = strdup(get_column(buffer,2));
      bufferConst = strdup(get_column(buffer,0));
      myArray -> structptr[myArray -> index++].tconst = strdup(bufferConst);
      myArray -> structptr[myArray -> count++].primaryTitle = strdup(bufferTitle);
    }

  }


  fclose(fp);
  return myArray;


}
