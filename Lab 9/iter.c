#include "Iter.h"

Boolean hasMoreElements(Iterator it){
	if (it.pos < it.size)	
		return TRUE;
		
	else
		return FALSE;
}

Element getNextElement(Iterator* it){
	return it->ele_arr[it->pos++];
	}

