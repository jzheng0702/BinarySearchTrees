#include "common.h"

/*Helper function: This function will take three arguments,
a string that contains an entire line from the file,
another string where the column contents will be copied, and a column number. */
char* get_column(char* line, int columnNum) {
  int start,end,count,i,totalTab;
  char * columnContents;
  char buffer[MAX_LENGTH];

  /*find all the tabs*/
  totalTab = 0;
  for (i = 0; i < strlen(line);i++) {
    if (line[i] == '\t') {
      totalTab++;
    }
  }

  /*Last column, there is no tab character after the last column*/
  count = 0;
  start = 0;
  if (columnNum == totalTab) {
    for (i = 0; i < strlen(line); i++) {
      if (line[i] == '\t') {
        //printf("%d: tab\n",i);
        count++;
        if (count == columnNum) {
          start = i;
          end = strlen(line) - 1;
          i = MAX_LENGTH;
        }
      }
    }
  } else {
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
  }



  if(line[start] == '\t' || line[start] == ' ') {
    strncpy(buffer,line+start+1,end - start);
  } else {
    strncpy(buffer,line+start,end - start);
  }

  buffer[end - start] = '\0';
  //printf("My word is %s\n",buffer);
  columnContents = malloc(end - start + 1);
  strcpy(columnContents,buffer);

  return columnContents;
}
