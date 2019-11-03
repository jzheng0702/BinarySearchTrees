#include "binary.h"



int compare(const void* s1, const void* s2) {
	return strcmp(s1, s2);
}
void add_node(struct tree **root, char* my_key, void* structptr) {
  if (*root) /*there's a node here*/
  {
    if (compare(my_key,(*root)->key) < 0) {
      add_node(&((*root)->children[0]), my_key,structptr);
    }
    else {
      add_node(&((*root)->children[1]), my_key,structptr);
    }
  }
  else { /*No node here*/
    (*root) = malloc(sizeof( struct tree ));
    (*root)-> value = structptr;
    (*root)-> key = my_key;
    (*root)-> children[0]= NULL;
    (*root)-> children[1]= NULL;
  }
}

struct tree *find_node( struct tree *root, char* sentence) {
	/*while (root != NULL) {
		if (compare(sentence,root->key) == 0) {
			return root;
		} else if (compare(sentence,root->key) > 0){
	    root = root -> children[1];
		} else {
			root = root -> children[0];
		}
  }

  return NULL;*/
  if (root) {
    if (compare(sentence,root->key) != 0){
			if (compare(sentence,root->key) < 0){
        return find_node(root->children[0], sentence);
      }
      else {
        return find_node(root->children[1], sentence);
      }
    }
    else{
			return root;
    }

  }
  else {
    return NULL;
  }
}

void printTree(struct tree *root) {
  if (root) {
    printf("%s\n",root -> key);
    printTree(root -> children[0]);
    printTree(root -> children[1]);
  }
}

/*

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
