#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

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
		push(head,temp);
	}
	fclose(fileptr);

	printf("Performing pop operations.... \n\n");
	int count = 1;
	while(head->first!=NULL)
	{
		printf("Stack after pop %d", count++);
		pop(head);
		printStack(head);
		printf("\n");
	}
}
