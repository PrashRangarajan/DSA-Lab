#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct{
	char* name;
	float cg;
} Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
Element* readFile(FILE* fp, Element Ls[], int num);
void  writeFile(FILE* fp, Element Ls[], int size);
Element* mergeSortRec(Element Ls[], int st, int end);
void MSRec(Element Ls[], int size);
void MSItr(Element Ls[], int n);
void printArray(Element A[], int size);
void createTempFile(FILE* fp, int K);
void mergeFiles(FILE* fp1, FILE* fp2, FILE* fout);

