#ifndef PRINCIPALS_H
#define PRINCIPALS_H

#include "common.h"

struct title_principals {
  char *tconst;
  char *nconst;
  char *characters;
};

struct array_principals {
  int num_of_items;
  struct title_principals* structptr;
  int index;
  int count;
  int index2;
};

struct array_principals* get_principals (char* path);




#endif
