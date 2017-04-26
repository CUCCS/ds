//ʵ���б༭����
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef char SElemType;

typedef struct 
{
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

Status StackTraverse(SqStack *S);

Status LineEdit(SqStack *s);
// �����ַ�ջs�����ն˽���һ�в��������ù��̵���������
//ջ�Ļ���������������

Status InitStack(SqStack *S)//����һ����ջS
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) 
	{
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
	S->top = S->base;	//ջ��ջ����ͬΪ��ջ 
	return OK;
}

bool StackEmpty(SqStack *S)//��SΪ��ջ�򷵻�TRUE,���򷵻�FALSE
{
	if (S->base == S->top)
		return true;
	else
		return false;
}


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
	*(S->top)++ = e;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
{
	if (StackEmpty(S))return ERROR;
	*e = *--(S->top);
	return OK;
}//Pop



Status StackTraverse(SqStack *S)
{
	char *p;
	p = S->base;
	while (p != S->top)
	{
		printf("%c", *p);
		p++;
	}
	return OK;
}//StackTraverse



// �����ַ�ջs�����ն˽���һ�в��������ù��̵���������
Status LineEdit(SqStack *S)
{
	char str,e;
	scanf_s("%c", &str);
	while (str != '/')
	{
		while (str != '/'&&str != '\n')
		{
			switch (str)
			{
			case '#':
				Pop(S,&e);
				break;
			case '@':
				ClearStack(S);
				break;
			default:
				Push(S, str);
				break;
			}
			scanf_s("%c", &str);
		}
		StackTraverse(S);
		printf("\n");
		if (str != '/')
			scanf_s("%c", &str);
	}
	return OK;
}

int main()
{
	SqStack s;
	InitStack(&s);
	LineEdit(&s);
	return 0;
}
