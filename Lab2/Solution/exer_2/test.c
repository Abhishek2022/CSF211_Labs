#include<stdio.h>
int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Not enough arguments\n");
		return 0;
	}
	
	FILE *readptr, *writeptr;
	readptr = fopen(argv[1],"r");
	writeptr = fopen(argv[2],"w");

	if(readptr == NULL)
	{
		printf("Unable to read\n");
		return 0;
	}

	if(writeptr == NULL)
	{
		printf("Unable to write\n");
		return 0;
	}

	char ch;
	while(fscanf(readptr,"%c",&ch)!=EOF)
	{
		fprintf(writeptr,"%c",ch);
	}
	fclose(readptr);
	fclose(writeptr);
}
