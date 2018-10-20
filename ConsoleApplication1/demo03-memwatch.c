#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memwatch.h"

/*
**MEMWATCH
**MW_STDIO
*/
int getMem(char **pt)
{
	char *p = NULL;
	p = (char *)malloc(100);
	memset(p, 0, 100);
	strcpy(p, "aaaaaa");
	*pt = p;
	return 0;
}

int main(int arg, char *args[])
{
	char *p = NULL;
	getMem(&p);
	printf("%s\n", p);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	printf("hello\n");
	system("pause");
}