#include "LinkList.h"

List* createList(int N){
	List* l = (List*)myalloc(sizeof(List));
	l->size = 0;
	l->head = NULL;

	int i, num;
	Node* nd,*nxt; 
	nd = (Node*) myalloc(sizeof(Node));
	srand(time(NULL));
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
	FILE* f = fopen("TotSize.txt","w");
	fprintf(f, "The total size is %lu.\n", tspace);
	fclose(f);
	return l;

}

List* createCycle(List* Ls){
	srand(time(NULL));
	Boolean isLinear = rand()%2;
	if (isLinear == TRUE){
		return Ls;
	}
	else{
		int r = rand()%(Ls -> size);
		printf("Remain Linear? %d, r = %d.\n", isLinear, r);
		Node* temp = Ls->head;
		for (int i = 1; i < r; i++){
			temp = temp->next;
		}
		Node* last = Ls->head;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = temp;
		return Ls;
	}
}

void traverseList(List* Ls, int n){
	Node* temp = Ls->head;
	printf("The %d elements are:\n",n);
	for (int i=0; i<n; i++){
		if(temp == NULL) break;
		printf("#%d: %d\n", i+1, temp->e);
		temp = temp->next;
		
	}


}

List* makeCircularList(List* Ls){
	Boolean b = testCyclic(Ls);
	if (b == FALSE){
		Node* temp = Ls->head;
		if (temp == NULL)
			return Ls;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = Ls->head;
	}
	
	return Ls;




}
