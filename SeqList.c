#include "SeqList.h"

Key newKey(int k){
	Key* ky = (Key*)malloc(sizeof(Key));
	ky ->key = k;
	return *ky;
}

int getKey(Node* nd){
	return nd->el.ky.key;
}


Element newElement(Key ky, int el){
	Element* e =(Element*)malloc(sizeof(Element));
	e->ky = ky;
	e->elem = el;
	return *e;
}

int getElement(Node* nd){
	return nd->el.elem;
}

SeqList newList(){
	SeqList* sl = (SeqList*)malloc(sizeof(SeqList));
	sl->size = 0;
	sl->head = NULL;
	sl->tail = NULL;
	return *sl;

}

SeqList insertAtFront(SeqList sl, Element e){
	Node* nd = (Node*)malloc(sizeof(Node));
	nd->el = e;
	nd->next = sl.head;
	sl.head = nd;
	sl.size++;
	if (sl.tail == NULL)
		sl.tail = nd;
	return sl;
}

SeqList insertAtEnd(SeqList sl, Element e){
	Node* nd = (Node*)malloc(sizeof(Node));
	nd -> el = e;
	nd -> next = NULL;
	sl.tail->next = nd;
	sl.tail = nd;
	sl.size++;
	if (sl.head == NULL)
		sl.head = nd;
	return sl;
}

SeqList insertInOrder(SeqList sl, Element e){
	Node* temp = sl.head;
	if (sl.head == NULL || e.ky.key < getKey(sl.head)){
		return insertAtFront(sl,e);
	}
	while(temp->next != NULL){
		if (e.ky.key < getKey(temp->next)){
			Node* nd = (Node*)malloc(sizeof(Node));
			nd -> el = e;
			nd->next = temp->next;
			temp->next = nd;
			sl.size++;
			return sl;
		}
		temp = temp->next;
	}
	return insertAtEnd(sl,e);
}


SeqList deleteAtFront(SeqList sl){
	if (sl.head == NULL){
		printf("The given list was empty!\n");
		return sl;
	}
	sl.head = sl.head->next;
	sl.size--;
	return sl;
}

SeqList delete(SeqList sl, Element e){
	if (sl.head == NULL){
		printf("The given list was empty!\n");
		return sl;
	}
	if (getKey(sl.head)==e.ky.key){
			sl.head = sl.head->next;
			sl.size--;
			return sl;
	}
	else{
		Node* temp = sl.head;
		while(temp->next != NULL){
			if (getKey(temp->next)==e.ky.key){
					printf("Element with value %d and key %d has been deleted!\n", e.elem, e.ky.key);
					temp->next = temp->next->next;
					sl.size--;
					return sl;
			}
			temp = temp->next;
		}	
	}
	printf("Element %d not found!\n", e.elem);
	return sl;
}

Element find(SeqList sl, Key k){
	Node* temp = sl.head;
	if (temp == NULL)
		printf("The list is empty.\n");
	while (temp != NULL){
		if (getKey(temp) == k.key)
			return temp->el;
		temp = temp->next;
	}
	return newElement(k,-1);
}

void printList(SeqList sl){
	Node* temp = sl.head;
	if (temp == NULL)
		printf("The list is empty.\n");
	printf("The list of size %d is as follows:\n", sl.size);
	while (temp != NULL){
		printf("Key: %d, Element: %d\n",getKey(temp),getElement(temp));
		temp = temp->next;
	}

}



