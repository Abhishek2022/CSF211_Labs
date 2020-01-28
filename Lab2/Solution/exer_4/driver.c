#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
int main(int argc, char *argv[])
{	
	if(argc == 1)
	{
		printf("No input file");
		return 0;
	}

	FILE * fileptr = fopen(argv[1], "r");
	if(fileptr == NULL)
	{
		printf("Cannot read file\n");
		return 0;
	}
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	while (!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);
		insertFirst(head,temp);
	}
	fclose(fileptr);

	// print the linked list.
	printList(head);
	
	// delete the first element of the linked list.
	struct node* temp = deleteFirst(head);

	// print the linked list again to check if delete was successful.
	printList(head);
	
	// print the linked list to a new file.
	FILE *newptr = fopen("newfile.txt","w");
	if(newptr == NULL)
	{
		printf("Cannot write on file\n");
		return 0;
	}

	struct node* ptr = head->first;
	while(ptr!=NULL)
	{
		fprintf(newptr,"%d\n",ptr->element);
		ptr = ptr->next;
	}
	fclose(newptr);		
}
