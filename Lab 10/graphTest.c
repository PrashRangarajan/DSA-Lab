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
	printMatrix(g);
	printf("%d", bfs(g, v1, v2));
}

