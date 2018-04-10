#include "mergeSort.h"
#include<stdio.h>

void mergeFiles(FILE *f1, FILE *f2, FILE *f3)
{
	char c1[15], c2[15];
	float ft1, ft2;
	int size = 0;
	int flag = 0;
	fscanf(f1, "%15[^,], %f\n", c1, &ft1);
	fscanf(f2, "%15[^,], %f\n", c2, &ft2);
	while (1)
	{
		if (ft1<=ft2)
		{
			fprintf(f3, "%s,%f\n", c1, ft1);
			size++;
			if(!(fscanf(f1, "%15[^,], %f\n", c1, &ft1)>=1))
			{
				flag = 1;				
				break;
			}
		}
		else
		{
			fprintf(f3, "%s,%f\n", c2, ft2);
			size++;
			if(!(fscanf(f2, "%15[^,], %f\n", c2, &ft2)>=1))
			{
				flag = 2;				
				break;
			}
		}
	}
	if(flag == 2)
	{
		do
		{
			fprintf(f3, "%s,%f\n", c1, ft1);
			size++;
		}while(fscanf(f1, "%15[^,], %f\n", c1, &ft1)>=1);
	}
	else
	{
		do
		{
			fprintf(f3, "%s,%f\n", c2, ft2);
			size++;
		}while(fscanf(f2, "%15[^,], %f\n", c2, &ft2)>=1);
	}
}
void mergeSortFiles(int max_file)
{
	char c1[15];
	float ft1;	
	char filename[50];
	int filecount = max_file;
	FILE* results[max_file];
	char filename1[50], filename2[50];
	
	while(filecount!=1)
	{
		for(int i = 0; i < filecount; i++) 
		{
    			sprintf(filename, "results%03d", i);
    			results[i] = fopen(filename, "r");
		}		
		if (filecount%2==0)
		{
			for (int i = 0; i<filecount; i+=2)
			{
				FILE* temp = fopen("temp.txt", "w");
				mergeFiles(results[i], results[i+1], temp);
				fclose(results[i]);
				fclose(results[i+1]);
				fclose(temp);
				sprintf(filename1, "results%03d", i);
				remove(filename1);
				sprintf(filename2, "results%03d", i+1);
				remove(filename2);
				sprintf(filename1, "results%03d", (i/2));
				rename("temp.txt", filename1);
			}
			filecount/=2;
		}
		else
		{
			FILE* temp = fopen("temp.txt", "w");			
			mergeFiles(results[filecount-1], results[filecount-2], temp);
			fclose(results[filecount-1]);
			fclose(results[filecount-2]);
			fclose(temp);
			sprintf(filename1, "results%03d", filecount-1);
			remove(filename1);
			sprintf(filename2, "results%03d", filecount-2);
			remove(filename2);
			sprintf(filename2, "results%03d", filecount-2);
			rename("temp.txt", filename2);
			filecount--;
		}
	}
	fclose(results[0]);
	rename("results000", "Final Results");
	
}

int main()
{
	globalcnt = 0;
	FILE *fp = fopen("10240.txt", "r");
	int cutoff = 128;
	int max_file = 10240/cutoff;
	FILE* results[max_file];
	for(int i = 0; i < max_file; i++) 
	{
    		char filename[50];
		sprintf(filename, "results%03d", i);
    		results[i] = fopen(filename, "w");
	}
	char c[15];
	int size = 0, count = 0;
	float ft;
	int filecount = 0;
	Element *e = (Element*) myalloc(sizeof(Element)*cutoff);
	while(fscanf(fp, "%15[^,], %f\n", c, &ft)>=1)
	{
		e[count].name = (char*) myalloc (sizeof(char)*15);
		strcpy(e[count].name, c);
		e[count].cgpa = ft;
		count++;
		size++;
		if(count==cutoff)
		{
			recMergeSort(e, 0, cutoff-1);
			for(int i = 0; i<count; i++)
				fprintf(results[filecount], "%s,%f\n", e[i].name, e[i].cgpa);
			filecount++;		
			count = 0;
			myfree(e);
			Element *e = (Element*) myalloc(sizeof(Element)*cutoff);
		}
	}
	printf("%d \n", size);
	fclose(fp);
	for(int i = 0; i < max_file; i++) 
		fclose(results[i]);
	mergeSortFiles(max_file);
}
