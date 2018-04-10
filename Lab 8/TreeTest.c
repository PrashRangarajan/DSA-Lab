#include "tree.h"

int main(void){
	int i, val;
	Tree* t;
	for (i=0; i < 5; i++){
		val = getrnd(150, 170);
		printf("%d\n", val);
		t = add(t, val);
	}
	printf("%d\n", t->right->val);
	printf("Found: %d\n", find(t, 163)->val);
	inOrder(t);
	printf("\n\n\n");
	inOrder(delete(t, 163));
	//t = rotate(t, find(t, 168), find(t, 160), find(t, 159), find(t, 157)); 



	return 0;
}
