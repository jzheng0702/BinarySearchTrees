#ifndef BINARY_H
#define BINARY_H

#include "common.h"
#include "title.h"

struct tree {
  char *key;
  void *value;
  struct tree* children[2];

};


void add_node(struct tree **root, char* my_key, void* structptr);
int compare(const void* s1, const void* s2);
struct tree *find_node( struct tree *root, char* sentence);
void freeTree(struct tree* root);



#endif
