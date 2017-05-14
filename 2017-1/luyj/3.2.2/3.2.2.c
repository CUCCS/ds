#include "3.2.2.h"

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


Status Marry(SqStack *s, char*test)
{
	int i;
	int j = 0;
	SElemType e;
	SElemType m;
	SElemType n;
	for (i = 0; test[i] != '\0'; i++)
	{
		switch (test[i])
		{
		case '[':
		{
			Push(s, test[i]);
			SElemType*l = s->base;
			while (l != s->top)
			{
				printf("%c", *l);
				l++;

			}
			printf("\n");
			break;
		}
		case '{':
		{
			Push(s, test[i]);
			SElemType*l = s->base;
			while (l != s->top)
			{
				printf("%c", *l);
				l++;

			}
			printf("\n");
			break;
		}
		case '(':
		{
			Push(s, test[i]);
			SElemType*l = s->base;
			while (l != s->top)
			{
				printf("%c", *l);
				l++;

			}
			printf("\n");
			break;
		}
		case ']':
		{
			GetTop(s, &e);
			if (e == '[')
			{
				if (StackEmpty(s) == false)
				{
					Pop(s, &m);
					SElemType*l = s->base;
					while (l != s->top)
					{
						printf("%c", *l);
						l++;

					}
					printf("\n");

				}
			}
			else
			{
				Push(s, test[i]);
				SElemType*l = s->base;
				while (l != s->top)
				{
					printf("%c", *l);
					l++;

				}
				printf("\n");
			}
			break;
		}
		case '}':
		{
			GetTop(s, &e);
			if (e == '{')
			{
				if (StackEmpty(s) == false)
				{
					Pop(s, &m);
					SElemType*l = s->base;
					while (l != s->top)
					{
						printf("%c", *l);
						l++;

					}
					printf("\n");
				}
			}
			else
			{
				Push(s, test[i]);
				SElemType*l = s->base;
				while (l != s->top)
				{
					printf("%c", *l);
					l++;

				}
				printf("\n");
			}
			break;
		}
		case ')':
		{
			GetTop(s, &e);
			if (e == '(')
			{
				if (StackEmpty(s) == false)
				{
					Pop(s, &m);
					SElemType*l = s->base;
					while (l != s->top)
					{
						printf("%c", *l);
						l++;

					}
					printf("\n");
				}
				else
				{
					Push(s, test[i]);
					SElemType*l = s->base;
					while (l != s->top)
					{
						printf("%c", *l);
						l++;

					}
					printf("\n");

				}
				break;
			}
		}
		}

	}
	if (StackEmpty(s) == true)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
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


Status Pop(SqStack*s, SElemType *e)
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


Status GetTop(SqStack*s, SElemType* e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	*e = *(s->top - 1);
	return OK;
}
