#include <stdio.h>
typedef char SElemType;

//ջ�ṹ��
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack *S);//��ʼ��ջ
int Push(SqStack *S, SElemType e);//��ջ
int Pop(SqStack *S, SElemType *e);//ɾ��ջ�е�Ԫ��
int DestoryStack(SqStack *S);//����ջ
void LineEdit(SqStack *S);//�б༭����
int ClearStack(SqStack *S);//���ջ�е�Ԫ��