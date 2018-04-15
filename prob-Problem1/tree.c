/******************************************************
*           DSA Lab Test 2: Problem 1 (tree.c)
*   
*     Only fill up the missing function definitions.
* ****************************************************/
#include "tree.h"
#include "extras.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

unsigned int* createList(unsigned int p)
{
    unsigned int *list = NULL;
    
    // Write your code here.
	list = (unsigned int*)malloc(p*sizeof(unsigned int));
	int i;
	for (i=0; i< p; i++){
		list[i] = rand();
	}
    
    return list;
}

tree constructTree(unsigned int *list, unsigned int len)
{
    tree t = NULL;
	t = (tree)malloc(sizeof(struct _tnode));
	t->data = list[0];
	int val = rand()%3;
	if (val == 0){
		t->left = NULL;
		t->right = constructTree(list+1, len-1);
	}
	else if (val == 1){
		t->right = NULL;
		t->left = constructTree(list+1, len-1);
	}
	else{
		if (len%2 == 1){
			t->left = constructTree(list+1, (len-1)/2);
			t->right = constructTree(list+(len-1)/2 + 1, (len-1)/2);
		}
		else{
			t->left = constructTree(list+1, (len-1)/2);
			t->right = constructTree(list+(len-1)/2 +  1, (len+1)/2);
		}
	}

    return t;
}



bool matchTreeIterative(tree root, unsigned int *list, unsigned int size)
{
    bool status = false;
    /*if(root != NULL)
    {
	Stack st = push(newS(), root,  );
        printTreeInorder(root->left);
        printf("%u\t", root->data);
        printTreeInorder(root->right);
    }*/
    // Write your code here.

    return status;
}
