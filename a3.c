#include "common.h"

int main(int argc, char * argv[]) {
  struct array_name * strptr;
  struct array_title * title_basics;
  struct array_principals * title_principals;
  struct title_basics* title;
  struct name_basics* name;
  /*int i;*/
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }

  strptr = get_name(argv[1]);
  //title_basics = get_title(argv[1]);
  //title_principals = get_principals(argv[1]);

  //build_tindex(title_basics);
  build_nindex(strptr);
  //printTree(title_basics->tindex);

/*
  printf( "%p\n", (void *)(strptr->nindex) );
  printf( "%s\n", (strptr->nindex)->key );
  printf( "%p\n", (void *)(strptr->nindex)->value );
  printf( "%s\n", ((struct name_basics *)((strptr->nindex)->value))->primaryName);
  printf( "%s\n", ((struct name_basics *)((strptr->nindex)->value))->nconst );*/


/*

  title = find_primary_title(title_basics,"Star Wars: Episode V - The Empire Strikes Back" );

  printf( "%p\n", (void *)title );
  printf( "%s\n", title->tconst );
  printf( "%s\n", title->primaryTitle );*/


  name = find_primary_name(strptr,"Anthony Daniels" );

  printf( "%p\n", (void *)name );
  printf( "%s\n", name->nconst );
  printf( "%s\n", name->primaryName );


  /*Testing
  printf( "%p\n", (void *)(title_basics->tindex) );
  printf( "%s\n", (title_basics->tindex)->key );
  printf( "%p\n", (void *)(title_basics->tindex)->value );
  printf( "%s\n", ((struct title_basics *)((title_basics->tindex)->value))->primaryTitle );
  printf( "%s\n", ((struct title_basics *)((title_basics->tindex)->value))->tconst );

  /*Testing for name*/
  /*for (i=0;i<10;i++){
    printf( "%s %s\n", strptr -> structptr[i].nconst, strptr -> structptr[i].primaryName);
  }
  printf( "\n" );

  for (i=524619;i<524629;i++) {
    printf( "%s %s\n", strptr -> structptr[i].nconst, strptr -> structptr[i].primaryName);
  }*/

  /*Testing for title*/
  /*
  for (i=0;i<10;i++){
    printf( "%s %s\n", titleptr -> structptr[i].tconst, titleptr -> structptr[i].primaryTitle);
  }
  printf( "\n" );

  for (i=525313;i<525323;i++) {
    printf( "%s %s\n",titleptr -> structptr[i].tconst, titleptr -> structptr[i].primaryTitle);
  }*/

  /*Testing for principals
  for (i=0;i<10;i++) {
    printf( "%s %s %s", title_principals -> structptr[i].tconst,title_principals -> structptr[i].nconst,title_principals -> structptr[i].characters);
  }
  printf( "\n" );

  for (i=14676207;i<14676217;i++){
    printf( "%s %s %s", title_principals -> structptr[i].tconst,title_principals -> structptr[i].nconst,title_principals -> structptr[i].characters);
  }*/
}
