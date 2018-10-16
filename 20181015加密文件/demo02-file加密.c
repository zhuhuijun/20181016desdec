#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

#define  MAXLEN 4096

int FileSymEnc(const char *pfile1, const char *pfile2)
{
	FILE *pf1 = NULL, *pf2 = NULL;
	unsigned char tmpbuf[MAXLEN] = { 0 };
	char crypdata[MAXLEN] = { 0 };
	int cryplen = 0;
	int crypret = 0;
	int tmpret = 0;
	int tmpret2 = 0;
	pf1 = fopen(pfile1, "rb");
	if (NULL == pf1)
	{
		goto End;
	}

	pf2 = fopen(pfile2, "wb");
	if (NULL == pf2)
	{
		goto End;
	}

	//copy data
	while (!feof(pf1))
	{
		tmpret = fread(tmpbuf, 1, MAXLEN, pf1);
		printf("while tmpret:%d\n", tmpret);
		if (feof(pf1))//文件结束
		{
			break;
		}

		//加密数据的方法
		crypret = DesEnc_raw(tmpbuf
			, tmpret
			, crypdata
			, &cryplen);
		printf("while enc len:%d\n", cryplen);
		if (crypret != 0)
		{
			printf("enc error\n");
			goto End;
		}
		tmpret2 = fwrite(crypdata, 1, cryplen, pf2);
		printf("while tmpret2:%d\n", tmpret2);

		if (tmpret2 != cryplen)
		{
			printf("while fwrite error ,please check disk\n");
			goto End;
		}
	}
	//加密数据的方法
	crypret = DesEnc(tmpbuf
		, tmpret
		, crypdata
		, &cryplen);
	printf("tmpret:%d\n", tmpret);
	printf("cryplen:%d\n", cryplen);
	if (crypret != 0)
	{
		printf("enc error\n");
		goto End;
	}
	tmpret2 = fwrite(crypdata, 1, cryplen, pf2);
	printf("tmpret2:%d\n", tmpret2);

	if (tmpret2 != cryplen)
	{
		printf("fwrite error ,please check disk\n");
		goto End;
	}


End:
	if (pf1 != NULL)
	{
		fclose(pf1);
	}
	if (pf2 != NULL)
	{
		fclose(pf2);
	}
	goto End;
	return 0;
}

int main002(int arg, char *args[])
{
	int ret = 0;
	const char *pfile1 = "d:/2.cer";
	const char *pfile2 = "d:/2.enc.txt";
	ret = FileSymEnc(pfile1, pfile2);
	if (ret != 0)
	{
		printf("enc error\n");
	}
	system("pause");
	return 1;
}