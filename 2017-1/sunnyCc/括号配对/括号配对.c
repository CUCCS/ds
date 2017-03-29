#include "pair.h"
#include <stdio.h>  
#include <math.h>     //含有overflow  
#include <process.h>  //exit()  


void main()
{

	char ch[100];
	char *p;
	int e;
	SqStack s;

	InitStack(&s);  //初始化空栈  
	p = ch; //指针p指向字符数组ch

	printf("输一个含义有()[]{}的括号表达式:\n");
	gets(ch);

	while (*p)
	{
		switch (*p)
		{
		case '{':
		case '[':
		case '(': push(&s, *p++); break;//s只要是左括号就入栈  
		case '}':
		case ']':
		case ')':pop(&s, &e);  //s只要是右括号就与栈中的左括号e配对
			if ((e == '{' && *p == '}') || (e == '[' && *p == ']') || (e == '(' && *p == ')'))
			{
				p++;
			}
			else
			{
				printf("括号不匹配!\n");
				return OVERFLOW;
			}//返回OVERFLOW的值给主调进程
			break;
		default:p++;//其他字符就后移  
		}
	}
	if (StackEmpty(s))
	{
		printf("括号匹配成功");
	}//出入栈完成后检查栈是否为空,若为空则代表所有括号都匹配成功
	else
	{
		printf("缺少右括号！");
	}//否则栈中有剩余的左括号，配对不成功
	printf("\n");
	return 0;
}

