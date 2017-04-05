#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <time.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ����
#define STACKINCREMENT  10  //�洢�ռ��������

#define OVERFLOW -2

typedef struct{
	int *base;   //��ջ����֮ǰ������֮��base��ֵΪNULL
	int *top;      //ջ��ָ��
	int sackbase;   //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;


//����һ����ջ
int InitStack(SqStack *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));   //��������ռ�
	if(!S->base)exit(OVERFLOW);           //�ж��Ƿ����ɹ�
	S->top = S->base;              //ָ��ջ��
	S->sackbase = STACK_INIT_SIZE;         //��ʼ������󳤶�
	return 0;
}



//��SΪ��ջ����OK ���򷵻�ERROR
int StackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return 1;
	else
		return 0;
}


//�����µ�ջ������
int Push(SqStack *S,int e)
{
	if(S->top - S->base >= S->sackbase)//�ռ䲻��
	{
		S->base = (int*)realloc(S->base,(S->sackbase+STACKINCREMENT)*sizeof(int));
		if(!S->base)exit(OVERFLOW);
		S->top = S->base + S->sackbase;
		S->sackbase += STACKINCREMENT;
	}
	*S->top ++= e;
	return 0;
}



//��ջ���� ��ɾ��ջ�����ݲ���e�����ҷ���OK ���򷵻�ERROR
int Pop(SqStack *S,int *e)
{
	if(S->top == S->base)
		return 1;
	*e=*--S->top;//ɾ��S��ջ��Ԫ�أ�����ԭ�������ٰ�ָ��ָ��e 
	return 0;
}


void convertion(SqStack *S,int d,int N)
{
	//NΪ��ת������,dΪ��ת���ɵ�����
	InitStack(S);

	while(N)
	{
		Push(S,N%8);
		N = N/d;
	}
	while(!StackEmpty(S))
	{
		int e;
		Pop(S,&e);
		printf("%d",e);
	}
}


int main()
{
	
	int N;int d;
	SqStack S;
	InitStack(&S);
	srand((unsigned)time(NULL));
	printf("Ҫת��������\n");
	N = rand()%1024;
	printf("%d\n",N);
	printf("����Ҫת���ɵ����ƣ�\n");
	scanf_s("%d",&d);
	printf("ת�����ֺ����Ϊ:\n");
	convertion(&S,d,N);
	printf("\n");

	return 0;
}

