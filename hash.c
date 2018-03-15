#include "hash.h"

int hashfn(char* str,  int baseNumber, int tableSize){
	int i, a, sum=0;
	for (i=0; str[i] != '\0'; i++){
		a = (int)str[i];
		sum += a;			
	}
printf("%d\n", sum);
	sum %= baseNumber;
	sum %= tableSize;
	return sum;
}

int collcnt (char** str_arr, int size, int baseNumber, int tableSize){
	int* num = malloc(sizeof(int)*size);	
	int i,j,cnt=0,  val;
	for (i = 0; i < size; i++){
		num[i]  = hashfn(str_arr[i], baseNumber, tableSize);
printf("%d %d\n", i, num[i]);
	}
	for (i = 0; i < size; i++)
		for (j=i+1; j < size; j++)
			if (num[i] == num[j] && num[j] != -1)
	{num[j] = -1;			cnt++;	
}
	return cnt;
}	

char** parse(FILE* fp){
	char** str_arr = malloc(10000*sizeof(char*));
	char* str;
	int i;
	for (i=0 ; !feof(fp); i++){
		
		fscanf(fp, "%s", str);
		if (checkString(str) == 0)
			{i--; continue;}
		str_arr[i] = malloc(strlen(str)*sizeof(char));
		strcpy(	str_arr[i] , str);

		printf("%s\n", str_arr[i]);

}		
	printf("No of valid strings: %d\n", i);
	return str_arr;
}
int checkString( char* s )
{
    while ( isalpha( *s ) ) ++s;

    return *s == '\0'; 
}
