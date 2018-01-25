#include <stdio.h>
#include <stdlib.h>
#include "Alloc.h"

typedef int Element;
enum Boolean {FALSE, TRUE};
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
