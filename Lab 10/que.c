#include "que.h"

Queue newQ(){
	Queue* q = (Queue*) malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return *q;

}

Boolean isEmptyQ(Queue q){
	if (q.size == 0) return true;
	else return false;

}

Queue delQ(Queue q){
	if (isEmptyQ(q)) return q;
	if (q.head->next == NULL) q.tail = NULL;
	q.head = q.head->next; 
	q.size--;
	return q;	

}

Element front(Queue q){
	return q.head->el;
} 

Queue addQ(Queue q, Element e){
	Node* nd = (Node*)malloc(sizeof(Node));
	nd -> el = e;
	nd -> next = NULL;
	if (isEmptyQ(q)){
		q.head = nd;
		q.tail = nd;
		q.size++;
		return q;
}
	q.tail->next = nd;
	q.tail = nd;
	q.size++;
	if (q.head == NULL)
		q.head = nd;
	return q;
}

int lengthQ(Queue q){
	return q.size;
}

