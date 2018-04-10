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
		return t;
}	
Tree* add(Tree* t, root rt){
	if (t == NULL)
	{
		return createNode(rt, NULL, NULL);
	}
	if (t->val < rt){
		if (t->right == NULL){
			t->right = createNode(rt, NULL, NULL);
			}
		else{
			add(t->right, rt);
		}		
	}
	else{
		if (t->left == NULL){
			t->left = createNode(rt, NULL, NULL);
			}
		else
			add(t->left, rt);
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

Tree* inOrderSucc(Tree* t){
	t = t->right;
	if(t != NULL)
		while (t->left != NULL)
			t = t->left;
	return t;
}


Tree* delete(Tree* t, root node){
	Tree* temp = t;
	Tree* parent;
	int flag = 0;
	while (temp != NULL && !flag){
		if(node < temp->val){
			parent = temp;
			temp = temp->left;
		}
		else if(node > temp->val){
			parent = temp;
			temp = temp->right;
		}
		else{
			flag = 1;
		}

	}
	if (!flag){
		printf("Item not found.\n");
		return t;
	}
	if (temp == NULL)
		return t;
	if(temp->left == NULL && temp->right == NULL){
		if (parent->left == temp)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(temp);
		return t;
	}
	if (temp->left == NULL || temp->right == NULL){
		if (parent -> left == temp){
			if (temp->left == NULL)
				parent->left = temp->right;
			else
				parent->left = temp->left;
			}
		else{
			if(temp->left == NULL)
	
				parent->right = temp->right;
			else
				parent->right = temp->left;
			}
		free(temp);
		return t;
	}
	Tree* succ= inOrderSucc(temp);
	printf("P: %d", parent->val);
	root succ_val = succ->val;
	t = delete(t, succ->val);
	succ = createNode(succ_val, temp->left, temp->right);
	find(t, succ->val);
	if (parent->left == temp)
		parent->left = succ;
	else
		parent->right = succ;
	free(temp);
	return t;
}

Tree* rotate(Tree* t, Tree* X, Tree* Y, Tree* Z, Tree* W){
	Tree *a = X, *b = Y, *c = Z;
	Tree* temp;
	if (a->val < b->val){
		temp = a;
		a = b;
		b = temp;
	}
	if (a->val < c->val){
		temp = a;
		a = c;
		c = temp;
	}
	if (b->val < c->val){
		temp = b;
		b = c;
		c = temp;
	}
	Tree* T[4];
	T[0] = X->left;
	T[1] = X->right;
	if (Y->right == X)
		T[2] = Y->left;
	else
		T[2] = Y->right;
	if (Z->right == X)
		T[3] = Z->left;
	else
		T[3] = Z->right;
	int i, j;
	for (i = 1; i < 3 ; i--){
		for (j = i-1 ; T[i]->val < T[j]-> val &&  j >=0; j--)
			T[j+1] = T[j];
		T[j+1] = T[i];
	}
	
	if (W->left == Z)
		W->left = b;
	else
		W->right = b;

	b->left = a;
	b->right = c;
	a->left = T[0];
	a->right = T[1];
	c->left = T[2];
	c->right = T[3];
	return t;
}	


