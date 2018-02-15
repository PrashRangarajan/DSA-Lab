#include <stdio.h>
#include <stdlib.h>
//#include "SeqList.h"

typedef struct{
	char* name;
	long int empID;
} Emp;

void readFile(FILE* f, Emp** em );
void printList(Emp** em, int size);
void insertionSort(Emp **em, int size);

void swap(Emp*  e1, Emp* e2);
int partition (Emp** em, int  low, int high,int  pInt);
void QSRec(Emp** em, int low, int high);
