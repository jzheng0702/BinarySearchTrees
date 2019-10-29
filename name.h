#ifndef NAME_H
#define NAME_H

#include <stdio.h>
#include <string.h>

struct name_basics {
  char *nconst;
  char *primaryName;
};

struct name_basics* get_name (char* path);






#endif
