//ds 3.2.cpp
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

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

Status conversion(SqStack *S, int input, int d);
//ʵ������ת��




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
		input = input / d;
	}
	while (!StackEmpty(S))
	{
		Pop(S, &output);
		printf("%d", output);
	}

	return OK;

}//conversion


int main(int argc, char* argv[])
{
	SqStack S;
	int input;
	int d;

	srand((unsigned)time(NULL));//��ʱ������
	input = (int)rand() % 5000;//������ɲ�������
	d = (int)rand() % 9;//�������ת������
	printf("%d\n%d\n", input, d);

	conversion(&S, input, d);

	return 0;
}