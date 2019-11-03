#include "common.h"


struct array_principals* get_principals (char* path){
  /*Declating my variables*/
  struct array_principals * myArray = malloc(sizeof(struct array_principals));
  static char myPath[100];
  char *strptr = NULL;
  char buffer[MAX_LENGTH];
  char *bufferConst = NULL;
  char *bufferChar = NULL;
  char *bufferTConst = NULL;
  char * ptr;
  FILE * fp;
  int count = 0,index = 0,index2 = 0;


  /*The full-path name*/
  strcat(myPath,path);
  strcat(myPath,"/title.principals.tsv");
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

    strptr = get_column(buffer,3);
    if (strstr(strptr,"actor") || strstr(strptr,"actress")) {
      myArray -> num_of_items++;
    }
    free(strptr);

  }
  printf("lines = %d\n",myArray -> num_of_items);/*Printing out the buffer*/


  /*malloc my array*/
  myArray -> structptr = malloc(sizeof(struct title_principals) * myArray -> num_of_items);
  myArray -> tindex = NULL;
  myArray -> nindex = NULL;
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
      bufferConst = reverseString(bufferConst);
      myArray -> structptr[index++].nconst = strdup(bufferConst);
      bufferTConst = strdup(get_column(buffer,0));
      bufferTConst = reverseString(bufferTConst);
      myArray -> structptr[index2++].tconst = strdup(bufferTConst);
      myArray -> structptr[count++].characters = strdup(bufferChar);
    }

  }


  fclose(fp);
  return myArray;
}

void build_nindex_tp(struct array_principals* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    //printf("%s\n",myptr -> structptr[i].primaryName);
    add_node(&myptr -> nindex,myptr -> structptr[i].nconst,&myptr -> structptr[i]);
  }
}

struct title_principals* find_nconst_tp(struct array_principals* myptr,char* sentence){
  struct tree* root;
  struct title_principals* answer;
  root = find_node(myptr->nindex,sentence);
  answer = root -> value;


  return answer;
}

void build_tindex_tp(struct array_principals* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    //printf("%s\n",myptr -> structptr[i].primaryName);
    add_node(&myptr -> tindex,myptr -> structptr[i].tconst,&myptr -> structptr[i]);
  }
}

struct title_principals* find_tconst_tp(struct array_principals* myptr,char* sentence){
  struct tree* root;
  struct title_principals* answer;
  root = find_node(myptr->tindex,sentence);
  answer = root -> value;


  return answer;
}
