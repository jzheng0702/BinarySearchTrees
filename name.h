#ifndef NAME_H
#define NAME_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

struct name_basics {
  char *nconst;
  char *primaryName;
};

struct name_basics* get_name (char* path);






#endif
