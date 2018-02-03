#include "Linklist.h"

Boolean testCyclic(List* Ls){
	Node* first = Ls->head, *second, *third;
	if (first== NULL || first->next == NULL || first->next->next == NULL || first->next->next->next == NULL)
		return FALSE;
	second = first->next;
	third = second->next;
	second->next = first;
	Node* first2 = first;
	first->next= NULL;
	first = second;
	second = third;
	third = third->next;
	while (third != first2){
		if (third == NULL)
			return FALSE;
		second->next = first;
		first = second;
		second = third;
		third = third->next;
		}
	return TRUE;
}
