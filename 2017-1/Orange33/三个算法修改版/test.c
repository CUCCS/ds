#include <stdio.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100  //存储空间初始分配
#define STACKINCREMENT 10  //存储空间分配增量
#define OVERFLOW -2

typedef struct SqStack{  
	int *base; //栈底  
	int *top;  //栈顶  
	int StackSize;   //栈当前的存储空间  
}SqStack;  

//初始化空栈
void InitStack(SqStack *S)  
{
	S->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int)); //分配基本空间 
	S->StackSize=STACK_INIT_SIZE;   //初始链表最大长度
	S->top=S->base;  //指向栈顶
};  
//判断栈是否为空
int StackEmpty(SqStack S)  
{  
	if(S.base==S.top) 
	{
		return 1;  
	}
	else  
	{
		return 0;  
	}
};

//压栈
void push(SqStack *S,int e)  
{  
	if(S->top-S->base>=S->StackSize)  //空间不足
	{
		S->base=(int *)realloc(S->base,(S->StackSize+STACKINCREMENT)*sizeof(int));  
		S->top=S->base+S->StackSize;  
		S->StackSize+=STACKINCREMENT;
	}  
	*(S->top)=e;  
	S->top++;        
};

//出栈
void pop(SqStack *S,int *e)  
{  
	if(S->base!=S->top)  
	{
		S->top--;  
		*e=*S->top;
	}  
};  


int main()  
{

	char test[100];
	char *p;
	int e; 
	SqStack S;

	InitStack(&S);  //初始化空栈  
	p=test; //指针p指向字符数组ch

	printf("请输入括号:"); 
	gets(test);

	while(*p)
	{   
		switch (*p)  
		{  
		case '{':  
		case '[':  
		case '(': push(&S,*p++);break;//只要是左括号就入栈  
		case '}':  
		case ']':  
		case ')':pop(&S,&e);  //只要是右括号就与栈中的左括号e配对
			if ((e=='{' && *p=='}') ||(e=='[' && *p==']') || (e=='(' && *p==')'))  
			{
				p++;  
			}
			else  
			{
				printf("括号不匹配!");
				return OVERFLOW;
			}
			break;  
		default:
			p++;
		}  
	}  
	if (StackEmpty(S))  
	{
		printf("括号匹配成功");
	}//检查栈是否为空,若为空则代表所有括号都匹配成功
	else  
	{
		printf("缺少右括号！"); 
	}//否则栈中有剩余的左括号,匹配失败
	printf("\n");  
}

