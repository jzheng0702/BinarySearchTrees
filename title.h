#ifndef TITLE_H
#define TITLE_H


#include "common.h"
#include "binary.h"

struct array_title {
  int num_of_items;
  struct title_basics* structptr;
  struct tree* root_one;
  struct tree* root_two;
};

struct title_basics {
  char *tconst;
  char *primaryTitle;
};

struct array_title* get_title (char* path);




#endif
