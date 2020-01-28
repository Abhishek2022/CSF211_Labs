#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void insertFirst(struct linkedList * head, int ele){
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	link->element = ele;
	link->next = head->first;
	head -> first = link;
	head -> count++;
}

struct node* deleteFirst(struct linkedList * head){
	struct node *ptr = head->first;
	if(ptr != NULL)
	{
		head->first = ptr->next;
		head->count--;
	}
	return ptr;
}


void printList(struct linkedList * head){
	struct node *ptr = head->first;
	printf("\n[ ");

	while(ptr != NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}

int search (struct linkedList * head, int ele)
{
	int flag = 0;
	struct node *ptr = head->first;
	while(ptr != NULL){
		if(ptr->element == ele)
		{
			flag = 1; break;
		}
	}	
	return flag;
}

struct node* delete (struct linkedList * head, int ele)
{
	struct node *ptr = head->first;
	struct node *prev = head->first;
	
	if(ptr == NULL) return ptr;
	if(ptr->element = ele) return deleteFirst(head);
	ptr = ptr->next;

	while(ptr != NULL){
		if(ptr->element == ele)
		{
			prev->next = ptr->next;
			head->count--;
			return ptr;
		}
		prev = prev->next;
		ptr = ptr->next;
	}
}

