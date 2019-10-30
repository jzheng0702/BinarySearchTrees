#include "common.h"
#include "principals.h"


struct title_principals* get_principals (char* path){
  /*Declating my variables*/
  struct title_principals * structptr;
  static char myPath[100];
  char *strptr = NULL;
  char buffer[MAX_LENGTH];
  char *bufferConst = NULL;
  char *bufferChar = NULL;
  char *bufferTConst = NULL;
  char * ptr;
  FILE * fp;
  int count = 0,index = 0,anotherIndex = 0;
  int numOfLines = 0;


  /*The full-path name*/
  strcat(myPath,path);
  strcat(myPath,"/title.principals.tsv");
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

    strptr = get_column(buffer,3);
    if (strstr(strptr,"actor") || strstr(strptr,"actress")) {
      numOfLines++;
    }
    free(strptr);

  }
  printf("lines = %d\n",numOfLines);/*Printing out the buffer*/


  /*malloc my array*/
  structptr = malloc(sizeof(struct title_principals) * numOfLines);
  fseek(fp,0,SEEK_SET);
  while(!feof(fp)){
    if (fgets(buffer,MAX_LENGTH,fp) == NULL){
      break;
    }

    if(strlen(buffer) == MAX_LENGTH - 1){
      fprintf(stderr,"Error: BUFFER TOO SMALL\n");
      exit(-1);
    }

    strptr = get_column(buffer,3);
    if (strstr(strptr,"actor")|| strstr(strptr,"actress")) {
      bufferChar = strdup(get_column(buffer,5));
      bufferConst = strdup(get_column(buffer,2));
      bufferTConst = strdup(get_column(buffer,0));
      structptr[index++].nconst = strdup(bufferConst);
      structptr[anotherIndex++].tconst = strdup(bufferTConst);
      structptr[count++].characters = strdup(bufferChar);
    }

  }


  fclose(fp);
  return structptr;
}
