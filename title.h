#ifndef TITLE_H
#define TITLE_H

#include "binary.h"



struct array_title {
  int num_of_items;
  struct title_basics* structptr;
  struct tree* const_index;
  struct tree* tindex;
};

struct title_basics {
  char *tconst;
  char *primaryTitle;
};

struct array_title* get_title (char* path);
void build_tindex(struct array_title* myptr);
struct title_basics* find_primary_title(struct array_title* myptr,char* sentence);




#endif
