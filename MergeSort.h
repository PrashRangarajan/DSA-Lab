#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char* name;
	float cg;
} Element;

Element* merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
Element* readFile(FILE* fp, Element Ls[]);
Element* mergeSortRec(Element Ls[], int st, int end);
