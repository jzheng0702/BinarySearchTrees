#include "binary.h"



int compare(const void* s1, const void* s2) {
	return strcmp(s1, s2);
}

void add_node(struct tree **root, char* my_key, void* structptr) {
  if (*root) /*there's a node here*/
  {
    if (compare(my_key,(*root)->key) < 0) {/*If my key is smaller*/
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
			return root;/*Find node!*/
    }

  }
  else {
    return NULL;
  }
}

void freeTree(struct tree *root){
  if (root) {
    freeTree(root -> children[0]);
    freeTree(root -> children[1]);
    free(root);
  }
}
