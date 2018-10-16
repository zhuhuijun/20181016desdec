#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

int main(int arg, char *args[])
{
	int ret;
	char *pdata = "1234";
	int plen = strlen(pdata);
	unsigned char crypdata[4096] = { 0 };
	int cryplen = 0;


	unsigned char crypdata2[4096] = { 0 };
	int cryplen2 = 0;


	ret =  DesEnc(pdata
		, plen
		, crypdata
		, &cryplen);
	printf("enc after:%s\n", crypdata);



	ret =  DesDec(crypdata
		, cryplen
		, crypdata2
		, &cryplen2);
	printf("dec after:%s\n", crypdata2);
	system("pause");
	return 1;
}

