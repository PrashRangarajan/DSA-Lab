#include "MergeSort.h"
Element* readFile(FILE* fp, Element Ls[], int num){
	int i;
	for(i=0; !feof(fp) && i < num; i++){
		Element* el = (Element*)malloc(sizeof(Element));
		char* nam = (char*)malloc(sizeof(10*sizeof(char)));
		float f;
		printf("F befo %p\n",fp);
		fscanf(fp,"%[^,],%f\n",nam, &f );
		printf("F after  %p\n",fp);
		el->name = nam;
		el->cg = f;
		Ls[i] = *el;
	}
	
	/*if (i!=num){
		Element* Ls2 = (Element*)malloc(i*sizeof(Element));

		for(int j=0; j < i; j++)
			Ls2[j] = Ls[j];
		free(Ls);
		return Ls2;
	}*/
	return Ls;

}

void writeFile(FILE* fp, Element Ls[], int size){
	for (int i = 0; i < size; i++)
	       fprintf(fp,"%s,%f\n",Ls[i].name,Ls[i].cg);	
}
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	int i=0,j=0, k=0;
	if (sz2 == 0) 
		for (;i < sz1; i++)
			Ls[i] = Ls1[i];
	while(i<sz1 && j<sz2){		
	if (Ls1[i].cg<Ls2[j].cg){
			Ls[k++] = Ls1[i++];
			}
		else{
			Ls[k++] = Ls2[j++];
			}
	}

	while(i < sz1)
		Ls[k++] = Ls1[i++];
		
	while(j<sz2)
		Ls[k++] = Ls2[j++];
//	printArray(Ls, sz1+sz2);
}

void MSRec(Element Ls[], int size){
	int* a;
	printf("Outer: %p\n",a);
	if (size<=1){ 
	int* b;	printf("Inner: %p\n",b);
		return;
	}

	int mid = (size-1)/2;
	MSRec(Ls, mid+1);
	MSRec(Ls+mid+1,size-mid-1);
	Element Ls2[size];
	merge(Ls, mid+1, Ls+mid+1,size-mid-1,Ls2);
	for (int i=0; i<size;i++)
		Ls[i] = Ls2[i];
}

void printArray(Element A[], int size)
{
	    int i;
	    for (i=0; i < size; i++)		      
		    printf("Name: %s, CG: %f\n", A[i].name, A[i].cg);
}

void MSItr(Element Ls[], int n){
	Element* Ls2;
	int lsize, rsize;
	for(int size = 1; size < n; size*=2){
		Ls2 = (Element*)malloc(2*size*sizeof(Element));
		for (int iter = 0; iter < n/size; iter+=2){
//			printf("size: %d, iter = %d\n",size,iter);
			lsize = (iter+1)*size < n ? size : n - iter*size;
			rsize = (iter+1)*size < n ? ((iter+2)*size < n ? size : n - (iter + 1 ) * size) : 0;
//			printf("lsize = %d, rsize = %d\n",lsize, rsize);
			merge(Ls+iter*size, lsize, Ls+(iter+1)*size, rsize, Ls2);
			for (int i=0; i<lsize+rsize; i++){
				Ls[i+iter*size] = Ls2[i];
			}
		}
	free(Ls2);
	}




}

void createTempFile(FILE* fp, int K){
	Element* KArr; 
	FILE* fp2;
	char* ch = (char*)malloc(10*sizeof(char));
	for(int i = 0; !feof(fp); i++){
		KArr =	(Element*)malloc(K*sizeof(Element));
		KArr = readFile(fp,KArr,K);
		MSItr(KArr,K);
		sprintf(ch, "File_%d.txt", i);
		fp2 = fopen(ch,"w");
	//	printArray(KArr,K);
	//	printf("\n");
		writeFile(fp2,KArr,K);
		fclose(fp2);
		free(KArr);
	}	

}


void mergeFiles(FILE* fp1, FILE* fp2, FILE* fout){
	Element* el1 =  (Element*)malloc(sizeof(Element));
	Element* el2 =  (Element*)malloc(sizeof(Element));
	FILE* temp = fp1, *temp2 = fp2;
	while(!feof(fp1) && !feof(fp2)){
		printf("F befo %p\n",fp1);
	el1 = readFile(fp1,el1,1);
		printf("F after  %p\n",fp1);
	printArray(el1,1);
	printf("1\n");	
	el2 = readFile(fp2,el2,1);
	printArray(el2,1);
	printf("2\n %p", fp1);
	fp1 = temp;
	printf("Huh? %p\n", fp1);
	printArray(readFile(fp1,el1,1),1);
	fp2 = temp2;
		if (el1->cg <= el2->cg){
			writeFile(fout,el1,1);
			el1 = readFile(fp1,el1,1);
			temp = fp1;
			printf("Array 1: \n");
			printArray(el1,1);
			printf("Array 2: \n");
			printArray(el2,1);

			printf("i%d %d\n", feof(fp1), feof(fp2));
			printf("1-\n");
			}
		else{

			printf("i%d %d\n", feof(fp1), feof(fp2));
			writeFile(fout,el2,1);
			el2 = readFile(fp2,el2,1);
			temp2 = fp2;
			printf("Array 1: \n");
			printArray(el1,1);
			printf("Array 2: \n");
			printArray(el2,1);
			printf("i%d %d\n", feof(fp1), feof(fp2));
			printf("2-\n");
		}
	}
	printf("exit\n");
	/*do{
		writeFile(fout,el1,1);
		el1 = readFile(fp1,el1,1);
	}while (!feof(fp1));
	do{
		writeFile(fout,el2,1);
		el2 = readFile(fp2,el2,1);
	}while (!feof(fp2));*/
	while (!feof(fp1)){
		el1 = readFile(fp1,el1,1);
		writeFile(fout,el1,1);
	}	
	while (!feof(fp2)){
		el2 = readFile(fp2,el2,1);
		writeFile(fout,el2,1);
	}	


}
