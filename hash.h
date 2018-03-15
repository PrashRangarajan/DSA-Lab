#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hashfn(char* str, int baseNumber, int tableSize);
int collcnt (char** str_arr, int size, int baseNumber, int tableSize);
char** parse(FILE* fp);
int checkString( char* s );


