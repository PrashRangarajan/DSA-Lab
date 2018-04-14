#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "nary.h"

struct qNode{
	struct qNode* next; 
	Element el; 

}; 
typedef struct qNode qNode;

struct Queue{
	qNode* head;
	qNode* tail;
	int size;
};
typedef struct Queue Queue;

Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);

