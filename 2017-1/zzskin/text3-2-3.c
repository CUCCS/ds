#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define STACK_INIT_SIZE 100    //�洢�ռ��ʼ������
#define STACK_SIZE 100            //�洢�ռ��������
#define STACKINCREMENT 10         //�洢�ռ��������

typedef char SElemType ;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //ö�ٶ��壨����״̬��

typedef enum{
	False,
	True
}Bool;                            //���岼������

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;                          //˳��ջ�Ķ���

Status InitStack(SqStack *S);
Status DestroyStack (SqStack *S);
Status Pop(SqStack *S,SElemType *e);
Bool IsStackEmpty(SqStack *S);
Status ClearStack(SqStack *S);
Status Push(SqStack *S,SElemType e);
SElemType GetTop(SqStack *S,SElemType *e);
void LineEdit(SqStack *S);


Status InitStack(SqStack *S)       //����˳��ջ
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
		return  OVERFLOW; 
	}//�洢����ʧ��
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


Status DestroyStack (SqStack *S)//����ջs��s������
{
	S->top = S->base;
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK; 
}

Status Pop(SqStack *S,SElemType *e)//��ջ��Ϊ�գ���ɾ��s��ջ��Ԫ�أ���e����ֵ��������OK�����򷵻�ERROR��
{
	if(IsStackEmpty(S))
	{
		return OK;
	}
	*e = *--S->top;
	return ERROR;
}

Bool IsStackEmpty(SqStack *S)//�ж�ջ���Ƿ�Ϊ�գ�
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status ClearStack(SqStack *S)//���ջ
{ 
		SElemType *e=(SElemType*)malloc(sizeof(SElemType));
	if (IsStackEmpty(S))
		return OK;
	else
	{
		while (*--S->top != ' ')
			Pop(S, e);
		return ERROR;
	}
} 

Status Push(SqStack *S,SElemType e)//����Ԫ��Ϊe���µ�ջ��Ԫ��
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

SElemType GetTop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

void LineEdit(SqStack *S)
{
	SElemType  *c = (SElemType*)malloc(sizeof(SElemType));
	char ch;
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵�������
	InitStack(S);
	ch = getchar();//���յ�һ����ĸ
	while(ch != EOF)
	{
		while(ch != EOF && ch != '\n')
		{
			switch(ch)
			{
			case '#':
				Pop(S,c);    
				break;//����ջ�ǿ�ʱ��ջ
			case '@':
				ClearStack(S);   
				break;//����SΪ��ջ
			default:
				Push(S,ch);      
				break;//��Ч�ַ���ջ��δ����ջ������
			}
			ch = getchar();   //���ն˽�����һ���ַ�
		}
			while(!IsStackEmpty(S))
		{
			Pop(S,c);
			printf("%c",*c);
		}
		ClearStack(S);
		if ( ch != EOF)
			ch = getchar();
	}
	DestroyStack(S);
}

int main()
{
	SqStack S;
	InitStack(&S);
	printf("���:\n");
	LineEdit(&S);           //�б༭
	DestroyStack(&S);      //����ջ
	return 0;
}