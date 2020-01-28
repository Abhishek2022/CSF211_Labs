#include<stdio.h>
#include<stdlib.h>
#include"MultiQ.h"

struct MultiQ* loadData(char* filename, int num)
{
	FILE *fptr = fopen(filename,"r");
	struct MultiQ* mq = createMQ(num);
	int tid,p;
	
	while(!feof(fptr))
	{
		fscanf(fptr,"%d, %d", &tid, &p);
		struct Task* t = (struct Task*) malloc(sizeof(struct Task));
		t->tid = tid;
		t->p = p;
		
		mq = addMQ(mq,t); 
	}	 
	return mq;
}

struct MultiQ* testDel(struct MultiQ* mq, int num)
{
	for(int i = 0; i < num; i++)
	{
		mq = delNextMQ(mq);
	}
	return mq;
}
		
int main()
{
	struct MultiQ *mq = loadData("input10.txt", 10);
	mq = testDel(mq,4);
	return 0;
}
