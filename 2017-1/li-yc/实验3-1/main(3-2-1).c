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
	if(d>10){
		printf("输入的数字不符合转换进制的要求\n");
		printf("请重新输入要转换的数\n");
		scanf_s("%d",&d);
	}
	printf("要转换的数据:%d\n",input);
	printf("要转化的进制:%d\n",d);
	InitStack(&s);//初始化一个栈
	conversion(&s, input, d);
	return 0;
}