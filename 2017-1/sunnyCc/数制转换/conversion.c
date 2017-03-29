#include "conversion.h"
#include <stdlib.h>
#define MAX 1000
//��ʼ��˳��ջ  
int InitStack(SqStack *S) {
	S->base = (int*)malloc(MAX);
	if (!S->base) {
		return 0;//�洢�ռ����ʧ��   
	}
	S->top = S->base;
	S->stacksize = MAX;
	return 1;
};

//�ж�ջ�Ƿ�Ϊ��  
int IsEmpty(SqStack *S) {
	if (S->base == S->top) {
		return 1;//ջ��   
	}
	else {
		return 0;//ջ�ǿ�   
	}
};

//��ջ  
int Push(SqStack *S, int e) {
	if (S->top - S->base == S->stacksize) {
		return 0;//ջ��   
	}
	*S->top++ = e;  //����eΪ�µ�ջ��Ԫ��
	return 1;
};

//��ջ   
int Pop(SqStack *S, int *e) {
	if (S->top == S->base) {
		return 0;//ջ��   
				 //printf("ջ��\n");  
	}
	*e = *--S->top;//ɾ��S��ջ��Ԫ�أ�����ԭ�������ٰ�ָ��ָ��e  
	return 1;
	//printf("%d",e);  
};

//����ת��  
void conversion(SqStack *S, int n, int m) {
	//n��ʾ��ת��������m��ʾ��������Ľ���   
	InitStack(S);
	while (n) {
		Push(S, n%m); //��վ 
		n = n / m;
	}

	while (!IsEmpty(S)) {
		int e;
		Pop(S, &e);  //��ջ
		printf("%d", e);
	}
};
