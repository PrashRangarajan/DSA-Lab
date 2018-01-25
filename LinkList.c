#include "LinkList.h"

List* createList(int N){
	List* l = (List*)myalloc(sizeof(List));
	l->size = 0;
	l->head = NULL;

	int i, num;
	Node* nd, nxt; 
	nd = (Node*) myalloc(sizeof(Node));
	nd -> e = rand()%1000;
	l -> head = nd;
	nxt = nd;
	l -> size++;
	for (i = 1; i < N; i++){
		num= rand()%1000;
		nd = (Node*)myalloc(sizeof(Node));
		nxt->next = nd;
		nd -> e = num;
		nxt = nd;
		l->size++;
	}
	nxt -> next = NULL;
	return l;

}

List* createCycle(List* Ls){
	int i = rand()%2;



}
