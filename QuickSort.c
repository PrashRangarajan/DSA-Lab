#include "QuickSort.h"

Stack* newStack(){
	return  (Stack*)malloc(sizeof(Stack));
}

void push(Stack* s, int low, int high){
	Node* n = (Node*)malloc(sizeof(Node));
	n->low = low;
	n->high = high;
	n-> next = s->head;
	s->head = n;
	s->size++;
}

Node* top(Stack* s){
	return s->head;
}

void pop(Stack* s){
	if (s->head == NULL)
		return;
	Node* temp = s->head->next;
	free(s->head);
	s->head = temp;
	s->size--;
}

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

void swap(Emp** em, int ind1, int ind2){
	Emp* temp;
	temp = em[ind1];
	em[ind1] = em[ind2];
	em[ind2] = temp;

}

int partition (Emp** em, int  low, int high,int  pInt){
	int pPos; 
	swap(em, pInt, low);
	int lt=(low+1);       
	int rt=high; 
	Emp* pv=em[low];
	while (lt<rt) {
		for( ; lt<=high && em[lt]->empID<=pv->empID;lt++) ;          
		for( ; em[rt]->empID>pv->empID;rt--) ;                               
	if (lt<rt) 
		swap(em, lt++, rt--);
	}
	pPos = (lt == rt)? (em[lt]->empID < pv->empID ? lt : (lt-1)) : (lt-1);
	swap(em, low, pPos);
	return pPos;
}

void QSRec(Emp** em, int low, int high){
	if (low < high){ 
	int pPos = low + rand()%(high-low);
	pPos = partition(em, low, high, pPos);
	QSRec(em, low, pPos-1);
	QSRec(em, pPos+1, high);
	}
}

void QSIter(Emp** em, int low, int high, int lim){
	Stack* s = newStack();
	push(s, low, high);
	Node* n;
	int pPos;
	while(s->size != 0){
		n = top(s);
		pop(s);
		low = n->low;
		high = n->high;
		while( low < high){
			pPos = low + rand()%(high-low+1);
			pPos = partition(em, low, high, pPos);
			if  (pPos-1-low >= lim)
				push(s, low, pPos-1);
			low = pPos+1;
		}
	}
}

void testRun(Emp** em, int tot_size, int size, double* ISTime, double* QSTime){
//	Emp** em1 = (Emp**)malloc(2000*sizeof(Emp*));
//	memcpy(em1, em, sizeof(Emp));
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	QSIter(em, 0, tot_size-1, size);
	insertionSort(em, tot_size);
	gettimeofday(&t2, NULL);
	//printList(em, size);

	*QSTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	*QSTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	gettimeofday(&t1, NULL);
	insertionSort(em, size);
	gettimeofday(&t2, NULL);
	*ISTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	*ISTime += (t2.tv_usec - t1.tv_usec)/1000.0;
}

double estimateCutoff(Emp ** em, int tot_size, int low, int high){
	double *ISLow, *ISHigh, *QSLow, *QSHigh;
	ISLow = (double*)malloc(sizeof(double));
	ISHigh = (double*)malloc(sizeof(double));
	QSLow = (double*)malloc(sizeof(double));
	QSHigh = (double*)malloc(sizeof(double));
	FILE *fp = fopen("data.txt", "r");
	Emp** em2 = (Emp**)malloc(2000*sizeof(Emp*)); 
	readFile(fp, em2);
	fclose(fp);
	testRun(em, tot_size, low, ISLow, QSLow);
	testRun(em2, tot_size, high, ISHigh, QSHigh);
	printf("Values: ISH - %lf, QSH - %lf, ISL - %lf, QSL - %lf\n", *ISHigh, *QSHigh, *ISLow, *QSLow);

	for (int i = low; i < high; i+=20){
	FILE *fp = fopen("data.txt", "r");
	Emp** em2 = (Emp**)malloc(2000*sizeof(Emp*)); 
	readFile(fp, em2);
	testRun(em2, tot_size, i, ISLow, QSLow);
	fclose(fp);
	printf("IS: %lf, QS: %lf\n", *ISLow,*QSLow);
	free(em2);
	}


	if (*ISLow > *QSLow || *ISHigh < *QSHigh)
		return -1;
	int  mid;
	double* ISMid = (double*)malloc(sizeof(double));
	double* QSMid = (double*)malloc(sizeof(double));
	while(*ISLow < *QSLow && *ISHigh > *QSHigh){
		mid = (low+high)/2;
		testRun(em, tot_size, mid, ISMid, QSMid);
		if (*ISMid <= *QSMid){
			low = mid;
			QSLow = QSMid;
			ISLow = ISMid;
		}
		else{
			high = mid;
			QSHigh = QSMid;
			ISHigh = ISMid;
		}
	}
	return mid;
}
