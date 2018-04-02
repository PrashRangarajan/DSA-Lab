extern int MAX_HEIGHT = 5;
#include "nary.h"

Node createTree(int noc){
	}


Boolean isEmptyTree(Node nt){
	if (nt.noc == 0)
		return TRUE;
	else
	return FALSE;
	}

Element getRootVal(Node nt){
	return nt.val;
	}


Iterator getChildren(Node nt){
	return nt.it;
	}
