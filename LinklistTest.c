#include "LinkList.h"

int main(void){
	List * Ls = createList(20);	
	Ls = createCycle(Ls);
	traverseList(Ls, 80);	
	printf("Cyclic: %d.\n",testCyclic(Ls));
	Ls = makeCircularList(Ls);
//	printf("Cyclic: %d.\n",testCyclic(Ls));

}
