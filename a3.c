#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  struct name_basics * strptr;
  if (argc < 2) {
    fprintf(stderr, "Usage:  %s directory\n", argv[0] );
    exit(-1);
  }

  strptr = get_name(argv[1]);
}
