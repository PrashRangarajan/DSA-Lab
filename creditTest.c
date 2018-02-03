#include "credit.h"

int main(int argc, char** argv){
	FILE* fp = fopen("100", "r");
	int size = atoi(argv[1]);
	Record ** rdarr = (Record**)malloc(size*sizeof(Record*));
	readFile(fp, rdarr, &size);
	fclose(fp);
	insertionSort(rdarr, size);
	fp = fopen("op.txt","w");
	writeFile(fp,rdarr,size);
	fclose(fp);       






	return 0;
}
