#include<stdlib.h>
#include<stdio.h>

#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */

typedef char SElemType;

typedef enum{ERROR,OK,OVERFLOW}Status;
typedef enum{FALSE,TRUE}bool;
typedef struct SqStack
{
	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
	SElemType *top; /* ջ��ָ�� */
	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack; /* ˳��ջ */

Status InitStack(SqStack *S)
{ /* ����һ����ջS */
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)
		return OVERFLOW; /* �洢����ʧ�� */
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestroyStack(SqStack *S)
{ /* ����ջS��S���ٴ��� */
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	return OK;
}
Status ClearStack(SqStack *S)
{ /* ��S��Ϊ��ջ */
	(*S).top = (*S).base;
	return OK;
}
Status StackEmpty(SqStack *S)
{ /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
	if ((*S).top == (*S).base)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SqStack S)
{ /* ����S��Ԫ�ظ�������ջ�ĳ��� */
	return S.top - S.base;
}
Status GetTop(SqStack *S, SElemType *e)
{ /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	if ((*S).top>(*S).base)
	{
		*e = *((*S).top - 1);
		return OK;
	}
	else
		return ERROR;
}
Status Push(SqStack *S, SElemType e)
{ /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
	if ((*S).top - (*S).base >= (*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)
			exit(OVERFLOW); /* �洢����ʧ�� */
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}
Status Pop(SqStack *S, SElemType *e)
{ /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	//printf("%c", *e);
	return OK;
}
Status StackTraverse(SqStack S, Status(*visit)(SElemType))
{ /* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
	/* һ��visit()ʧ�ܣ������ʧ�� */
	while (S.top>S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}


Status visit(SElemType c)
{
	printf("%c ", c);
	return OK;
}
