#include "edit.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0

//��ʼ��ջ
int InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) {
		return OVERFLOW;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}

//��ջ
int Push(SqStack *S, SElemType e) {
	if ((S->top - S->base) >= S->stacksize) {
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base) {
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	//printf("%c\n",e);
	return OK;
}

//ɾ��ջ�е�Ԫ��
int Pop(SqStack *S, SElemType *e) {
	if (S->top == S->base) {
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}


//���ջ�е�Ԫ��
int ClearStack(SqStack *S) {
	S->top = S->base;
	return OK;
}

//����ջ
int DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}

//�б༭����
void LineEdit(SqStack *S) {
	SElemType *p, ch, c;
	InitStack(S);
	ch = getchar();
	while (ch != -1) {
		while (ch != -1 && ch != '\n') {
			switch (ch) {
			case '#':Pop(S, &c); break;//����ջ�ǿ�ʱ��ջ
			case '@':ClearStack(S); break;//����SΪ��ջ
			default:Push(S, ch); break;//��Ч�ַ���ջ��δ����ջ�����
			}
			ch = getchar();//���ն˽�����һ���ַ�
		}
		p = S->base;
		while (p != S->top) {
			printf("%c", *p);
			++p;
		}
		//����ջ�׵�ջ����վ���ַ����������ù��̵�������
		ClearStack(S);//����SΪ��ջ
		if (ch != EOF)
		{
			ch = getchar();
		}
	}

}