#include "Iter.h"

struct ntree{
	int val;
	Iterator it;
	};

typedef struct ntree* Element;
typedef struct ntree* Node;

Node createTreeAcc(int noc, int height);
Node createTree(int noc);
Boolean isEmptyTree(Node nt);
int getRootVal(Node nt);
Iterator getChildren(Node nt);
Iterator addIter(Iterator it, Element e);
Iterator createIter(int noc);
void treeTraverse(Node nt);





