#include "SeqList.h"

SeqList merge(SeqList sl1, SeqList sl2){
	SeqList sl3 = newList();
	Node* temp = sl1.head;
	while (temp != NULL){
		sl3 = insertInOrder(sl3, temp->el);
		temp = temp -> next;
	}
	temp = sl2.head;
	while (temp != NULL){
		sl3 = insertInOrder(sl3, temp->el);
		temp = temp -> next;
	}
	return sl3;
}




SeqList insertionSort(SeqList sl){
	SeqList sl_new = newList();
	Node* temp = sl.head;
	while (temp != NULL){
		sl_new = insertInOrder(sl_new, temp->el);
		temp = temp -> next;
	}
	return sl_new;
}
