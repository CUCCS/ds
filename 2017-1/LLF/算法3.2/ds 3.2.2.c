//ʵ���������
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef char SElemType;

typedef struct {
	SElemType *base;//�ڹ���ǰ�����ٺ�base��ֵΪNULL
	SElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ���Ŀռ䣬��Ԫ��Ϊ��λ
}SqStack;//����ջ

typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;//���巵��ֵ��ö������

typedef enum {
	false,
	true
} bool;//���巵��ֵ

	   //ջ�Ļ���������������

Status InitStack(SqStack *S);
//����һ����ջS

Status DestroyStack(SqStack *S);
//����S

Status ClearStack(SqStack *S);
//��S��Ϊ��ջ

bool StackEmpty(SqStack *S);
//��SΪ��ջ�򷵻�TRUE,���򷵻�FALSE

int StackLength(SqStack *S);
//����S��Ԫ�ظ�������ջ�ĳ���

Status GetTop(SqStack *S, SElemType e);
//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR

Status Push(SqStack *S, SElemType e);
//����Ԫ��eΪ�µ�ջ��Ԫ��

Status Pop(SqStack *S, SElemType *e);
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR

Status StackTraverse(SqStack *S, Status(*visit)(SElemType));
//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ��,�����ʧ��

Status visit(SElemType e);
//��ӡջ��Ԫ��

Status matching(SElemType *exp);
//ʵ�����ŵ�ƥ��


#pragma once

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

Status DestrpoyStack(SqStack *S)//����S
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
	if (S->base == S->top)
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
	if (S->top - S->base >= S->stacksize) 
	{
		return(OVERFLOW);//�洢����ʧ��
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


Status matching(SElemType *exp) //ʵ�����ŵ�ƥ��
{
	SqStack S;
	InitStack(&S);
	int i = 0, flag = 0;
	SElemType e;
	while (exp[i] != '\0')
	{
		switch (exp[i])
		{
		case '(':
			Push(&S, exp[i]);
			break;
		case '{':
			Push(&S, exp[i]);
			break;
		case '[':
			Push(&S, exp[i]);
			break;
		case ')':
		{
			Pop(&S, &e);
			if (e != '(')
				flag = 1;
		}
		break;
		case '}':
		{
			Pop(&S, &e);
			if (e != '{')
				flag = 1;
		}
		break;
		case ']':
		{
			Pop(&S, &e);
			if (e != '[')
				flag = 1;
		}
		break;
		default:
			break;
		}
		if (flag)
			break;
		i++;
	}
	DestrpoyStack(&S);
	if (!flag)
		printf("����ƥ��ɹ�!\n");
	else
		printf("����ƥ��ʧ��!\n");
	return OK;
}

int main()
{

	SElemType exp1[] = { "{([])}" }, exp2[] = {"({])"};
	printf("EXP1��");
	matching(exp1);
	printf("EXP2��");
	matching(exp2);
	
	return 0;
}
	