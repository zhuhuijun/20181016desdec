#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclientdll.h"

int main001(int arg, char *args[])
{
	void *handle = NULL;
	int ret = 0;
	unsigned char buf[128];
	strcpy(buf, "12345");
	int buflen = 3;


	unsigned char outbuf[128] = {0};
	int outbuflen = 3;


	ret = cltSocketInit(&handle);
	if (ret != 0)
	{
		printf("cltSocketInit init error\n");
		return ret;
	}
	ret = cltSocketSend(handle, buf, buflen);
	if (ret != 0)
	{
		printf("cltSocketSend init error\n");
		return ret;
	}
	ret = cltSocketRev(handle, outbuf, &outbuflen);
	if (ret != 0)
	{
		printf("cltSocketSend init error\n");
		return ret;
	}
	printf("recv:%s\n", outbuf);
	cltSocketDestory(handle);
	handle = NULL;
	system("pause");
	return 1;
}