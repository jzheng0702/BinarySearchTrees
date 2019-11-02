#ifndef TITLE_H
#define TITLE_H


#include "common.h"

struct array_title {
  int num_of_items;
  struct title_basics* structptr;
  int index;
  int count;
};

struct title_basics {
  char *tconst;
  char *primaryTitle;
};

struct array_title* get_title (char* path);




#endif
