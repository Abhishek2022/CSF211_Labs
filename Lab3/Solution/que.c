#include<stdio.h>
#include<stdlib.h>
#include"que.h"

struct Queue* newQ()
{
	struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
	q->head = NULL;
	q->tail = NULL;
	q->length = 0;
	return q;
}

int isEmptyQ(struct Queue* q)
{
	return (q->length == 0);

}

struct Queue* delQ(struct Queue* q)
{
	if(q->head)  
	{
		q->head = q->head->next;
		q->length--;
	}
	return q;
}

int front(struct Queue* q)
{
	if(q->head) return q->head->element;
}

struct Queue* addQ(struct Queue* q, int e)
{
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->element = e;

	struct node* temp = q->head;
	while(temp->next != NULL) temp = temp->next; 
	
	temp->next = newnode;
	q->tail = newnode;
	q->length++;
	return q;
}

int lengthQ(struct Queue* q)
{
	return q->length;
}


