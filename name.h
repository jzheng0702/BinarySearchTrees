/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#ifndef NAME_H
#define NAME_H


struct name_basics {
  char *nconst;
  char *primaryName;
};

struct array_name {
  int num_of_items;
  struct name_basics* structptr;
  struct tree* nindex;
  struct tree* const_index;
};

struct array_name* get_name (char* path);
void build_pnindex(struct array_name* myptr);
struct name_basics* find_primary_name(struct array_name* myptr,char* sentence);
void build_nindex(struct array_name* myptr);
struct name_basics* find_nconst(struct array_name* myptr,char* sentence);







#endif
