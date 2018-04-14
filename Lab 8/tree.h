#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int root;
struct Tree{
	root val;
	struct Tree* left;
	struct Tree* right;
	int bal:2;
	int ht;
};
typedef struct Tree Tree;

int getrnd(int low, int high);

Tree* createNode(root rt, Tree* lf, Tree* rg);
Tree* add(Tree* t, root rt);
Tree* find(Tree* t, root rt);
void inOrder(Tree* t);
Tree* inOrderSucc(Tree* t);
Tree* delete(Tree* t, root node);
Tree* rotate(Tree* t, Tree* X, Tree* Y, Tree* Z, Tree* W);
int height(Tree* t);
int getBal(Tree* t);
int max(int a, int b);




