#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hashfn(char* str, int baseNumber, int tableSize);
int collcnt (char** str_arr, int size, int baseNumber, int tableSize);
char** parse(FILE* fp);
int checkString( char* s );
int is_prime(int num);
void profile(char** ch_arr);

struct Node{
	int index;
	int count;
	struct Node* next;
};
typedef struct Node Node;

typedef struct
{
	Node** first;
	int elementCount;
	int insertionCost;
	int queryingCost;
} hashTable;

hashTable* createHT(int tableSize);
void insertHT(hashTable* h, char** ch_arr, int index);
int insertAll(hashTable* h, char** ch_arr, int size);
Node* lookup(hashTable* h, char* str, char** ch_arr);
