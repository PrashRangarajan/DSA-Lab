#include "graph.h"


int main(void){
	Graph* g = createGraph(5);
	Vertex v1, v2;
	v1.val = 1;
	v2.val = 2;
	g = addEdge(g, v1, v2);
	v1.val = 0;
	v2.val = 4;
	g = addEdge(g, v1, v2);
	v2.val = 3;
	g = addEdge(g, v1, v2);
	v1.val = 3;
	v2.val = 1;
	g = addEdge(g, v1, v2);
	v1.val = 0;
	v2.val = 1;
	printMatrix(g);
	printf("%d\n", bfs(g, v1, v2));
	int vl = degree(g, v1);
	printf("Deg: %d\n", vl);
	Vertex* vArr = getAdjacent(g, v1);
	printf("%d\n", vArr[1].val);

}

