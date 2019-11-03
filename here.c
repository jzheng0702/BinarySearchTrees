#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  printf("> ");
  char input[100];
  char before[100];
  char* strptr;
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
  printf("input\n");
  for ( i = 0; i < strlen(before);i++) {
    printf("%d: %c\n",(i+1),before[i]);
  }

  printf("after\n");
  for ( i = 0; i < strlen(strptr);i++) {
    printf("%d: %c\n",(i+1),strptr[i]);
  }
  printf("%s\n",strptr);










  return (0);
}
