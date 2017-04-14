#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef enum
{
	Error, OK
}Status;
//�ṹ�嶨��
typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;
//��ʼ��һ���յ�ջa
Status InitStack(SqStack *s)
{
	s->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!s->base)
		return Error;
	else
	{
		s->top = s->base;
		s->stacksize = STACK_INIT_SIZE;
		return OK;
	}
}
//��ջ�м���һ��Ԫ��
Status Push(SqStack *s, char e)
{
	//�ж�ջ�Ƿ�����
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (char*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(char));
		if (!s->base)
			return Error;
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top = e;
	s->top++;
	return OK;
}
//ɾ��ջ��Ԫ��
Status Pop(SqStack *s)
{
	if (s->top == s->base)
		return Error;
	s->top--;
	return OK;
}
//���ջ
Status ClearStack(SqStack *s)
{
	s->top = s->base;
	return OK;
}
//��ӡջ������
Status Print(SqStack *s)
{
	char *p;
	p = s->base;
	while (p != s->top)
	{
		printf("%c", *p);
		p++;
	}
	return OK;
}
//�б༭����
Status LineEdit(SqStack *s)
{
	char str;
	scanf("%c", &str);
	while (str != '/')
	{
		while (str!='/'&&str != '\n')
		{
			switch (str)
			{
			case '#':
				Pop(s);
				break;
			case '@':
				ClearStack(s);
				break;
			default:
				Push(s, str);
				break;
			}
			scanf("%c", &str);
		}
		Print(s);
		printf("\n");
		if(str!='/')
			scanf("%c", &str);
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
