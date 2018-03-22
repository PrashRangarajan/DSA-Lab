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
//	printf("%d\n", find(t, 163)->val);
	inOrder(t);




	return 0;
}
