//����ƥ��ļ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXLEN 50
typedef struct stack
{
	char ch[50];
	int top;
}ST;
//ջ�ĳ�ʼ��
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
//��ջ����
int Pop(ST *st)
{
	if (st->top == 0)
	{
		printf("ջΪ��\n");
		return 0;
	}
	st->top--;
	return st->ch[st->top];
}

//��ջ����
void Push(ST *st, char c)
{
	if (st->top == MAXLEN)
	{
		printf("ջ���\n");
		return;
	}
	st->ch[st->top] = c;
	st->top++;
}
//���ż��麯��
void check_symbol(ST *st, char *a)
{
	int i;
	Push(st, a[0]);

	for (i = 1; i< strlen(a); i++)
	{
		//����ÿһ��Ԫ�أ��жϳ�ջ������ջ
		if ((a[i] == ']'&&st->ch[st->top - 1] == '[') || (a[i] == ')'&&st->ch[st->top - 1] == '('))//��ջ������
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
		printf("������ƥ���\n\n");
	}
	else

	{
		printf("���Ų�ƥ��\n\n");
	}
}

void main()
{

	while (1)
	{
		char s[50];
		ST *st;
		st = ST_Init();
		printf("������һ������||���롮e���˳�����\n");
		scanf("%s", s);
		if (s[0] == 'e')
		{
			return ;
		}
		check_symbol(st, s);
	}

}
