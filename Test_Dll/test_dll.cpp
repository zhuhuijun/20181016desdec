#include "test_dll.h"
int panny(int i, int(*call_back)(int a, int b))
{
	int aa;
	aa = i*i;
	call_back(i, aa);
	return 0;
}