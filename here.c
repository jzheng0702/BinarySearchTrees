#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  printf("> ");
  char input[100];
  char before[100];
  char* strptr;
  char * key;
  int i;

  fgets(input, 100, stdin);
  strcpy(before,input);

  strptr = input;
  while(*strptr == ' ') {
    strptr++;
  }

  for (i = strlen(strptr) - 1; i >= 0; i--) {
    if (isalpha(strptr[i]) == 0) {
    } else {
      break;
    }
  }
  strptr[i + 1] = '\0';

  key = strptr;
  /*escape the first word*/
  while(*key != ' ') {
    key++;
  }

  /*escape the spaces after the first word*/
  while(*key == ' ') {
    key++;
  }
  printf("%s\n",key );

  if(strncmp(strptr,"name",4) == 0){
    printf("yes\n");
  }
  if(strncmp(strptr,"title",5) == 0){
    printf("title\n");
  }


  printf("input\n");
  for ( i = 0; i < strlen(before);i++) {
    printf("%d: %c\n",(i+1),before[i]);
  }

  printf("after\n");
  for ( i = 0; i < strlen(key);i++) {
    printf("%d: %c\n",(i+1),key[i]);
  }
  printf("%s\n",key);










  return (0);
}
