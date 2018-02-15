#include "QuickSort.h"

int main (void){
	
	Emp** em = (Emp**)malloc(2000*sizeof(Emp*));
	FILE* fp;
	fp = fopen("data2.txt","r");
	readFile(fp, em);
	printList(em, 5); 
	//insertionSort(em, 2000);
	//printList(em, 2000); 
	QSRec(em, 0, 4);
	printList(em, 5); 
	fclose(fp);
	return 0;
}
