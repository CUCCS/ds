/* ����ת�����������һ��������ֵ��1��9֮�䣩�����������ֵת�������*/
#include "conversion.h"
#include <stdio.h> 

#include <stdlib.h>
#include <time.h> //�õ���time���� 
#define MAX 1000//˳��ջ�洢�ռ����ֵ   

int main() {

	SqStack S;
	int n, m;
	srand(time(0));

	if (InitStack(&S)) {
		printf("ջS��ʼ���ɹ�!\n");
	}
	else {
		printf("ջS��ʼ��ʧ��!\n");
	}

	if (IsEmpty(&S)) {
		printf("ջΪ��.\n");
	}
	else {
		printf("ջ�ǿ�.\n");
	}

	printf("\n");

	printf("Ҫת������n:");
	n = rand() % 999999;
	printf("%d\n", n);

	printf("Ҫ���������:");
	m = rand() % 9 + 2;
	printf("%d\n", m);

	printf("ת�����ƺ����:");
	conversion(&S, n, m);
	DestoryStack(&S);//��ջ����
	printf("\n");

	return 0;
}