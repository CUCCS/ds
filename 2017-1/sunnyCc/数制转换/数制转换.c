/* 数制转换：随机产生一个数和数值（1到9之间），输出进行数值转换后的数*/
#include "conversion.h"
#include <stdio.h> 

#include <stdlib.h>
#include <time.h> //用到了time函数 
#define MAX 1000//顺序栈存储空间最大值   

int main() {

	SqStack S;
	int n, m;
	srand(time(0));

	if (InitStack(&S)) {
		printf("栈S初始化成功!\n");
	}
	else {
		printf("栈S初始化失败!\n");
	}

	if (IsEmpty(&S)) {
		printf("栈为空.\n");
	}
	else {
		printf("栈非空.\n");
	}

	printf("\n");

	printf("要转换的数n:");
	n = rand() % 999999;
	printf("%d\n", n);

	printf("要输出的数制:");
	m = rand() % 9 + 2;
	printf("%d\n", m);

	printf("转换数制后的数:");
	conversion(&S, n, m);
	DestoryStack(&S);//将栈销毁
	printf("\n");

	return 0;
}