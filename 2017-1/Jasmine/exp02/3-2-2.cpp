//�������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
//ö��״̬����
typedef enum
{
	Error, OK
}Status;
//����ջ�Ľṹ��
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
	*s->top= e;
	s->top++;
	return OK;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack *s)
{
	if (s->top == s->base)
	{
		return 0;
	}
	else
		return 1;
}
//ɾ��ջ��Ԫ��
Status Pop(SqStack *s)
{
	if (s->top == s->base)
		return Error;
	s->top--;
	return OK;
}
//����ջ��Ԫ��
char GetTop(SqStack *s)
{
	char *e;
	e = (char*)malloc(sizeof(char));
	if (s->top == s->base)
		return Error;
	*e = *(s->top -1);
	return *e;
}
//�ж�ƥ���Ƿ�ɹ�
Status matching(SqStack *s,char *p)
{
	int status=1;
	int len = strlen(p);
	int i = 0;
	while (i < len&&status)
	{
		switch (*p)
		{
		case '{':
		case '(':
		case '[':
			Push(s, *p);
			p++;
			i++;
			break;
		case '}':
		case ')':
		case ']':
			if (StackEmpty(s)&&(GetTop(s) == '{'||GetTop(s) == '['||GetTop(s) == '('))
			{
				status = 1;
				Pop(s);
				i++;
			}
			else
			{
				status = 0;
				i++;
			}
		}
	}
	if (!StackEmpty(s) && status == 1)
		return OK;
	else
		return Error;
}
int main()
{
	SqStack s;
	Status result;
	char test[STACK_INIT_SIZE];
	scanf("%s", test);
	InitStack(&s);
	result = matching(&s, test);
	if (result == OK)
		printf("matched!\n");
	else
		printf("not matched!\n");
	return 0;
}