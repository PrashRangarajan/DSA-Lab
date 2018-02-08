#include "MergeSort.h"

int main(void){
	FILE* fp;
	fp = fopen("4.txt", "r");
	Element* el_arr = (Element*)malloc(2000*sizeof(Element));
	
	el_arr = readFile(fp,el_arr); 
	fclose(fp); 
	Element* elel = (Element*)malloc(3000*sizeof(Element)); 
	//Element** elel = &ell;
	elel = merge(el_arr, 4, el_arr, 4, elel);
	fp = fopen("1024.txt","r");
	el_arr = readFile(fp,el_arr); 
	el_arr = mergeSortRec(el_arr,0, 3);
	fclose(fp);
	for (int p=0; p<15; p++)
	printf("F %f\n",el_arr[p].cg);
	return 0;

	}
