#include <stdio.h>
#include <stdlib.h>
#include "Alloc.h"
#include <time.h>

typedef int Element;
typedef enum {FALSE, TRUE} Boolean;
struct Node{
	struct Node* next;
	Element e;

};
typedef struct Node Node;

typedef struct{
	Node* head;
	int size;

} List;

List* createList(int N);
List* createCycle(List* Ls);
Boolean testCyclic(List* Ls);
void traverseList(List* Ls, int n);
List* makeCircularList(List* Ls);
