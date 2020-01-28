#include<stdio.h>

struct node{
	int element;
	struct node *next;
};

struct Queue{
	struct node *head;
	struct node *tail;
	int length;
};

struct Queue* newQ();
int isEmptyQ(struct Queue* q);
struct Queue* delQ(struct Queue* q);
int front(struct Queue* q);
struct Queue* addQ(struct Queue* q, int e);
int lengthQ(struct Queue* q);


