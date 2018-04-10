#include "que.h"

int getval(Vertex v){
	return v.val;
	}

Graph* createGraph(int numV){
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->numEdge = 0;
	g->numVert = numV;
	g->Matrix = (int**)malloc(numV*sizeof(int*));
	int i, j;
	for (i=0; i < numV; i++){
		g->Matrix[i] = (int*)calloc(numV,sizeof(int));
		}	
	return g;
}

Vertex* getAdjacent (Graph* g, Vertex v){
	int val = getval(v);
	int cnt = degree(g, v);
	Vertex* vArr = (Vertex*)malloc(cnt*sizeof(Vertex));
	int j =0;
	for (int i=0; i<g->numVert; i++){
		if(g->Matrix[val][i] == 1){
			Vertex *v2 = (Vertex*)malloc(sizeof(Vertex));;
			v2->val = i;
			vArr[j++] = *v2;
			}
		}
	return vArr;
}

Graph* addEdge(Graph* g, Vertex v, Vertex vAdj){
	g->numEdge++;
	g->Matrix[getval(v)][getval(vAdj)]=1;
	return g;
	}

int degree (Graph* g, Vertex v){
	int i, cnt=0;
	for (i=0; i < g->numVert; i++){
		if (g->Matrix[getval(v)][i] == 1){
			cnt++;
			}
	}
	return cnt;
}
	

void printMatrix(Graph* g){
	printf("The adjacency matrix is:\n");
	int i,j;
	for (i=0; i < g->numVert; i++){
		for(j=0; j<g->numVert; j++)
			printf("%d ", g->Matrix[i][j]);
		printf("\n");
	}
}

Boolean bfs(Graph* g, Vertex v, Vertex tf){
	int num = g->numVert;
	Boolean** visited = (Boolean**)malloc(num*sizeof(Boolean*));
	Boolean* visitVert = (Boolean*)calloc(num, sizeof(Boolean));
	int i;
	for (i = 0; i < num; i++){
		visited[i] = (Boolean*)calloc(num,sizeof(Boolean));	
		}
	Queue q = addQ(newQ(), v);
	
	while(!isEmptyQ(q)){
		Vertex u = front(q);
		int val = getval(u);
		q = delQ(q);
		Vertex* vArr = getAdjacent(g, u);
		int deg = degree(g, v);
		int i, valw;
		for (i= 0; i < deg; i++){
			valw = getval(vArr[i]);
		if (visited[val][valw] == false){
			if (!visitVert[valw]){
				visitVert[valw] = true;
				visited[val][valw] = true;
			Vertex *v2 = (Vertex*)malloc(sizeof(Vertex));
			v2->val = valw;
			q = addQ(q, *v2);
			if (getval(*v2) == getval(tf))
			return true;
			}
			}
			}
			}
return false;

}
