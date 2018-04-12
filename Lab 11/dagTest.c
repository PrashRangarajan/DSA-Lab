#include "edge.h"

int main(void){
	FILE* fp = fopen("graph0.txt", "r");
	Graph* g = readFile(fp);	
	int i;
	printf("Set of edges:\n");
	for (i=0; i<g->numE; i++){
		printf("%d %d\n", *(g->Elist[i].v1), *(g->Elist[i].v2));
		}
	printf("Set of vertices:\n");
	int* da = indeg(g);
	for (i=0; i<g->numV; i++)
		printf("%d Deg:%d\n", g->Vlist[i], da[i]);
	int* sorted = topoSort(g);
	for (i=0; i<g->numV; i++)
		printf("%d \n", sorted[i]);

	fclose(fp);


	return 0;
}
