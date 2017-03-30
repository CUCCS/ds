#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

Status InitStack(SqStack *S,int size);
Status Push(SqStack *S,SElemType e);
Bool IsStackEmpty(SqStack *S);
SElemType GetTop(SqStack *S,SElemType *e);
Status Pop(SqStack *S,SElemType *e);
void DestroyStack(SqStack *S);
Status matching(SqStack S, char *exp);

Status InitStack(SqStack *S,int size)       //����˳��ջ
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
	    return  OVERFLOW; 
	}//�洢����ʧ��
	S->top = S->base;
	S->stacksize = size;
	return OK;
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

Bool IsStackEmpty(SqStack *S)//�ж�ջ���Ƿ�Ϊ�գ�
{
	if(S->top == S->base)
		return True;
	else
		return False;
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

Status Pop(SqStack *S,SElemType *e)//��ջ��Ϊ�գ���ɾ��s��ջ��Ԫ�أ���e����ֵ��������OK�����򷵻�ERROR��
{
	if(IsStackEmpty(S))
	{
		return ERROR;

	}
	*e = *--S->top;

	return OK;
}

void DestroyStack(SqStack *S)//����ջs��s������
{
	if(S)
	{
		S = NULL;
	}
	free(S);
}
Status matching(SqStack S, char *exp)//�����Ƿ�ƥ��
{
	int state = 1;
	int i = 0;
	int flag = 0;
	SElemType e;
	while(exp[i]!='\0')
	{
		switch(exp[i])
		{
		case '(':
			Push(&S,exp[i]);
			break;
		case '[':
			Push(&S, exp[i]);
			break;
		case '{':
			Push(&S, exp[i]);
			break;

		case ')':
			{
					Pop(&S ,&e);
					if(e != '(')
						flag = 1;
			}
			break;
				
		case ']':
			{
					Pop(&S ,&e);
					if(e != '[')
						flag = 1;
			}
			break;
		case '}':
			{
					Pop(&S ,&e);
					if(e != '{')
						flag = 1;
			}
			break;
		}
		i++;
	}
		if(IsStackEmpty(&S) && state) 
			return OK;
		else
			return ERROR;
}
int main()
{
	SqStack S;
	Status ret;//cserfsedc
	char test[100];
	scanf("%s",&test);
	InitStack(&S,STACK_SIZE);
	ret = matching(S ,test);

	if(ret == OK)
	{
		printf("ƥ��ɹ���\n");
	}
	else 
	{
		printf("ƥ��ʧ�ܣ�\n");
	}
	return 0;
}