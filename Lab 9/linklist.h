#include<stdio.h>
#include<stdlib.h>

#ifndef ELEMENT
#define ELEMENT
typedef struct{
	int e;
}Element;
#endif

typedef struct node{
	Element e;
	struct node* next;
}node;

typedef struct{
	node* head;
	node* tail;
	int length;
}list;


list* newlist();
void ins(list* ls, node *new);
Element del(list* ls);
int isEmpty(list* ls);