#include"linklist.h"


list* newlist(){
	list* ls = (list*)calloc(1,sizeof(list));
	return ls;
}

void ins(list* ls, node *new){
//	node* new = (node*)malloc(sizeof(node));
//	new->e = *e;
	//new->e = (Element*)malloc(sizeof(Element));
//	new->next = NULL;
		
	if(ls->length==0){
		ls->head = new;
		ls->tail = new;
		ls->length++;
		return;
	}
	ls->tail->next = new;
	ls->tail = new;
	ls->length++;
	return;
}

Element del(list* ls){
	if(ls->length>=1){
		node* temp = ls->head;
		Element e = temp->e;
		ls->head = ls->head->next;
		return e;
	}	
}

int isEmpty(list* ls){
	return !(ls->length);
}