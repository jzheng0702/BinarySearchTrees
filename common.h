/*Jingjing Zheng
ID: 1043704
email:jzheng06@uoguelph.ca*/
#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "binary.h"
#include "name.h"
#include "principals.h"
#include "title.h"

#define MAX_LENGTH 1024




char* get_column(char* line, int columnNum);
char* reverseString(char* myString);
char* strdup(char* s);



#endif
