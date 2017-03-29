#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef int SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
enum bool{ false, true };
typedef struct _SqStack{
	SElemType   *base;
	//造之前和销毁之后，base的值为NULL
	SElemType *top; //栈顶指针
	int stracksize;
}SqStack;
Status InitStack(SqStack *S){
	//构建一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e){
	//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stracksize){//栈满，追加存储空间
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//存储分配失败
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//为空
	else
		return false;//不为空
}
int main() 
{//子函数声明
SqStack S;
SElemType e;
  InitStack( &S);//初始化空栈 
  StackEmpty( &S);//判空  
  Push( &S, e);//进栈 
  Pop(  &S, &e);//出栈 
 //主函数开始 
 char ch[100],*p;int ei; 
 p=ch; 
 printf("输一个含义有()[]{}的括号表达式:\n"); 
gets(ch); 
 while(*p) 
 { 
 switch (*p) 
 { 
 case '{': 
 case '[': 
 case '(': 
 Push(&S,*p++);
 break;//只要是左括号就入栈 
 case '}': 
 case ']': 
 case ')':
 Pop(&S,&ei); 
 if ((ei=='{' && *p=='}')||(ei=='[' && *p==']') || (ei=='(' && *p==')')) 
 p++; 
 else 
 {printf("括号不匹配!");exit(OVERFLOW); break;} 
 
 default :p++;//其他字符就后移 
 } 
 } 
 if (StackEmpty(&S)) 
 printf("括号匹配成功"); 
 else 
 printf("括号不匹配"); 
 printf("\n"); 
} 
