#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10 //�洢�ռ��������

typedef int SElemType;
//��˳��ջ���ж���
typedef struct Sq_Stack
{
    SElemType *base;
    SElemType *top;
    int stacksize;

}SqStack;
typedef enum
{      OK,
    ERROR,
    OVERFLOW,

}Status;


//Status InitStack(SqStack*S);//����һ����ջ
////void DestroyStack(SqStack*S);//�����Ѿ����ڵ�ջ
//Status Push(SqStack*S,SElemType e);//��һ���µ�Ԫ����ӵ�ջ��
//Status Pop(SqStack*S,SElemType *e);//ɾ��ջ����Ԫ��,����e������ֵ
//bool StackEmpty(SqStack*S);//�ж�һ��ջ�Ƿ�Ϊ��
////Status GetTop(SqStack S);
//void Conversion(SqStack*S,SElemType input,SElemType mod);


//����һ����ջS
Status  InitStack (SqStack* pS)    //����һ����ջ
{
	pS->base=(SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));

	if(! pS->base) 
	{
		return OVERFLOW;
	}

	pS->top =(*pS).base;
	pS->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;

}
int StackEmpty(SqStack *S)
{
	if (S)
		return S->base==S->top;
	return 1;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;

}

void conversion (SqStack *S,int n,int d) 
{
	SElemType e;
	while (n) 
	{
		Push(S, n % d);
		n = n / d;
	}
	while (!StackEmpty(S)) 
	{
		Pop(S, &e);
		printf ( "%d", e );
	}

	printf("\n");
} // conversion
int main()
{
	int n;
	int d;
	SqStack S;
	srand(time(0));

	n=rand()%1024;
	printf("��ת������ ��%d\n",n);
	d=rand()%10+1;
	printf("ת������ ��%d\n",d);
	
	InitStack(&S);
	conversion(&S,n,d);
	return 0;
}