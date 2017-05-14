#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char SElemType;
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

//����һ����ջ��
Status InitStack(SqStack *);
//��ջ��Ϊ�գ�ɾ��ջ��Ԫ�أ�
Status Pop(SqStack*, SElemType*e);
//����Ԫ����Ϊ�µ�ջ��Ԫ�أ�
Status Push(SqStack*, SElemType);
//��s��Ϊ��ջ���ο����ϴ��룻
Status ClearStack(SqStack*);
//�ж�s�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack*s);
//����ջʹ֮���ٴ��ڣ�
Status DistoryStack(SqStack *s);
//�����ַ�ջ�����ն˽���һ�в��������ù��̵���������
Status LineEdit(SqStack*s, char*a);
