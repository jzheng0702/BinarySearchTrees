#ifndef NAME_H
#define NAME_H

#include "common.h"


struct name_basics {
  char *nconst;
  char *primaryName;
};

struct array_name {
  int num_of_items;
  struct name_basics* structptr;
  struct tree* root_one;
  struct tree* root_two;
};

struct array_name* get_name (char* path);







#endif
