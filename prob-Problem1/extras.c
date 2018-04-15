/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.c)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/
#include "extras.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

// Write your code here.

Stack push(Stack s, int p, unsigned int val){
	int i ;
	for (i = s.size; i>0; i--){
		s.arr[i] = s.arr[i-1];
	}
	s.arr[0] = val;
	s.pointer = p;
}


Stack newS(int size){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->arr = (unsigned int*)(size*sizeof(unsigned int));
	return *s;
}


unsigned int top(Stack s, int* p){
	if (s.pointer == 1) *p=1;
	else *p = 0;
	return s.arr[0];
}

Stack pop (Stack s){
	int i;
	for (i = 0; i<s.size-1; i++){
		s.arr[i+1] = s.arr[i];
	}
	return s;
}
