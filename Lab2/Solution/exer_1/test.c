EXERCISE 1A
-- The value of argc will be 1.



EXERCISE 1B
#include<stdio.h>
int main(int argc, char *argv[])
{
	for(int i =0 ;i < argc; i++)
	{
		if(i == 0) printf("%s ", argv[0] + 2);
		else printf("%s ",argv[i]);
	}
}


EXERCISE 1C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int integer(char *str, int n)
{
	int flag = 1;
	for(int i = 0; i<n; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			flag = 0;
	}
	return flag;
}

int main(int argc, char *argv[])
{
	for(int i =0 ;i < argc; i++)
	{
		int len = sizeof(argv[i])/sizeof(char);

		if(i == 0) printf("%s ", argv[0] + 2);

		else if(integer(argv[i],len))
		{
			int val = atoi(argv[i]);
			printf("%d ",val);
		}

		else printf("%s ",argv[i]);
	}
}
