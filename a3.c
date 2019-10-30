#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  struct name_basics * strptr;
  int i;
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }

  strptr = get_name(argv[1]);

/*Testing for name
  for (i=0;i<10;i++){
    printf( "%s %s\n", strptr[i].nconst, strptr[i].primaryName);
  }
  printf( "\n" );

  for (i=524619;i<524629;i++) {
    printf( "%s %s\n", strptr[i].nconst, strptr[i].primaryName);
  }*/
}
