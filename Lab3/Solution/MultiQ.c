#include<stdio.h>
#include<stdlib.h>
#include"MultiQ.h"

struct MultiQ* createMQ(int num)
{
	struct MultiQ* mq = (struct MultiQ*) malloc(sizeof(struct MultiQ));
	mq->quelist = (struct Queue**) malloc(sizeof(struct Queue) * (num+1));
	mq->num = num;
	for(int i = 0; i <= num; i++)
	{
		mq->quelist[i] = newQ();
	}
	return mq;
}

struct MultiQ* addMQ(struct MultiQ *mq, struct Task* T)
{
	mq->quelist[T->p] = addQ(mq->quelist[T->p],T->tid);
	return mq;
}

struct Task* nextMQ(struct MultiQ* mq)
{
	int num = mq->num;
	struct Task* t = (struct Task*) malloc(sizeof(struct Task));
	t->tid = t->p = -1;
	for(int i = num; i >= 0; i--)
	{
		if(mq->quelist[i]->length > 0)
		{
			t->tid = front(mq->quelist[i]);
			t->p = i;
			break;	
		}
	}
	return t;
}

struct MultiQ* delNextMQ(struct MultiQ* mq)
{
	int num = mq->num;
	for(int i = num; i >= 0; i--)
	{
		if(mq->quelist[i]->length > 0)
		{
			mq->quelist[i] = delQ(mq->quelist[i]);
			break;	
		}
	}
	return mq;
}

int isEmptyMQ(struct MultiQ* mq)
{
	int num = mq->num;
	for(int i = 0; i <= num; i++)
	{
		if(mq->quelist[i]->length > 0) return 0;
	}	
	return 1;
}

int sizeMQ(struct MultiQ* mq)
{
	int num = mq->num;
	int count = 0;
	for(int i = 0; i <= num; i++)
	{
		count += mq->quelist[i]->length;
	}
	return count;
}

int sizeMQbyPriority(struct MultiQ* mq, int p)
{
	return mq->quelist[p]->length;
}

struct Queue* getQueueFromMQ(struct MultiQ* mq, int p)
{
	return mq->quelist[p];
}
