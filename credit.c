#include "credit.h"

Record* newRec(){
	Record* rd = (Record*)malloc(sizeof(Record));
	rd->code = (char*)malloc(5*sizeof(char));
	rd->first= (char*)malloc(5*sizeof(char));
	rd->last=(char*)malloc(5*sizeof(char));
	return rd;
}

void readFile(FILE* fp, Record** rd, int* size){

	int i;
	for (i = 0; !feof(fp); i++){
	/*	if (i >= *size){
			*size *= 2;
			printf("Test %d", *size);
			rd = (Record**)realloc(rd, *size*sizeof(Record*));
		}*/
		rd[i] = newRec();
		fscanf(fp,"\"%lu,%[^,],%d/%d,%[^,],%[^\"]\"\n",&rd[i]->crd_num,rd[i]->code,&rd[i]->dat.month,&rd[i]->dat.year,rd[i]->first,rd[i]->last);
	
	}
	*size = i;
}

void writeFile(FILE* fp, Record** rd, int size){
	int i;
	for (i = 0; i < size; i++){
	//printf("Write: %d\n",i);
		fprintf(fp,"\"%lu,%s,%d/%d,%s,%s\"\n",rd[i]->crd_num,rd[i]->code,rd[i]->dat.month,rd[i]->dat.year,rd[i]->first,rd[i]->last);
	}
}
void insertInOrder(Record** rd, int size, Record* rec){

		int i;
		for(i=size; i>0 && rec->crd_num<rd[i-1]->crd_num; i--)
			rd[i]=rd[i-1];		
		rd[i] = rec;
}

void insertionSort(Record** rd, int size){
		if(size <= 1) return;
		insertionSort(rd,size-1);
		Record* temp = rd[size-1];
		insertInOrder(rd,size-1,temp);
}
