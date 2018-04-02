#include "Iter.h"

struct ntree{
	int val;
	Iterator it;
	int noc;
	};

typedef Element struct ntree*;
typedef struct ntree* Node;

Node createTree(int noc);
Boolean isEmptyTree(Node nt);
Element getRootVal(Node nt);
Iterator getChildren(Node nt);





