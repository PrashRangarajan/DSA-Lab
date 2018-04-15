/******************************************************
*           DSA Lab Test 2: Problem 2 (graph.c)
*   
*     Only fill up the missing function definitions.
* ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"
#include "extras.h"


Graph initGraph(int N)
{
    Graph g = NULL;
    
    // Write your code here.
    g = (Graph)malloc(sizeof(struct _Graph));
	g->vcount = N;
	g->ecount = 0;
	g->list = (node)calloc(N,sizeof(struct _node));
	int i;
	for (i = 0; i <N; i++)
		g->list[i].id = N;
	g->wt = (int*)malloc(N*sizeof(int)); 
	g->visited = (bool*)malloc(N*sizeof(bool));

    return g;
}
void printAdjacencyList(Graph g)
{
    // Write your code here.
	int i;
	printf("\n");
	for(i=0; i<g->vcount; i++){
		struct _node n = g->list[i];
		printf("%d\t(%d)  ==>  ", i, g->wt[i]);
		if (n.id == g->vcount){
			printf("\n");
			continue;
		}
		while(n.next != NULL){
			printf("%u\t", n.id);
			n = *(n.next);
		}
		printf("\n");
				
	}
}                                                                                                                                         

void insertEdge(Graph g, unsigned int u, unsigned int v)
{
    // Write your code here.

	if(g->list[u].id == g->vcount){
		g->list[u].id = v;
		g->list[u].next = NULL;
	}
	else{
		node n = (node)malloc(sizeof(struct _node));
		g->list[u] = *n;
		n->next = &(g->list[u]);
		n->id = v;

	}
	g->ecount++;
}
void bestFirstTraverse(Graph g, unsigned int root)
{
    // Write your code here.
}
