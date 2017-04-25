//����ƥ�����
#include <stdio.h>
#include <stdlib.h>
#define STACKINCREAMENT 10
#define STACK_INIT_SIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int status;
typedef char SElemtype;

typedef struct
{
	SElemtype *base;
	SElemtype *top;
	status stacksize;
}sqstack;

//��ʼ��ջ
status Init(sqstack *s)
{
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

//��ȡջ��Ԫ��
status Gettop(sqstack *s, SElemtype e)
{
	if (s->top == s->base)
		return ERROR;
	e = *(s->top - 1);
	return OK;
}

//ѹջ
status push(sqstack *s, SElemtype e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (SElemtype *)realloc(s->base, (s->stacksize + STACKINCREAMENT) * sizeof(SElemtype));
		if (!s->base)
			exit(OVERFLOW);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREAMENT;
	}
	*s->top++ = e;
	return OK;
}

//��ջ
status pop(sqstack *s, SElemtype *e)
{
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

//�ж��Ƿ�Ϊ��ջ
status stackempty(sqstack *s)
{
	if (s->top == s->base)
		return OK;
	return ERROR;
}

//���ջ
status clearstack(sqstack *s)
{
	if (s->top == s->base)
		return ERROR;
	s->top = s->base;
	return OK;
}

//����ƥ���㷨
status Parenthesis_match(sqstack *s, char *str)
{
	int i = 0, flag = 0;
	SElemtype e;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '(':
			push(s, str[i]);
			break;
		case '[':
			push(s, str[i]);
			break;
		case ')':
		{
			pop(s, &e);
			if (e != '(')
				flag = 1;
		}
		break;
		case ']':
		{
			pop(s, &e);
			if (e != '[')
				flag = 1;
		}
		break;
		default:
			break;
		}
		if (flag)
			break;
		i++;
	}

	if (!flag && stackempty(s))
		printf("����ƥ��ɹ�!\n");
	else
		printf("����ƥ��ʧ��!\n");
	return OK;
}

int main()
{
	char str[100], enter;
	sqstack s;
	Init(&s);
	printf("���������Ŵ�:\n");
	scanf("%s", str);
	scanf("%c", &enter);
	Parenthesis_match(&s, str);
	return 0;
}

