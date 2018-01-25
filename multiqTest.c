#include "multiq.h"

MultiQ loadData(FILE* f){
	MultiQ mq = createMQ(SIZE);
	TaskID tid;
	Priority p;
	while (fscanf(f, "%ld,%d", &tid, &p) == 2){
		Task t = newTask(tid, p-1);
		mq = addMQ(mq, t);
	}
	return mq;
}

MultiQ testDel(MultiQ mq,int num){
	for (int i =0; i < num; i++){
		mq = delNextMQ(mq);
	}
	return mq;
}

int main(void)
{
	struct timeval t1, t2;
	double elapsedTime;

	MultiQ mq = createMQ(SIZE);
	printf("Empty: %d\n", isEmptyMQ(mq));
	printf("%d\n", isEmptyQ(*mq));
	Task t = newTask(11,0);
	mq = addMQ(mq, t);
	t = newTask(18,2);
	mq = addMQ(mq, t);
	t = newTask(20,1);
	mq = addMQ(mq, t);
	t = nextMQ(mq);
	printf("MQ next task %ld\n",t.tid);
	printf("Empty: %d\n", isEmptyMQ(mq));
	printf("Total length: %d\n", sizeMQ(mq));
	printf("Total length priority: %d\n", sizeMQbyPriority(mq, 0));
	mq = delNextMQ(mq);
	t = nextMQ(mq);
	printf("MQ next task %ld\n",t.tid);
	printf("Total length: %d\n", sizeMQ(mq));

	FILE* f = fopen("input10000.txt", "r");
	gettimeofday(&t1, NULL);
	mq = loadData(f);
	gettimeofday(&t2, NULL);
	fclose(f);
	printf("Total length: %d\n", sizeMQ(mq));
	t = nextMQ(mq);
	printf("MQ next task %ld\n",t.tid);
	mq = testDel(mq, 3);
	printf("Total length: %d\n", sizeMQ(mq));

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Total time is %f ms.\n", elapsedTime);
	return 0;
}