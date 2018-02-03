#include "Alloc.h"
<<<<<<< HEAD
size_t tspace = 0;
void* myalloc (size_t size){
	void* p = malloc(size+sizeof(size_t));
	if (p == NULL) return NULL;
	tspace += size;
//	printf("%lu\n",tspace);
	*(size_t*)p = size;
	return (p + sizeof(size_t));
}

void myfree(void* ptr){
	tspace -= *(size_t*)(ptr - sizeof(size_t));
	free(ptr - sizeof(size_t));
=======

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
>>>>>>> ae031808b0cdb05c0c1fb9e955268519e4ee90ce
}
