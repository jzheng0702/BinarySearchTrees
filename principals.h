#ifndef PRINCIPALS_H
#define PRINCIPALS_H

struct title_principals {
  char *tconst;
  char *nconst;
  char *characters;
};

struct title_principals* get_principals (char* path);




#endif
