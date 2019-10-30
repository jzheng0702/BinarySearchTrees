#include "common.h"

/*Helper function: This function will take three arguments,
a string that contains an entire line from the file,
another string where the column contents will be copied, and a column number. */
char* get_column(char* line, int columnNum) {
  int start,end,count,i;
  char * columnContents;
  char buffer[MAX_LENGTH];

  /*find the tabs*/
  count = 0;
  start = 0;
  for (i = 0; i < strlen(line);i++) {
    if (line[i] == '\t') {
      count++;
      if (count == columnNum + 1) {
        end = i;
        i = MAX_LENGTH;
      } else if (count == columnNum) {
        start = i;
      }
    }

  }

  if(line[start] == '\t' || line[start] == ' ') {
    strncpy(buffer,line+start+1,end - start);
  } else {
    strncpy(buffer,line+start,end - start);
  }

  buffer[end - start] = '\0';
  columnContents = malloc(end - start + 1);
  strcpy(columnContents,buffer);

  return columnContents;
}
