#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct Teacher
{
	char name[64];
	int age;
	char *name2;
} Teacher;
//��������ĵȺŲ�����ֻ���ָ�������ֵ��from copy�� to
//�����ָ�������ָ����ڴ�ռ�copy�����ǳcopy
//���ֳ����ǽṹ��������һ�����߶���ָ��
//�����ִ����copy��Ҫ�Լ�����ռ�
void copyT(Teacher *from, Teacher *to)
{
	//*to = *from;
	memcpy(to, from, sizeof(Teacher));
	to->name2 = (char *)malloc(100);
	strcpy(to->name2, from->name2);
}
int main001(int arg, char *args[])
{
	Teacher t1;
	Teacher t2;
	strcpy(t1.name, "name1");
	t1.name2 = (char *)malloc(100);
	strcpy(t1.name2, "ssss");
	copyT(&t1, &t2); //ֱ�Ӹ�ֵ
	if (t1.name2 != NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}
	if (t2.name2 != NULL)
	{
		free(t2.name2);
		t2.name2 = NULL;
	}
	printf("hello,world");
	system("pause");
	return 1;
}