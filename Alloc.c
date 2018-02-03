#include "Alloc.h"
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
}
