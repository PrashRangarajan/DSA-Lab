#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "graph.h"

typedef Vertex Element;
struct Node{
	struct Node* next; 
	Element el; 

}; 
typedef struct Node Node;

struct Queue{
	Node* head;
	Node* tail;
	int size;
};
typedef struct Queue Queue;


Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);
