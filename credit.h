#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int month;
	int year;
} date;

typedef struct{
	long unsigned int crd_num;
	char* code;
	date dat;
	char* first;
	char* last;
} Record;

Record* newRec();
void readFile(FILE* fp, Record** rdarr, int* size);
void writeFile(FILE* fp, Record** rd, int size);

void insertInOrder(Record** rd, int size, Record* rec);
void insertionSort(Record** rd, int size);
