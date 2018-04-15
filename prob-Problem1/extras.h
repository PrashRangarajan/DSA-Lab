/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.h)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/

#include "tree.h"
#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED
	
// Write your code here.
	typedef struct{
		unsigned int* arr;
		int size;
		int pointer;
	} Stack;
	Stack newS(int size);
	Stack push(Stack s, int p, unsigned int val);
	unsigned int top(Stack s, int* p);
	Stack pop (Stack s);
#endif // EXTRAS_H_INCLUDED
