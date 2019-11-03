/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#include "common.h"
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
  int index = 0;
  int count = 0;


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
  /*printf("lines = %d\n",myArray -> num_of_items);Printing out the buffer*/


  /*malloc my array*/
  myArray -> structptr = malloc(sizeof(struct title_basics) * myArray -> num_of_items);
  index = 0;
  count = 0;
  myArray -> const_index = NULL;
  myArray -> tindex = NULL;

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
      bufferConst = reverseString(bufferConst);
      /*printf("%s\n",bufferConst);*/
      myArray -> structptr[index++].tconst = strdup(bufferConst);
      myArray -> structptr[count++].primaryTitle = strdup(bufferTitle);
    }

  }


  fclose(fp);
  return myArray;


}

/*build a tree based on primaryTitle*/
void build_ptindex(struct array_title* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    add_node(&myptr -> tindex,myptr -> structptr[i].primaryTitle,&myptr -> structptr[i]);
  }
}

struct title_basics* find_primary_title(struct array_title* myptr,char* sentence){
  struct tree* root;
  struct title_basics* answer;
  if (find_node(myptr->tindex,sentence) == NULL) {
    return NULL;
  } else {
    root = find_node(myptr->tindex,sentence);
    answer = root -> value;
  }


  return answer;
}

/*Build a tree based on tconst*/
void build_tindex(struct array_title* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    add_node(&myptr -> const_index,myptr -> structptr[i].tconst,&myptr -> structptr[i]);
  }
}

struct title_basics* find_tconst(struct array_title* myptr,char* sentence){
  struct tree* root;
  struct title_basics* answer;
  if (find_node(myptr->const_index,sentence) == NULL) {
    return NULL;
  } else {
    root = find_node(myptr->const_index,sentence);
    answer = root -> value;
  }


  return answer;
}
