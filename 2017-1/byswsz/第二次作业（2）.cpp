#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
#define DEBUG 1

typedef enum  
{ ERROR,
  OVERFLOW,
  OK}
Status;

typedef char SElemType;  
//对顺序栈进行定义
typedef struct  
{  
    SElemType *base;  
    SElemType *top;  
    int stacksize;  
}SqStack;  

Status  InitStack (SqStack* pS);//构造一个空栈
Status Push (SqStack *S , SElemType e);
int StackEmpty (SqStack *S);
Status Pop (SqStack S , int *e);
void Match(SqStack *S , char *p);


//构造一个空栈

Status  InitStack (SqStack* pS)    
{
	pS->base=(SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));

	if(! pS->base) 
	{
		return OVERFLOW;
	}

	pS->top =(*pS).base;
	pS->stacksize = STACK_INIT_SIZE;

	return OK;
}
//把一个新的元素添加到栈中
Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;

}

int StackEmpty(SqStack *S)
{
	if (S)
		return S->base==S->top;
	return 1;
}
//删除栈顶的元素,并用e返回其值
Status Pop(SqStack *S,int *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;
}
//自定义函数，对括号进行判定。
void Match(SqStack *S , char *p)
{
	    int i=0;
		int bracket;
		InitStack(S); //构造一个空栈
		while(p[i] != '\0')  
		{  
			DEBUG && printf("当前括号 '%c' ", p[i]);
			switch(p[i])  
			{  
			case '(':
				DEBUG && printf(" '%c' 入栈 \n", p[i]);
				Push(S,p[i]); //入栈时添加一个新的元素
				break; 

			case ')':  
				DEBUG && printf("  出栈  ");
                Pop(S,&bracket);//出栈时删除栈顶元素
				printf("结果是  '%c' \n",bracket);
					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("匹配失败\n");
						return;
					}//出栈的元素不与其对应
				
					break;
			case '[':  
				DEBUG && printf(" '%c' 入栈 \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ']':  
				DEBUG && printf("  出栈  ");
                Pop(S,&bracket);
				printf("结果是  '%c' \n",bracket);

					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("匹配失败\n");
						return;
					}
				
					break;
			default:  
				break;  
				}   
			i++;//循环执行，当配完时
			}   //while 循环结束。
		StackEmpty(S);//判断是否循环完
		DEBUG && printf("匹配成功 \n\n");//若debug成功则OK啦啦啦啦啦啦啦啦


}


int main()
{
	char str1[10]="([()])";  
	char str2[10]="[([][])]";
	char str3[10]="[((]])";
    SqStack S; 

	printf("开始匹配第一组 :");
	puts(str1);
    Match(&S,str1);  

	printf("开始匹配第二组 :");
	puts(str2);
    Match(&S,str2);

	printf("开始匹配第三组 :");
	puts(str3);
    Match(&S,str3);
    return 0;  
}//最后想说一句mmp，让我去哭一会儿呜呜呜呜呜呜

