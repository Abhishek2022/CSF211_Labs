#include<stdio.h>
#include<stdlib.h>
#include"que.h"

struct MultiQ{	
	struct Queue **quelist;
	int num;
};

struct Task{
	int tid;
	int p;
};

struct MultiQ* createMQ(int num);
struct MultiQ* addMQ(struct MultiQ *mq, struct Task* T);
struct Task* nextMQ(struct MultiQ* mq);
struct MultiQ* delNextMQ(struct MultiQ* mq);
int isEmptyMQ(struct MultiQ* mq);
int sizeMQ(struct MultiQ* mq);
int sizeMQbyPriority(struct MultiQ* mq, int p);
struct Queue* getQueueFromMQ(struct MultiQ* mq, int p);
