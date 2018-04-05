#include <stdio.h>
#include <stdlib.h>

typedef struct {int val;} Vertex;

typedef struct{
	int** Matrix;
	int numVert;
	int numEdge;
	} Graph;
//typedef Vertex* Enumeration; 
typedef enum {false, true} Boolean;

int getval(Vertex v);
Graph* createGraph(int numV);
Vertex* getAdjacent (Graph* g, Vertex v);
Graph* addEdge(Graph* g, Vertex v, Vertex vAdj);
int degree (Graph* g, Vertex v);
void printMatrix(Graph* g);
Boolean bfs(Graph* g, Vertex v, Vertex tf);
