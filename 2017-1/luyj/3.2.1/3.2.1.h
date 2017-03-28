#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef int SElemType;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum
{
	true,
	false
}bool;

//����������ķǸ�ʮ������������ӡ����������ֵ�Ľ�������
Status conversion(SqStack*, SElemType, int);
//����һ����ջ
Status InitStack(SqStack *);
//�����µ�ջ��Ԫ��
Status Push(SqStack*, SElemType);
//�ж��Ƿ��ǿ�ջ�����ǿգ���e������ֵ��������OK�����򣬷���ERROR��
Status Pop(SqStack*, SElemType*e);

bool StackEmpty(SqStack*s);