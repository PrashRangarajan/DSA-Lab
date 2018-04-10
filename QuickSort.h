#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct{
	char* name;
	long int empID;
} Emp;

void readFile(FILE* f, Emp** em );
void printList(Emp** em, int size);
void insertionSort(Emp **em, int size);

void swap(Emp** em, int ind1, int ind2);
int partition (Emp** em, int  low, int high,int  pInt);
void QSRec(Emp** em, int low, int high);
void QSIter(Emp** em, int low, int high, int lim);
void testRun(Emp** em, int tot_size, int size, double* ISTime, double* QSTime);
double estimateCutoff(Emp ** em, int tot_size, int low, int high);

struct Node{
	int low;
	int high;
	struct Node* next;
};
typedef struct Node Node;

typedef struct{
	Node* head;
	int size;
} Stack;

void push(Stack* s, int low, int high);
Node* top(Stack* s);
void pop(Stack* s);
Stack* newStack();
