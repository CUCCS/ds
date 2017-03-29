#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "3-2-1.h"

int main(){
	SqStack s;
	int input;
	int d;
	srand(time(0));
	input=rand();
	d=rand()%10;
	printf("要转换的数据:%d\n",input);
	printf("要转化的进制:%d\n",d);
	InitStack(&s);//初始化一个栈
	conversion(&s, input, d);
	return 0;
}