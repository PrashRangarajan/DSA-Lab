#include "QuickSort.h"

void readFile(FILE* f, Emp** em){
	for (int i = 0; 1; i++){
		em[i] = (Emp*)malloc(sizeof(Emp));
		em[i]->name = (char*)malloc(10*sizeof(char));
	if(fscanf(f, "%s %ld\n", em[i]->name, &em[i]->empID) != 2)
	break;

}
}

void printList(Emp** em, int size){
	printf("The list of size %d is:\n", size);
	for (int i = 0; i < size; i++)
		printf("%s %ld\n", em[i]->name, em[i]->empID);
}

void insertionSort(Emp **em, int size){
	Emp* temp;	
	int i,j;
	for (i = 1; i < size; i++){
		temp = em[i];
		j = i-1;
		while (j >= 0 && (em[j]->empID > temp->empID)){
				em[j+1] = em[j];
				j--;	
		}
		em[j+1] = temp;
		}



}

void swap(Emp*  e1, Emp* e2){
	Emp* temp;
	temp = e1;
	e1 = e2;
	e2 = temp;

}

int partition (Emp** em, int  low, int high,int  pInt){
	int pPos; 
	swap(em[pInt],em[low]);
	int lt=low+1;       
	int rt=high; 
	Emp* pv=em[low];
	while (lt<rt) {
		for( ; lt<=high && em[lt]->empID<=pv->empID;lt++) ;          
		for( ; em[rt]->empID>pv->empID;rt--) ;                               
	if (lt<rt) {
		swap(em[lt], em[rt]);
		lt++;
		rt--;
	}
	}
	if (lt == rt)
		pPos = lt;
	else
		pPos = lt -1;
	swap(em[low], em[pPos]);
	return pPos;
}

void QSRec(Emp** em, int low, int high){
	if (low < high){ 
	int pInt = low + rand()%(high-low);
	int pPos = partition(em, low, high, pInt);
	printf("%d %d %d %d\n", low, high, pInt, pPos);
//	QSRec(em, low, pPos-1);
//	QSRec(em, pPos+1, high);
	}
}
