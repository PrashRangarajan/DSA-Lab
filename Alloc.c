#include "Alloc.h"

size_t tspace=0;

void* myalloc (size_t size){
	void* p = malloc(size);
	tspace += size;
	return p;
}

void myfree(void* ptr, size_t size){
	free(ptr);
	tspace -= size;
}

void lpalloc(void){
	for (int i = 0; i< 10000; i++){	
	int M= rand()%15000 + 10000;
	int* in = (int*)myalloc(M* sizeof(int));
	printf("M - %d, First - %p and Last - %p\n", M, in, in+M-1);
	myfree(in, M*sizeof(int));
}
}
