#include "edge.h"

Graph* readFile(FILE* fp){
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->numV = 0;
	g->numE = 0;
	g->Elist = (Edge*)malloc(1000*sizeof(Edge));
	g->Vlist = (Vertex*)malloc(1000*sizeof(Vertex));
	Edge* e;
	int val1, val2, i;
	int vnum = 0;
	Vertex *v1, *v2;
	for(i=0; !feof(fp); i++){
		e = (Edge*)malloc(sizeof(Edge));
		fscanf(fp,"%d %d\n", &val1, &val2);
		v1 = (Vertex*)malloc(sizeof(Vertex));
		getVertex(v1, val1);
		int temp = find(g->Vlist, val1, vnum);
//		printf("v1 - %d - %d\n", val1, temp); 
		if (temp == -1){
			g->Vlist = insert(g->Vlist, v1, vnum);
			vnum++;
		}
		else
			*v1 = g->Vlist[temp];
		v2 = (Vertex*)malloc(sizeof(Vertex));
		getVertex(v2, val2);
		temp = find(g->Vlist, val2, vnum);
//		printf("v2 - %d - %d\n", val2, temp); 
		if (temp == -1){	
			g->Vlist = insert(g->Vlist, v2, vnum);
			vnum++;
		}
		else
			*v2 = g->Vlist[temp];
		e->v1 = v1;
		e->v2 = v2;
		g->Elist[i] = *e;
	}
	g->numV = vnum;
	g->numE = i;
	return g;
}

int find(Vertex* Vlist, int val, int vnum){
	if (Vlist == NULL || vnum == 0)
		return -1;
	int l =0;
	int r = vnum-1;
	while(l<=r){
		int m = l + (r-l)/2;
		if (Vlist[m] == val)
			return m;
		if (Vlist[m] < val)
			l = m+1;
		else
			r = m-1;
	}
	return -1;
}
	
Vertex* insert(Vertex* vl, Vertex* v,  int vnum){
	int i;
	for (i = vnum; i >0 && *v < vl[i-1]; i--){
		vl[i] = vl[i-1];
		}
	vl[i] = *v;
	return vl;
}
void getVertex(Vertex* v, int val){
	*v = val;
}

int* indeg(Graph* g){
	int i;
	int* degArr = (int*)calloc(g->numV, sizeof(int));
	for(i=0; i<g->numE; i++)
		degArr[find(g->Vlist, *(g->Elist[i].v2), g->numV)]++;
	return degArr;
}

Vertex* topoSort(Graph* g){
	Vertex* v = (Vertex*)malloc(g->numV*sizeof(Vertex));

	int* indg = indeg(g);
	int i, j, num=0;
	for(i=0; i<g->numV; i++){
		if (indg[i] == 0){
			v=insert(v,&g->Vlist[i], num++);
			indg[i] = -1;
			for(j=0; j<g->numE; j++){
				if (*(g->Elist[i].v1) == g->Vlist[i]){
				indg[find(g->Vlist, *(g->Elist[i].v2), g->numV)]--;
				}
			}
		}
	}
	return v;
}
