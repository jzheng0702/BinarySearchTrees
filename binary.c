#include "common.h"
#include "binary.h"

/*
void printTree(struct tree *root) {
  if (root) {
    printf("%d\n",root -> data);
    printTree(root -> children[0]);
    printTree(root -> children[1]);
  }
}

void freeTree(struct trr *root){
  if (root) {
    freeTree(root -> children[0]);
    freeTree(root -> children[1]);
    free(root);
  }
}

void add_node( struct tree **root, int number)
{
  if (*root) there's a node here
  {
    if (number < (*root) -> data)
    {
      add_node(&((*root)->children[0]), number);
    }
    else {
      add_node( &((*root)->children[1]), number);
    }
  }
  else no node here
  {
    (*root) = malloc( sizeof( struct tree ));
    (*root)->data = number;
    (*root)-> key = 0;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}

struct tree* searchTree(struct tree* root, int value) {
  while (root != NULL && value != root -> data) {
    if (root -> data < value) {
      root = root -> children[0];
    } else {
      root = root -> children[1];
    }
  }

  return root;
}*/
