#include "3.2.3.h"

Status LineEdit(SqStack*s,char *a)
{

	char c;
	char ch;
	ch =getchar();

	printf("过程如下：\n");
	while (ch != EOF)
	{
		while (ch != EOF&&ch != '\n')
		{
			switch (ch)
			{
			case '#':
			{
				Pop(s, &c);
				SElemType*l = s->base;
				while (l != s->top)
				{
					printf("%c", *l);
					l++;

				}
				printf("\n");
				break;
			}
			case '@':
			{
				ClearStack(s);
				SElemType*l = s->base;
				while (l != s->top)
				{
					printf("%c", *l);
					l++;

				}
				printf("\n");
				break;
			}
			default:
			{
				Push(s, ch);
				SElemType*l = s->base;
				while (l != s->top)
				{
					printf("%c", *l);
					l++;

				}
				printf("\n");
			}
			}
			ch = getchar();

		}
		int i = 0;
		while (s->top != s->base)
		{
			a[i] = *(s->base);
			s->base++;
			i++;
		}

		a[i] = '\0';
		printf("输出结果如下:\n");
		puts(a);
		ClearStack(s);
		if (ch != EOF)
		{
			ch = getchar();
		
		}
	}

	DistoryStack(&s);
	return OK;
}


bool StackEmpty(SqStack*s)
{
	if (s->base == s->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Status ClearStack(SqStack*s)
{
	s->top = s->base;
	return OK;
}


Status DistoryStack(SqStack *s)
{
	while (!StackEmpty)
	{
		s->top = NULL;
		s->top--;
	}
	s->base = NULL;
	free(s->base);
	free(s->top);
	return OK;
}


Status InitStack(SqStack*s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}


Status Push(SqStack*s, SElemType e)
{
	if (s->top - s->base > s->stacksize)
	{
		s->base = (SElemType*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElemType));
		if (!s->base)
		{
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += 2 * STACK_INIT_SIZE;
	}
	*s->top = e;
	s->top++;
	return OK;

}
Status Pop(SqStack*s, SElemType*e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	else
	{
		*e = *--s->top;
		return OK;
	}

}
