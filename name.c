/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#include "common.h"
#include "name.h"

/*The get_name function will take a string as an argument
that is the directory path to the files.
It will return a pointer to an array of struct name_basics.*/
struct array_name* get_name (char* path) {
  /*Declating my variables*/
  struct array_name * myArray = malloc(sizeof(struct array_name));
  static char myPath[100];
  char *strptr;
  char buffer[MAX_LENGTH];
  char *bufferConst;
  char *bufferName;
  char * ptr;
  FILE * fp;
  int count = 0, index = 0;


  /*The full-path name*/
  strcat(myPath,path);
  strcat(myPath,"/name.basics.tsv");
  ptr = malloc(strlen(myPath) + 1);/*malloc enough space for my pointer +1 for \0*/
  ptr = myPath;/*point to my string*/

  fp = openFile(ptr);
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

    strptr = get_column(buffer,4);
    if (strstr(strptr,"actor") || strstr(strptr,"actress")) {
      myArray -> num_of_items++;
    }

  }
  /*printf("lines = %d\n",myArray -> num_of_items);Printing out the buffer*/


  /*malloc my array*/
  myArray -> structptr = malloc(sizeof(struct name_basics) * myArray -> num_of_items);
  myArray -> nindex = NULL;
  myArray -> const_index = NULL;
  fseek(fp,0,SEEK_SET);
  while(!feof(fp)){
    if (fgets(buffer,MAX_LENGTH,fp) == NULL){
      break;
    }

    if(strlen(buffer) == MAX_LENGTH - 1){
      fprintf(stderr,"Error: BUFFER TOO SMALL\n");
      exit(-1);
    }

    strptr = get_column(buffer,4);
    if (strstr(strptr,"actor") || strstr(strptr,"actress")) {
      bufferName = get_column(buffer,1);
      bufferConst = get_column(buffer,0);
      bufferConst = reverseString(bufferConst);
      /*printf("[%s]-[%s]\n",bufferConst,bufferName);*/
      myArray -> structptr[index++].nconst = strdup(bufferConst);
      myArray -> structptr[count++].primaryName = strdup(bufferName);
    }
  }


  fclose(fp);
  return myArray;
}

void build_pnindex(struct array_name* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    add_node(&myptr -> nindex,myptr -> structptr[i].primaryName,&myptr -> structptr[i]);
  }
}

struct name_basics* find_primary_name(struct array_name* myptr,char* sentence){
  struct tree* root;
  struct name_basics* answer;
  if (find_node(myptr->nindex,sentence) == NULL) {
    return NULL;
  } else {
    root = find_node(myptr->nindex,sentence);
    answer = root -> value;
  }


  return answer;
}


void build_nindex(struct array_name* myptr) {
  int i;

  /* It will loop over all the elements in the array*/
  for (i = 0; i < myptr -> num_of_items; i++) {
    add_node(&myptr -> const_index,myptr -> structptr[i].nconst,&myptr -> structptr[i]);
  }
}

struct name_basics* find_nconst(struct array_name* myptr,char* sentence){
  struct tree* root;
  struct name_basics* answer;
  if (find_node(myptr->const_index,sentence) == NULL) {
    return NULL;
  } else {
    root = find_node(myptr->const_index,sentence);
    answer = root -> value;
  }


  return answer;
}
