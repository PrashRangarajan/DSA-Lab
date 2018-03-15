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
	printf("%d\n", hashfn(ch_arr[0],  11, 10));
	printf("%d\n", collcnt(str, 3, 11, 5));
	FILE* fp;
	fp = fopen("alice.txt", "r");
	str = parse(fp);
	printf("%s", str[0]);		


	return 0;
}
