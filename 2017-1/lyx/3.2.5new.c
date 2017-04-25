#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>//生成随机值
//中缀表达式求值  
//先转为后缀表达式再求值；为简单起见，使用栈的循序存储结构实现  

//栈的顺序存储结构，用一维数组实现  
#define OK 1  
#define ERROR -1  
#define TRUE 1  
#define FALSE 0  
#define MAXSIZE 10  
typedef int Status;  
typedef char ElemType;  
typedef struct 
{  
	ElemType data[MAXSIZE];  
	int top;//栈顶指针  
}Stack;  

Status InitStack(Stack *S)
{  //初始化
	int i;  
	for(i=0;i<MAXSIZE;i++)  
    {
		S->data[i]=NULL;  //初始化为空
    }
	S->top=-1;  
	return OK;  
}  
 
Status CreateStack(Stack *S,int n)
{  //创建一个长度为n的堆栈 
	if(n>MAXSIZE || n<1)
	{  
		printf("输入长度有误！\n");  
		return ERROR;  
	}  
	srand(time(0));  
	int i;  
	for(i=0;i<n;i++)
	{  
		S->data[i]=rand()%100+1;//随机生成元素  
	}  
	S->top=n-1;  
	return OK;  
}  

Status push(Stack *S,ElemType e)
{//压栈操作  
	if(MAXSIZE-1==S->top)//判断是否栈满
	{  
		printf("栈已满\n");  
		return ERROR;  
	}  
	//栈顶指向的元素有值  
	++(S->top);  
	S->data[S->top]=e;  
	return OK;  
}  

Status pop(Stack *S,ElemType *e)
{//出栈  
	//将栈顶元素出栈，传给e  
	if(-1==S->top)
	{  
		printf("栈为空！\n");  
		return ERROR;  
	}  
	*e=S->data[S->top];  
	--(S->top);  
	return OK;  
}  

int MidToFinal(char *mid,char *final)
{//中缀表达式转后缀表达式   
	//中缀表达式为middle，要转换成后缀表达式传给last  
	//新建一个栈，来存储符号  
	char e;  
	Stack S;  
	if(OK!=InitStack(&S))
	{  
		printf("初始化栈失败！\n");  
	}  
	//当带转换的字符串*mid未终止时，循环处理  
	while(*mid)
	{//如果是数字，则直接输出  
		if(*mid>='0' && *mid<='9')
		{  
			*(final++)=*(mid++);  
			continue;  
		}
		else if(*mid=='+' || *mid=='-' || *mid=='*' || *mid=='/' || *mid=='(' || *mid==')')
		{//输入的是合法运算符号,比较之前是否有更高优先级的符号  
			if(S.top==-1 || '('==*mid)
			{  
				//当符号栈为空或遇到左括号时，符号入栈  
				push(&S,*(mid++));  
				continue;  
			}  
			if(')'==*mid)
			{  
				//遇到右括号时，栈顶元素依次出栈；直到遇到第一个左括号时结束  
				pop(&S,&e);  
				*(final++)=e;  
				while(pop(&S,&e) && e!='(')
				{  
					*(final++)=e;  
				}  
				// printf("%c\n",e);  
				mid++;  
				continue;  
			}  
			//后续的处理都要取出临时的栈顶元素，与当前输入的符号*mid相比较；
			//当临时栈顶元素优先级大于等于输入符号的优先级时，出栈；
			//否则符号入栈（已经弹出一个，记得把弹出的元素也入栈）  
			pop(&S,&e);  
			if('+'==*mid || '-'==*mid)
			{  
				if(e=='(')
				{  
					push(&S,'(');  
					push(&S,*(mid++));  
					continue;  
				}
				else
				{  
					*(final++)=e;  
					push(&S,*(mid++));  
					continue;  
				}  
			}
			else if('*'==*mid || '/'==*mid)
			{  
				if('*'==e || '/'==e)
				{  
					*(final++)=e;  
					push(&S,*(mid++));  
					continue;  
				}
				else
				{  
					push(&S,e);  
					push(&S,*(mid++));  
					continue;  
				}  
			}  

		}
		else
		{  
			printf("输入的字符不合法！%c\n",*mid);  
			return ERROR;  
		}  
	}  
	//当待转换的字符已经结束时，符号栈至少还有一个元素（中缀表达式的特点：数字结尾；后缀表达式以符号结尾）；将栈中的元素依次出栈  
	while(S.top!=-1)
	{  
		pop(&S,&e);  
		*(final++)=e;  
	}  
	//字符串的结束符！  
	*final='\0';  
}  

int main()  
{  
	char data[]="3+(5*6-7/1)*9";  
	char final[]="";  
	MidToFinal(data,final);  
	printf("%s\n",final);  
	return 0;  
}  