//顺序栈实现中缀表达式转后缀表达式并计算表达式的值
//输出表达式 以及计算结果
//可计算+-*/及含有括号的表达式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 50//输入字符串长度
#define OK 1  
#define ERROR -1  
#define TRUE 1  
#define FALSE 0  
#define MAXSIZE 50  //栈容量
typedef int Status;
typedef char ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int top;//栈顶指针  
}Stack;

// 初始化栈  
Status InitStack(Stack *S) {
	
	int i;
	for (i = 0; i<MAXSIZE; i++)
		S->data[i] = NULL;
	S->top = -1;
	return OK;
}


//压栈 
Status Push(Stack *S, ElemType e) {
	if (MAXSIZE - 1 == S->top)
	{
		
		return ERROR;
	}
	
	++(S->top);
	S->data[S->top] = e;
	return OK;
}

//出栈  
Status Pop(Stack *S, ElemType *e) {
	//将栈顶元素出栈，赋给e  
	if (-1 == S->top)
	{
		return ERROR;
	}
	*e = S->data[S->top];
	--(S->top);
	return OK;
}

Status Transform(char *mid,char *final)
{
	//中缀表达式为mid，转换成的后缀表达式传给final 
	//新建一个栈，来存储运算符
	char e;
	Stack S;
	if (OK != InitStack(&S)) 
	{
		return ERROR;
	}
	//当字符串*mid未终止时，循环  
	while (*mid) 
	{
		//如果是数字，则直接输出  
		if (*mid >= '0' && *mid <= '9') 
		{
			*(final++) = *(mid++);
			continue;
		}
		else if (*mid == '+' || *mid == '-' || *mid == '*' || *mid == '/' || *mid == '(' || *mid == ')') 
		{
			//比较之前是否有更高优先级的符号  
			if (S.top == -1 || '(' == *mid) 
			{
				//当栈为空或遇到左括号时，直接入栈  
				Push(&S, *(mid++));
				continue;
			}
			if (')' == *mid) 
			{
				//遇到右括号时，栈顶元素依次出栈；直到遇到第一个左括号时结束  
				Pop(&S, &e);
				*(final++) = e;
				while (Pop(&S, &e) && e != '(') 
				{
					*(final++) = e;
				}  
				mid++;
				continue;
			}
			//接下来取出临时的栈顶元素，与当前输入的符号*mid相比较；当栈顶元素优先级大于等于输入符号的优先级时，出栈，且*mid入栈；
			//否则符号入栈 
			Pop(&S, &e);
			if ('+' == *mid || '-' == *mid) 
			{
				if (e == '(') 
				{
					Push(&S, '(');
					Push(&S, *(mid++));
					continue;
				}
				else 
				{
					*(final++) = e;
					Push(&S, *(mid++));
					continue;
				}
			}
			else if ('*' == *mid || '/' == *mid) 
			{
				if ('*' == e || '/' == e) 
				{
					*(final++) = e;
					Push(&S, *(mid++));
					continue;
				}
				else 
				{
					Push(&S, e);
					Push(&S, *(mid++));
					continue;
				}
			}

		}
		else {
			//输入的字符不合法
			return ERROR;

		}
	}
	//当待转换的字符已经结束时，符号栈应至少还有一个元素，将栈中的元素依次出栈  
	while (S.top != -1) 
	{
		Pop(&S, &e);
		*(final++) = e;
	}
	//final的结束符
	*final = '\0';
}

//计算后缀表达式，若数字直接进栈，若是运算符则两个数字出栈，运算结果进栈，最终栈内只剩最后的结果
int Cul(char *a,Stack s)
{
	int e1=0, e2=0,e=0;

	
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= '0'&&a[i] <= '9')
			Push(&s,(int)( a[i]-'0'));
		
		else if (a[i] == '+')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			 e = e1 + e2 ;
			Push(&s, e);
		}
		else if (a[i] == '-')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
		    e = e1 - e2;
			Push(&s, e);
		}
		else if (a[i] == '*')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			e = e1 * e2;
			Push(&s, e);
		}
		else if (a[i] == '/')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			e = e1 / e2;
			Push(&s, e);
		}
	}
	Pop(&s, &e);
	
	return (int)(e);
				
}


void main()
{
	Stack s;
	InitStack(&s);
	char middle[N];
	char final[N];
	int r;
	printf("Please input an expression:\n");
	gets(middle);
	Transform(middle,final);
	printf("After:\n");
	puts(final);
	r = Cul(final,s);
	printf("The result is %d",r);

}
