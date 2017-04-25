//¿®∫≈∆•≈‰≥Ã–Ú
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

//≥ı ºªØ’ª
status Init(sqstack *s)
{
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

//ªÒ»°’ª∂•‘™Àÿ
status Gettop(sqstack *s, SElemtype e)
{
	if (s->top == s->base)
		return ERROR;
	e = *(s->top - 1);
	return OK;
}

//—π’ª
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

//≥ˆ’ª
status pop(sqstack *s, SElemtype *e)
{
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

//≈–∂œ «∑ÒŒ™ø’’ª
status stackempty(sqstack *s)
{
	if (s->top == s->base)
		return OK;
	return ERROR;
}

//«Âø’’ª
status clearstack(sqstack *s)
{
	if (s->top == s->base)
		return ERROR;
	s->top = s->base;
	return OK;
}

//¿®∫≈∆•≈‰À„∑®
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
		printf("¿®∫≈∆•≈‰≥…π¶!\n");
	else
		printf("¿®∫≈∆•≈‰ ß∞‹!\n");
	return OK;
}

int main()
{
	char str[100], enter;
	sqstack s;
	Init(&s);
	printf("«Î ‰»Î¿®∫≈¥Æ:\n");
	scanf("%s", str);
	scanf("%c", &enter);
	Parenthesis_match(&s, str);
	return 0;
}

