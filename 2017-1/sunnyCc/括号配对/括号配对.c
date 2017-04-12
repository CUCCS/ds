/*括号配对：随机产生一个数（0到5之间），输出对应的括号，进行配对检验*/
#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //用到了time函数 ,生成随机数0，1,2,3,4,5,分别对应“（”，“）”，“[”。“]”，“{”，“}”


void main()
{
	int a[10];
	char b[10];
	int i, number;
	srand((unsigned)time(NULL));//产生随机数种子
	for (i = 0; i<10; i++)
	{
		number = rand() % 6;  //产生0-5的随机数
		a[i] = number;
		printf("%d ", number);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (a[i] == 0)
			b[i] = '(';
		if (a[i] == 1)
			b[i] = ')';
		if (a[i] == 2)
			b[i] = '[';
		if (a[i] == 3)
			b[i] = ']';
		if (a[i] == 4)
			b[i] = '{';
		if (a[i] == 5)
			b[i] = '}';
		printf("%c", b[i]);
	}
	printf("\n");

	char *p;
	SqStack s;

	InitStack(&s);  //初始化空栈  
	p = b; //指针p指向字符数组ch

    pair(s,p);//进行括号配对
	DestoryStack(&s);//将栈销毁
	return 0;
}

