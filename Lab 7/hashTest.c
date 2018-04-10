#include "hash.h"

int main (void){
	char** str = malloc(10*sizeof(char*));
	int i;
	for(i=0; i<3; i++)
	str[i] = malloc(10*sizeof(char));
	strcpy(str[0], "spike");
	strcpy(str[1], "tom");
	strcpy(str[2], "jerry");
	
	char ch_arr[3][10] = {
                         "spike",
                         "tom",
                         "jerry"
    };
//	printf("%d\n", hashfn(ch_arr[0],  11, 10));
	printf("Test: %d\n", collcnt(str, 3, 11, 7));
	FILE* fp;
	fp = fopen("aliceinwonderland.txt", "r");
	str = parse(fp);
	printf("%s\n", str[0]);		
//	profile(str);
	hashTable* h = createHT(5000);
	printf("Insertion Cost: %d\n",insertAll(h, str, 22699)); 
	printf("Pos in table,Index ,Count \n");
	for(i=0; i < 5000; i++){
		Node* temp = h->first[i];
		while (temp !=NULL){
			printf("%d, %d, %d\n",i,temp->index, temp->count);
		temp = temp->next;
		}
	}
	printf("Lookup: %d\n", lookup(h, str[5], str)->index); 
	fclose(fp);


	return 0;
}
