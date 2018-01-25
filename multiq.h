#include "que.h"
#define SIZE 10
typedef Element TaskID;
typedef int Priority;

typedef struct{
	TaskID tid;
	Priority p;
} Task;

typedef Queue* MultiQ;

Task newTask(TaskID tid, Priority p);

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);
