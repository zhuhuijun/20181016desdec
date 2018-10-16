#pragma once
#ifndef __DES_H__
#define __DES_H__


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	/*----------------------------------------*/
	int DesEnc(unsigned char *pInData
		, int nInDataLen
		, unsigned char *pOutData
		, int *pOutDataLen);
	//Ω‚√‹
	int DesDec(unsigned char *pInData
		, int nInDataLen
		, unsigned char *pOutData
		, int *pOutDataLen);
	/*----------------------------------------*/
#ifdef __cplusplus
}
#endif // __cplusplus


#endif // !__DES_H__
