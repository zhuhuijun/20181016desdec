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
//机器编译的等号操作，只会把指针变量的值从from copy到 to
//不会把指针变量所指向的内存空间copy这就是浅copy
//出现场景是结构体中套用一级或者二级指针
//如果想执行深copy需要自己分配空间
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
	copyT(&t1, &t2); //直接赋值
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