#include<stdio.h>
#include<stdlib.h>
#include<time.h>//���������

#define STACK_INIT_SIZE 100//����곣��

typedef char SElemType;//����SElemTypeΪ�ַ���

typedef enum//ö������
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
}SqStack;//����ṹ��
typedef enum
{
	true,
	false
}bool;//����bool

Status InitStack(SqStack *s);//����һ����ջ
bool StackEmpty(SqStack *s);//��ջsΪ��ջ���򷵻�TRUE�����򷵻�FALSE
Status Pop(SqStack *s,SElemType *e);//��ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status GetTop(SqStack *s,SElemType *e);//��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status Push(SqStack *s,SElemType e);//����Ԫ��eΪ�µ�ջ��Ԫ��
Status ClearStack(SqStack *s);//��S��Ϊ��ջ
Status DistoryStack(SqStack *s);//����ջs��s���ٴ���
Status LineEdit(SqStack *s,char *a);//�ı��༭������