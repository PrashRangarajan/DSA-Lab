#include <stdio.h>
#include <stdlib.h>

struct Key{
	int key;
};
typedef struct Key Key;

struct Element{
	struct Key ky;
	int elem;
};
typedef struct Element Element;

struct Node{
	struct Element el;
	struct Node* next;
};
typedef struct Node Node;

typedef struct{
	int size;
	struct Node* head;
	struct Node* tail;
} SeqList;

Key newKey(int k);
int getKey(Node* nd);
Element newElement(Key ky, int el);
int getElement(Node* nd);


SeqList newList();
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element find(SeqList sl, Key k);
void printList(SeqList sl);

SeqList merge(SeqList sl1, SeqList sl2);
SeqList insertionSort(SeqList sl); 
