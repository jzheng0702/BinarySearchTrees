/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#ifndef PRINCIPALS_H
#define PRINCIPALS_H

#include "title.h"


struct title_principals {
  char *tconst;
  char *nconst;
  char *characters;
};

struct array_principals {
  int num_of_items;
  struct title_principals* structptr;
  struct tree* nindex;
  struct tree* tindex;
};

struct array_principals* get_principals (char* path);
void build_tindex_tp(struct array_principals* myptr);
void build_nindex_tp(struct array_principals* myptr);
struct title_principals* find_nconst_tp(struct array_principals* myptr,char* sentence,struct array_title* title_basics);
struct title_principals* find_tconst_tp(struct array_principals* myptr,char* sentence,struct array_name* name_basics );
struct tree* find_nconst_md(struct tree* root,char* sentence,struct array_title* title_basics);
struct tree* find_tconst_md(struct tree* root,char* sentence,struct array_name* name_basics);




#endif
