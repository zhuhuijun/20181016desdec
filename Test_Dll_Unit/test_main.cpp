#include <iostream>
#include "test_dll.h"
using namespace std;
int panny_call_back(int a, int b)
{
	int c;
	c = a + b;
	printf("�����%d\n", c);
	return 11;
}
void main()
{
	int p = 10;
	int panny1;
	panny1 = panny(p, panny_call_back);
	printf("���2��%d\n", panny1);
	std::cin.get();
	std::cin.get();
}