#include "common.h"

int main(int argc, char * argv[]) {
  struct array_name * name_basics;
  struct array_title * title_basics;
  struct array_principals * title_principals;
  struct title_basics* title;
  struct name_basics* name;
  struct title_principals* principals;
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }
  
  title_basics = get_title( argv[1] );
  build_ptindex(title_basics);
  build_tindex(title_basics);



  name_basics = get_name( argv[1] );
  build_pnindex( name_basics );
  build_nindex( name_basics );


  title_principals = get_principals(argv[1]);
  build_tindex_tp( title_principals );
  build_nindex_tp( title_principals );



  printf( "Ready\n" );
  name = find_primary_name( name_basics, "Bruce Lee" );
  principals = find_nconst_tp( title_principals, name->nconst );
  title = find_tconst( title_basics, principals->tconst );
  printf( "%s\n", title->primaryTitle );
}
