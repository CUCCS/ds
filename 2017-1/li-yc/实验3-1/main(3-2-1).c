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
		printf("��������ֲ�����ת�����Ƶ�Ҫ��\n");
		printf("����������Ҫת������\n");
		scanf_s("%d",&d);
	}
	printf("Ҫת��������:%d\n",input);
	printf("Ҫת���Ľ���:%d\n",d);
	InitStack(&s);//��ʼ��һ��ջ
	conversion(&s, input, d);
	return 0;
}