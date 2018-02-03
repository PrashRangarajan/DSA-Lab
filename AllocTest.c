#include "Alloc.h"

int main(void){
<<<<<<< HEAD
	int M = 10000;
	int* in;
	do{
        //M= rand()%150000 + 10000;
	M *= 2;
        in = (int*)myalloc(M* sizeof(int));
        //myfree(in);
        printf("M - %d, First - %p and Last - %p\n, Max Size - %lu\n", M, in, in+M-1, tspace);	

}while(in != NULL);
return 0;
=======
	lpalloc();	



>>>>>>> ae031808b0cdb05c0c1fb9e955268519e4ee90ce
}
