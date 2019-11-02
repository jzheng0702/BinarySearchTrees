#ifndef BINARY_H
#define BINARY_H

struct tree {
  char *key;
  void *data;
  struct tree* children[2];

};


//void printTree(struct tree* root);
//void freeTree(struct tree *root);



#endif
