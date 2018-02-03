#include "Linklist.h"

Boolean testCyclic(List* Ls){
	Node *hare = Ls->head, *tort = Ls->head;
	if (hare == NULL || hare->next == NULL || hare->next->next == NULL)
		return FALSE;
	hare = hare->next->next;
	tort = tort->next;
	while(1){
		if (hare == NULL || hare->next == NULL || hare->next->next == NULL)
			return FALSE;
		if (hare== tort|| hare->next== tort)
			return TRUE;
		hare = hare->next->next;
		tort = tort -> next;
	}
}


