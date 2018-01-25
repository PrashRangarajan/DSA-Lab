#include "que.h" 


int main(void){ 
	Queue q= newQ();
	Element e1 = 3, e2 = 4;
	q = addQ(q, e1);
	q = addQ(q, e2);
	q = addQ(q, e2);
	printf("%ld",q.head->el);	

}
