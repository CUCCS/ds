//括号匹配的检验程序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXLEN 50
typedef struct stack
{
	char ch[50];
	int top;
}ST;
//栈的初始化
ST *ST_Init()
{
	ST *st;
	if (st = (ST *)malloc(sizeof(ST)))
	{
		st->top = 0;
		return st;
	}
	return NULL;
}
//出栈操作
int Pop(ST *st)
{
	if (st->top == 0)
	{
		printf("栈为空\n");
		return 0;
	}
	st->top--;
	return st->ch[st->top];
}

//入栈操作
void Push(ST *st, char c)
{
	if (st->top == MAXLEN)
	{
		printf("栈溢出\n");
		return;
	}
	st->ch[st->top] = c;
	st->top++;
}
//符号检验函数
void check_symbol(ST *st, char *a)
{
	int i;
	Push(st, a[0]);

	for (i = 1; i< strlen(a); i++)
	{
		//遍历每一个元素，判断出栈还是入栈
		if ((a[i] == ']'&&st->ch[st->top - 1] == '[') || (a[i] == ')'&&st->ch[st->top - 1] == '('))//出栈的条件
		{
			Pop(st);
		}
		else
		{
			Push(st, a[i]);
		}
	}
	if (st->top == 0)
	{
		printf("括号是匹配的\n\n");
	}
	else

	{
		printf("括号不匹配\n\n");
	}
}

void main()
{

	while (1)
	{
		char s[50];
		ST *st;
		st = ST_Init();
		printf("请输入一串括号||输入‘e’退出程序：\n");
		scanf("%s", s);
		if (s[0] == 'e')
		{
			return ;
		}
		check_symbol(st, s);
	}

}
