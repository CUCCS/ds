#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100 //�洢�ռ��ʼ������

#define STACKINCREMENT 10 //�洢�ռ��������
typedef int Status;
typedef char SElemType;
//��˳��ջ���ж���
typedef struct Sq_Stack {

	SElemType *base;

	SElemType *top;

	int stacksize;
} SqStack;
//����
typedef enum {

	OK,
	ERROR,
	OVERFLOW,
    TRUE,
	FALSE ,
} Status;




/*#define OVERFLOW 
#define OK 
#define 
#define  
#define ERROR*/ 
Status InitStack(SqStack *pS);//�����ջ
SElemType Pop(SqStack *pS, SElemType *pe);//����ջ��Ԫ�أ�
Status Push(SqStack *pS, SElemType e);//������Ԫ�أ�
Status StackEmpty(SqStack *pS);//����@֮�����ջ֮���ж��Ƿ������
Status DestroyStack(SqStack *pS);//����#������ջ��

Status InitStack(SqStack *pS) {

	(*pS).base = (SElemType *)malloc(SIZE * sizeof(SElemType));

	if (!(*pS).base) 
		exit (OVERFLOW); //�洢����ʧ��

	(*pS).top = (*pS).base;

	(*pS).stacksize = SIZE;

	return OK;

}



SElemType Pop(SqStack *pS, SElemType *pe) {

	if ((*pS).top == (*pS).base) return ERROR;
	
	pe = --(*pS).top;

	return *pe;
}



Status Push(SqStack *pS, SElemType e) {

	if ((*pS).top - (*pS).base >= (*pS).stacksize) {

		(*pS).base = (SElemType *)realloc((*pS).base, ((*pS).stacksize + STACKINCREMENT) * sizeof(SElemType));

		if (!(*pS).base) exit (OVERFLOW);

		(*pS).top = (*pS).base + (*pS).stacksize;

		(*pS).stacksize += STACKINCREMENT;

	}

	*(*pS).top++ = e;

	return OK;

}



Status DestroyStack(SqStack *pS) {

	(*pS).top = NULL;

	(*pS).stacksize = 0;

	free((*pS).base);

	return OK;

}



Status StackEmpty(SqStack *pS) {

	if ((*pS).base == (*pS).top) return TRUE;

	else return FALSE;

}
//
void Lineedit() {

	int i = 0;  

	char ch[200] = "whli##ilr#e(s#*s)\noutchar@\nputchar(*s=#++)\0";
	//������
	SqStack S;

	SElemType e = ch[i];

	InitStack(&S); //�����ջ

	while (ch[i] != '\0') {

		e = ch[i];

		switch (ch[i]) {

		case '#':

			Pop(&S, &e);               break;

		case '@': {

			if (StackEmpty(&S)) break;

			while (e != '\n') { Pop(&S, &e); };

			if (StackEmpty(&S) || e == '\n') { Push(&S, e); break; }     break;

		}//����Ϊ��ջ

		default:

			Push(&S, ch[i]);             break;//��Ч�ַ���ջ

		};

		i++;

		//����ջ�׵�ջ����ջ���ַ����������ù��̵�������

	

	};

	char pa[100];

	int j = 0;

	while (!StackEmpty(&S)) {

		pa[j] = Pop(&S, &e);

		j++;

	};//�ų�#��@���֮�����������뵽������

	do {

		j--;

		printf("%c", pa[j]);

	} while (j >= 0);

	DestroyStack(&S);

}//���ϸ���ַ��������

int main() {

	Lineedit();

	return OK;

}




