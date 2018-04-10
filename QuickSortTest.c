#include "QuickSort.h"

int main (void){
	
	Emp** em = (Emp**)malloc(2000*sizeof(Emp*));
	FILE* fp;
	fp = fopen("data.txt","r");
	readFile(fp, em);
//	printList(em, 2000); 
//	QSRec(em, 0, 4);
	//printf("f\n");
	/*QSIter(em, 0, 1999, 2);
	insertionSort(em, 2000);*/
	double* ISTime, *QSTime;
	ISTime = (double*)malloc(sizeof(double));
	QSTime = (double*)malloc(sizeof(double));
//	testRun(em, 2000, 2000,ISTime, QSTime);
//	printList(em, 2000); 
//	printf("%lf, %lf\n", *ISTime, *QSTime);
	fclose(fp);
	printf("Cutoff: %lf\n",estimateCutoff(em,2000, 3, 1999));
	Stack* s = newStack();
	push(s, 1, 2);
	push(s, 1, 2);
	pop(s);
	push(s, 5, 4);
	printf("%d %d %d\n", s->head->low, s->head->high, s->size);
//	QSIter(em, 0, 1999, 0);
//	printList(em, 2000);
//	insertionSort(em, 2000);
//	printList(em, 2000);
	return 0;
}
