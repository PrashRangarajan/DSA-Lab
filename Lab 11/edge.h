#include "dag.h"

typedef struct{
	Vertex* Vlist;
	Edge* Elist;
	int numV;
	int numE;
} Graph;

Graph* readFile(FILE* fp);
void getVertex(Vertex* v, int val);
Vertex* insert(Vertex* vl, Vertex* v,  int vnum);
int find(Vertex* Vlist, int val, int vnum);
int* indeg(Graph* g);
Vertex* topoSort(Graph* g);


