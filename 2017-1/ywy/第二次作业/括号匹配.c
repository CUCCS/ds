#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCRESE 10
typedef char SElemType;
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;
}Sqstack;
typedef enum
{
	error, ok
}Status;
//����ջ
Status Initstack(Sqstack*S)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
	{
		return error;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return ok;
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(Sqstack *S)
{
	if (S->top == S->base)
	{
		return ok;
	}
	else return error;
}
//����ջ��Ԫ��
Status Push(Sqstack*S, SElemType e)
{
	if (S->top - S->base == S->stacksize)
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCRESE) * sizeof(SElemType));
		S->top = S->base + S->stacksize;
		S->base = S->base + STACKINCRESE;
	}
	*S->top++ = e;
	return ok;
}
//��ջ
Status Pop(Sqstack *S, SElemType*e)
{
	if (S->top == S->base)
	{
		return error;
	}
	*e = *--S->top;
	return ok;
}
//����ƥ�䣬ƥ�亯��д�Ĳ����ã�ֻ�п���ƥ��������������ֲſ�����ȷƥ��
Status cout(Sqstack *S, SElemType*str)
{
	int i = 0, flag = 0;
	SElemType e;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '(':
			Push(S, str[i]);
			break;

		case '{':
			Push(S, str[i]);
			break;
		case '[':
			Push(S, str[i]);
			break;
		case ')':
		{
			Pop(S, &e);
			if (e != '(')
			{
				flag = 1;
			}
		}
		break;
		case ']':
		{
			Pop(S, &e);
			if (e != '[')
			{
				flag = 1;
			}
		}
		break;
		case '}':
		{
			Pop(S, &e);
			if (e != '{')
			{
				flag = 1;
			}
		}
		break;
		}
		i++;
	}
	if (!flag&&StackEmpty(S))
	{
		printf("ƥ��ɹ���\n");
	}
	else
		printf("ƥ��ʧ�ܣ�\n");

	return ok;
}
int main()
{
	printf("����Ҫƥ������ţ�");
	SElemType str[20];
	Sqstack S;
	Initstack(&S);
	scanf("%s", str);
	cout(&S, str);
}