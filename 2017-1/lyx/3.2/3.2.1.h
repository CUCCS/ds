//ds 3.2.h
#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef int SElemType;

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

Status DestroyStack(SqStack *S)  ;
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

Status conversion(SqStack *S, int input, int d);
//ʵ������ת��


