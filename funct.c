int* mem_alloc(int n){
	int* num = (int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; i++){
		num[i] = i+1;
	}
}




int sum_arr(int arr[],int n)
{
int sum=0; 
int i;
for (i = 0; i <n; i++) 
{ 
	sum += i;

}
return sum;
}

int f1
