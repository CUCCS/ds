#include "pair.h"
#include <stdio.h>  
#include <math.h>     //����overflow  
#include <process.h>  //exit()  


void main()
{

	char ch[100];
	char *p;
	int e;
	SqStack s;

	InitStack(&s);  //��ʼ����ջ  
	p = ch; //ָ��pָ���ַ�����ch

	printf("��һ��������()[]{}�����ű��ʽ:\n");
	gets(ch);

	while (*p)
	{
		switch (*p)
		{
		case '{':
		case '[':
		case '(': push(&s, *p++); break;//sֻҪ�������ž���ջ  
		case '}':
		case ']':
		case ')':pop(&s, &e);  //sֻҪ�������ž���ջ�е�������e���
			if ((e == '{' && *p == '}') || (e == '[' && *p == ']') || (e == '(' && *p == ')'))
			{
				p++;
			}
			else
			{
				printf("���Ų�ƥ��!\n");
				return OVERFLOW;
			}//����OVERFLOW��ֵ����������
			break;
		default:p++;//�����ַ��ͺ���  
		}
	}
	if (StackEmpty(s))
	{
		printf("����ƥ��ɹ�");
	}//����ջ��ɺ���ջ�Ƿ�Ϊ��,��Ϊ��������������Ŷ�ƥ��ɹ�
	else
	{
		printf("ȱ�������ţ�");
	}//����ջ����ʣ��������ţ���Բ��ɹ�
	printf("\n");
	return 0;
}

