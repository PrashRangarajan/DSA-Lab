#include "multiq.h"

Task newTask(TaskID tid, Priority p){
	Task* t = (Task*)malloc(sizeof(Task));
	t->tid = tid;
	t->p = p;
	return *t;
}

MultiQ createMQ(int num){
	MultiQ mq = (MultiQ)malloc(num * sizeof(Queue));
	MultiQ mq2 = mq;
	int i;
	for (i =0; i< num; i++){
		Queue q = newQ();
		*mq = q;
		mq++;
	}

	return mq2;
}

MultiQ addMQ(MultiQ mq, Task t){
	Priority p = t.p;
	TaskID tid = t.tid;
	MultiQ temp = mq;
	temp += p;
	*temp = addQ(*temp, tid);
	return mq;

}

Task nextMQ(MultiQ mq){
	Priority p;
	for (p = SIZE-1; p >=0 ; p--){
		if(!isEmptyQ(mq[p])){
			TaskID tid = front(mq[p]);
			Task t = newTask(tid, p);
			return t;
		}

	}
	Task* t = (Task*)malloc(sizeof(Task));
	return *t;


}

MultiQ delNextMQ(MultiQ mq){
	Task t = nextMQ(mq);
	mq[t.p] = delQ(mq[t.p]);
	return mq;

}
Boolean isEmptyMQ(MultiQ mq){
	int i;
	for (i = 0; i < SIZE; i++){
		if (!isEmptyQ(mq[i]))
			return false;
	}
	return true;
}
int sizeMQ(MultiQ mq){
	int sum =0;
	for (int i = 0; i < SIZE; i++){
		sum += lengthQ(mq[i]);
	}
	return sum;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ(mq[p]);
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
	return mq[p];
}
