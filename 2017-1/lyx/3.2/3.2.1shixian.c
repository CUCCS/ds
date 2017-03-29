//ds 3.2.cpp
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

#include "ds 3.2.h"

//ջ�Ļ���������������

Status InitStack(SqStack *S)//����һ����ջS
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) {
		return(OVERFLOW);//�洢����ʧ��
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;

}//InitStack

Status DestroyStack(SqStack *S)//����S
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}


Status ClearStack(SqStack *S)//��S��Ϊ��ջ
{
	S->top = NULL;
	return OK;
}

bool StackEmpty(SqStack *S)//��SΪ��ջ�򷵻�TRUE,���򷵻�FALSE
{
	if (S->base==S->top)
		return true;
	else
		return false;
}

int StackLength(SqStack *S)//����S��Ԫ�ظ�������ջ�ĳ���
{
	return *S->top + 1;
}

Status GetTop(SqStack *S, SElemType e)//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
{
	if (S->top == S->base)return ERROR;
	e = *(S->top - 1);
	return OK;
}//GetTop

Status Push(SqStack *S, SElemType e)//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S->top - S->base >= S->stacksize) {//ջ����׷�Ӵ洢�ռ�
											//��ʱ����
											//S->base=(SElemaType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
											//if(!S->base){
		return(OVERFLOW);//�洢����ʧ��
						 //}
						 //S->top=S->base+S->stacksize;
						 //S->stacksize+=STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
{
	if (StackEmpty(S))return ERROR;
	*e = *--S->top;
	return OK;
}//Pop

 

Status StackTraverse(SqStack *S, Status(*visit)(SElemType))//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ��,�����ʧ��
{
	while (S->top > S->base)
		visit(*S->base++);
	printf("\n");
	return OK;
}//StackTraverse

Status visit(SElemType e) //��ӡջ��Ԫ��
{
	printf("%d ", e);
	return OK;
}  //visit

Status conversion(SqStack *S, int input, int d)//ʵ������ת��
{
	int output;
	InitStack(S);
	while (input) {
		Push(S, input%d);
		input = input / 8;
	}
	while (!StackEmpty(S))
	{
		Pop(S, &output);
		printf("%d", output);
	}

	return OK;

}//conversion


