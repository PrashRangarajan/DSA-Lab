#include "tree.h"

int getrnd(int low, int high){
	return low + rand()%(high-low);
	}

Tree* createNode(root rt, Tree* lf, Tree* rg){
		Tree* t = (Tree*) malloc(sizeof(Tree));
		assert (t!=NULL);
		t->val = rt;
		t->left = lf;
		t->right = rg;
		int bal = 0;
}	
Tree* add(Tree* t, root rt){
	if (t == NULL)
	{
		return createNode(rt, NULL, NULL);
	}
	if (t->val < rt){
		if (t->right == NULL){
			t->right = createNode(rt, NULL, NULL);
			t->bal=1;
			}
		else{
			t->bal=1;
			add(t->right, rt);
		}		
	}
	else{
		if (t->left == NULL){
			t->left = createNode(rt, NULL, NULL);
			t->bal=-1;
			}
		else
		{	t->bal=-1;
			add(t->left, rt);
		}
}
	return t;

}
Tree* find(Tree* t, root rt){
	if (t == NULL){
		printf("Node not found!\n");
		return NULL;
		}
	if (t->val == rt)
		return t;
	else if (t->val < rt)
		return find(t->right, rt);
	else
		return find(t->left, rt);
}

void inOrder(Tree* t){
	while(t != NULL){
		printf("Move left.\n");
		inOrder(t->left);
		printf("Value: %d\n", t->val);
		printf("Move right.\n");
		t=t->right;
	}
	printf("NULL\n");
}	

Tree* inOrderSucc(Tree* par, Tree* t){
	if(t->right != NULL)
		return t->right;
}

Tree* delete(Tree* t, root node){
	Tree* t1 = find(t, node);
	if (t1 == NULL)
		return NULL;
	if(t1->left == NULL && t1->right == NULL)
		free(t1);
		return t;
