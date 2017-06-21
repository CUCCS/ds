//С��ʮ����ת��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "3.2.1.h"

Status InitStack(SqStack *S) { //�����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(S->base)) {
		return OVERFLOW;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
Status DestoryStack(SqStack *S) { //����ջ
	SqStack *p;
	if (StackEmpty(*S)) {
		return ERROR;
	}
	free(S);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
};
Status StackEmpty(SqStack S) { //�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};
Status Push(SqStack *S, SElemType e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(S->base)) {
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top)++ = e;
	return OK;
};
Status Pop(SqStack *S, SElemType *e) { //��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (StackEmpty(*S)) {
		return ERROR;
	}
	*e = *--(S->top);
	return OK;
};

Status conversation(int d) {
	SqStack S;
	SElemType N, e;
	if (d > 10) {
		printf("ERROR! Please input a number (<=10)\n");
		return ERROR;
	}
	if (InitStack(&S)) { //�����ջ
		printf("Initialize stack failed.\n");
		return ERROR;
	};
	N = (int)rand() % 1024; //���������
	printf("\n������ %d\n", N);
	while (N) {
		Push(&S, N % d);
		N = N / d;
	}
	printf("��Ӧ%d�������� ",d);
	while (!StackEmpty(S)) {
		Pop(&S, &e);
		printf("%d", e);
	}
	printf("\n");
	DestoryStack(&S);
}

int main() {
	srand(time(NULL));

	conversation(8);
	conversation(2);

	return 0;
}