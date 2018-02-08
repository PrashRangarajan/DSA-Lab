#include "MergeSort.h"

Element* readFile(FILE* fp, Element Ls[]){
	for(int i=0; !feof(fp); i++){
		Element* el = (Element*)malloc(sizeof(Element));
		char* nam = (char*)malloc(sizeof(10*sizeof(char)));
		float f;
		fscanf(fp,"%[^,],%f\n",nam, &f );
		el->name = nam;
		el->cg = f;
		Ls[i] = *el;
	}
	return Ls;
}


Element* merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	for(int p =0; p<sz2; p++)
	printf("%d. %f\n", p,Ls2[p].cg);
	int i=0,j=0, k=0;
	
	while(i<sz1 && j<sz2){		
	if (Ls1[i].cg<Ls2[j].cg){
			Ls[k] = Ls1[i];
			i++;
			k++;
			}
		else{
			Ls[k] = Ls2[j];
			j++;
			k++;
			}
	}

	while(i < sz1){
		Ls[k] = Ls1[i];
		i++;
		k++;
		}
	while(j<sz2){
		Ls[k] = Ls2[j];
		j++;
		k++;
		}

	return Ls;
}

Element* mergeSortRec(Element Ls[], int st, int end){
	if ((end-st)<1) return Ls;
	int mid = (end+st)/2;
	Element* Ls1 = mergeSortRec(Ls, st, mid);
	Element* Ls2 = mergeSortRec(Ls, mid+1, end);
	Element* Lsnew = merge(Ls1, mid-st, Ls2, end-mid-1, Ls);
	return Lsnew;



}
