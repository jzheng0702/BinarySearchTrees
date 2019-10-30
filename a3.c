#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  struct name_basics * strptr;
  struct title_basics * titleptr;
  struct title_principals * title_principals;
  int i;
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }

  //strptr = get_name(argv[1]);
  //titleptr = get_title(argv[1]);
  title_principals = get_principals(argv[1]);


  /*Testing for name*/
  /*for (i=0;i<10;i++){
    printf( "%s %s\n", strptr[i].nconst, strptr[i].primaryName);
  }
  printf( "\n" );

  for (i=524619;i<524629;i++) {
    printf( "%s %s\n", strptr[i].nconst, strptr[i].primaryName);
  }*/

  /*Testing for title*/
  /*for (i=0;i<10;i++){
    printf( "%s %s\n", titleptr[i].tconst, titleptr[i].primaryTitle);
  }
  printf( "\n" );

  for (i=525313;i<525323;i++) {
    printf( "%s %s\n", titleptr[i].tconst, titleptr[i].primaryTitle);
  }*/

  /*Testing for principals
  for (i=0;i<10;i++) {
    printf( "%s %s %s\n", title_principals[i].tconst,title_principals[i].nconst,title_principals[i].characters );
  }
  printf( "\n" );

  for (i=14676207;i<14676217;i++){
    printf( "%s %s %s\n", title_principals[i].tconst,title_principals[i].nconst,title_principals[i].characters );
  }*/
}
