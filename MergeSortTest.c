#include "MergeSort.h"

int main(void){
	FILE* fp;
	/*fp = fopen("10.txt", "r");
	Element* el_arr = (Element*)malloc(7*sizeof(Element));
	
	el_arr = readFile(fp,el_arr); 
	fclose(fp); 
	Element* elel = (Element*)malloc(3000*sizeof(Element)); 
	merge(el_arr, 10, el_arr, 10, elel);
	for (int p=0; p<20; p++)
		printf("H %f\n",elel[p].cg);*/
	struct timeval t1, t2;
	double elapsedTime;
	Element* el_arr = (Element*)malloc(15*sizeof(Element));
	fp = fopen("15.txt","r");
	el_arr = readFile(fp,el_arr, 15); 
	gettimeofday(&t1, NULL);
	MSItr(el_arr,15);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time iterative is %lf ms.\n",elapsedTime);
			
	gettimeofday(&t1, NULL);
	MSRec(el_arr,15);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time recursive is %lf ms.\n",elapsedTime);
	printArray(el_arr,15);
	fclose(fp);
//	fp = fopen("15.txt","w");
//	writeFile(fp,el_arr,15);
	
//	fclose(fp);
	fp = fopen("15.txt","r");
	createTempFile(fp,3);
	FILE *fp1, *fp2, *fout;
	fp1 = fopen("File_0.txt","r");
	fp2 = fopen("File_2.txt","r");
	fout = fopen("File_Out.txt","w");
	printf("\n\n");
	mergeFiles(fp1, fp2, fout);
	fclose(fp1);
	fclose(fp2);
	fclose(fout);
	return 0;
	}
