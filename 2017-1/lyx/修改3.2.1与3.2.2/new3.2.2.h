 #include <stdio.h> 
 #include <stdlib.h> 
 #include <time.h>//生成随机数 
 #define STACK_INIT_SIZE 100//定义宏常量 
 typedef char SElemType;//定义SElemType为字符串 
 typedef enum 
{	OK, 
 	ERROR, 
	OVERFLOW 
 }Status;//枚举可能的现象 
 typedef struct _SqStack 
 {   SElemType *top; 
     SElemType*base; 
   	 int stacksize; 
 }SqStack;//定义结构体 
 typedef enum 
 {	true, 
 	false 
 }bool;//定义布尔 
 Status InitStack(SqStack *s);//构造一个空栈 
 Status brackets(SqStack *s,char*test);//括号匹配函数 
 bool StackEmpty(SqStack *s);//若栈s为空栈，则返回TRUE，否则返回FALSE 
 Status Pop(SqStack *s,SElemType *e);//若栈不空，则删除s的栈顶元素，用e返回其值，并返回OK；否则返回ERROR 
 Status GetTop(SqStack *s,SElemType *e);//若栈不空，则用e返回s的栈顶元素，并返回OK；否则返回ERROR 
 Status Push(SqStack *s,SElemType e);//插入元素e为新的栈顶元素 