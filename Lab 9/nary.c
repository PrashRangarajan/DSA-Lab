int MAX_HEIGHT = 3;
#include "que.h"
Node createTreeAcc(int noc, int height){
	int i;
	Iterator it = createIter(noc);
	Node n = (Node)malloc(sizeof(struct ntree));
	n->val = rand()%20;
	if (height == 1){
		for (i=0; i<noc; i++)
			it = addIter(it, NULL);
		n->it = it;
		return n;
	}
	Node nt;
	for (i=0; i<noc; i++){
		nt = createTreeAcc(noc, height-1);	
		it = addIter(it,nt);

	}
	n->it = it;
	return n;
}
Node createTree(int noc){
	return createTreeAcc(noc, MAX_HEIGHT);
	}

Boolean isEmptyTree(Node nt){
	if (nt==NULL)
		return TRUE;
	else
		return FALSE;
	}

int getRootVal(Node nt){
	if (isEmptyTree(nt))
		return 0;
	return nt->val;
	}


Iterator getChildren(Node nt){
	return nt->it;
	}

Iterator createIter(int noc){
	Iterator* it = (Iterator*)malloc(sizeof(Iterator));
	it->size = noc;
	it->pos = 0;
	it->ele_arr = (Element*)malloc(noc*sizeof(Element));
	return *it;
}

Iterator addIter(Iterator it, Element e){
	it.ele_arr[it.pos++] = e;
	if (it.pos == it.size)
		it.pos = 0;

	return it;
}

void treeTraverse(Node nt){
	if (isEmptyTree(nt))
		return;
	Queue que = addQ(newQ(), nt);
	Node n;
	while(!isEmptyQ(que)){
		n = front(que);
		que = delQ(que);
		printf("%d\n", getRootVal(n));
		Iterator it = getChildren(n);
		while(hasMoreElements(it)){
		Element el = getNextElement(&it);
		if (el != NULL)
			que = addQ(que,el);
		}
	}
}


	
