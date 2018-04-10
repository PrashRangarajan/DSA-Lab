#include "hash.h"

int hashfn(char* str,  int baseNumber, int tableSize){
	int i, a; long sum=0;
	for (i=0; str[i] != '\0'; i++){
		a = (int)str[i];
		sum += a*i;			
	}
	sum *= 10003;
//printf("Sum = %d\n", sum);
	sum %= baseNumber;
	sum %= tableSize;
//printf("Sum after mod = %d\n", sum);
	return (int)sum;
}

int collcnt (char** str_arr, int size, int baseNumber, int tableSize){
	int* num = malloc(sizeof(int)*size);	
	int i,j,cnt=0,  val;
	for (i = 0; i < size; i++){
		num[i]  = hashfn(str_arr[i], baseNumber, tableSize);
//printf("Index: %d Value:%d\n", i, num[i]);
	}
	for (i = 0; i < size; i++)
		for (j=i+1; j < size; j++)
			if (num[i] == num[j] && num[j] != -1)
	{num[j] = -1;			cnt++;	
}
	return cnt;
}	

char** parse(FILE* fp){
	char** str_arr = (char**)malloc(100000*sizeof(char*));
	char* str;
	str = (char*)malloc(50*sizeof(char));
	int i;
	for (i=0 ; !feof(fp); i++){
		
		fscanf(fp, " %s", str);
	//printf("%s\n",str);
		if (checkString(str) == 0)
		{//str = (char*)malloc(30*sizeof(char));
		i--; continue;}
		str_arr[i] = (char*)malloc(strlen(str)*sizeof(char));
		strcpy(	str_arr[i] , str);

//		printf("%d %s\n", i ,str_arr[i]);

}		
	printf("No of valid strings: %d\n", i);
//	printf("End: %s\n",str_arr[0]);
	return str_arr;
}
int checkString(char* s)
{
    while (isalpha(*s)) ++s;
   	 return *s == '\0'; 
}
int is_prime(int num)
{
       	if (num <= 1) return 0;
	if (num % 2 == 0 && num > 2) return 0;
	for(int i = 3; i < num / 2; i+= 2)
		if (num % i == 0)
			return 0;
        return 1;
}
void profile(char** ch_arr){
	int tbarr[3] = {5001, 50001, 5000001};
	int bnarr[3][6];
	int i=0, j=0, k;
	for (k=0; k<3; k++){
		i=0;
	for (j=tbarr[k]; j <2*tbarr[k]; j++){
		if (is_prime(j))
			bnarr[k][i++] = j;
		if (i>2) break;
 	}
	j = tbarr[k]*500;
	while(j++){
		if (is_prime(j))
			bnarr[k][i++] = j;
		if (i>5) break;
	}
	}
	printf("Collision values are:\n");
	for (k=0; k<3; k++){
		for (i=0; i<6; i++)
			printf("Table size %d and base number %d = %d.\n", tbarr[k], bnarr[k][i], collcnt(ch_arr, 22699, bnarr[k][i], tbarr[k]));
	}
}

hashTable* createHT(int tableSize){
	hashTable* h = (hashTable*)malloc(sizeof(hashTable));
	h->elementCount = tableSize;
	h->insertionCost = 0;
	h->queryingCost = 0;
	h->first = (Node**)malloc(tableSize*sizeof(Node*));
	int i;
	for(int i; i < tableSize; i++)
		h->first[i] = NULL;
	return h;
}

void insertHT(hashTable* h, char** ch_arr, int index){
	
	Node* temp;
	int val = hashfn(ch_arr[index], 50001, h->elementCount);
	if (h->first[val] == NULL){
		h->first[val] = (Node*)malloc(sizeof(Node));
		temp = h->first[val];
		temp->index = index;
		temp->count = 1;
		temp->next = NULL;
		return;
	}
	temp = h->first[val];
	Node* previous = temp;
	while(temp != NULL){

		if (strcmp(ch_arr[temp->index], ch_arr[val])){
			temp->count++;	
			return;
		}
		h->insertionCost++;
		previous = temp;
		temp = temp -> next;

	}
	previous->next = (Node*)malloc(sizeof(Node));
	previous->next->index = index;
	previous->next->count = 1;
	previous->next->next = NULL;
	return;
}

int insertAll(hashTable* h, char** ch_arr, int size){
	int i;
	for(i=0;i<size;i++)
		insertHT(h,ch_arr,i);
	return h->insertionCost;
}

Node* lookup(hashTable* h, char* str, char** ch_arr){
	int val = hashfn(str, 50001, h->elementCount);
	Node* temp = h->first[val];
	while (temp != NULL){
		if (strcmp(ch_arr[temp->index], str)==0)
				return temp;
		temp = temp->next;
		h->queryingCost++;
	}
	h->queryingCost--;
	return NULL;
}
