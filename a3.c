/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#include "common.h"
#include <ctype.h>

int main(int argc, char * argv[]) {
  struct array_name * name_basics;
  struct array_title * title_basics;
  struct array_principals * title_principals;
  struct title_basics* title;
  struct name_basics* name;
  struct title_principals* principals;
  int count;
  char test[10];
  char *key;
  int i;
  char input[MAX_LENGTH];
  char commands[MAX_LENGTH];
  char* command;

  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }

  scanf("%s",input);
  printf("%s\n", input);

  if(strcmp(input,"name") == 0) {
    /*Set up*/
    title_basics = get_title( argv[1] );
    build_ptindex(title_basics);
    build_tindex(title_basics);

    name_basics = get_name( argv[1] );
    build_pnindex( name_basics );
    build_nindex( name_basics );

    title_principals = get_principals(argv[1]);
    build_tindex_tp( title_principals );
    build_nindex_tp( title_principals );


    printf("> %s %s\n",input,"Harrison Ford");

    if(find_primary_name(name_basics,"Harrison Ford") == NULL) {
      printf("%s: nothing founded!\n","Harrison Ford");
      exit(-1);
    } else {
      name = find_primary_name(name_basics,"Harrison Ford");
    }

    find_nconst_tp(title_principals,name->nconst,title_basics);

  } else if (strcmp(command,"title") == 0) {
    title_basics = get_title( argv[1] );
    build_ptindex(title_basics);
    build_tindex(title_basics);

    name_basics = get_name( argv[1] );
    build_pnindex( name_basics );
    build_nindex( name_basics );

    title_principals = get_principals(argv[1]);
    build_tindex_tp( title_principals );
    build_nindex_tp( title_principals );

    if(find_primary_title(title_basics,key) == NULL) {
      printf("%s: nothing founded!\n",key);
      exit(-1);
    } else {
      title = find_primary_title(title_basics,key);
    }

    if(find_tconst_tp(title_principals,title->tconst) == NULL) {
      printf("%s: nothing founded!\n",title->tconst);
      exit(-1);
    } else {
      principals = find_tconst_tp(title_principals,title->tconst);
    }

    if(find_nconst(name_basics,principals->nconst) == NULL) {
      printf("%s: nothing founded!\n",principals->nconst);
      exit(-1);
    } else {
      name = find_nconst(name_basics,principals->nconst);
    }

    printf("> %s %s\n",command,key);
    printf("%s: ",name->primaryName);
    printf("%s\n",principals ->characters);
  }

  return(0);
}
