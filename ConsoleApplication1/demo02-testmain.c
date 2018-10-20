#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclientdll.h"

int main(int arg, char *args[])
{
	void *handle = NULL;
	int ret = 0;
	unsigned char buf[128];
	strcpy(buf, "12345");
	int buflen = 3;


	unsigned char *outbuf=NULL;
	int outbuflen = 3;


	ret = cltSocketInit2(&handle);
	if (ret != 0)
	{
		printf("cltSocketInit init error\n");
		return ret;
	}
	ret = cltSocketSend2(handle, buf, buflen);
	if (ret != 0)
	{
		printf("cltSocketSend init error\n");
		return ret;
	}
	ret = cltSocketRev2(handle, &outbuf, &outbuflen);
	if (ret != 0)
	{
		printf("cltSocketSend init error\n");
		return ret;
	}
	printf("recv:%s\n", outbuf);
	cltSocketRev2_Free(&outbuf);
	cltSocketDestory2(handle);
	handle = NULL;
	system("pause");
	return 1;
}