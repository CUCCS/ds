 //ds 3.2.h  
 #include <stdio.h> 
 #include <stdlib.h> 
 #define STACK_INIT_SIZE 100//存储空间初始分配量 
 #define STACKINCREMENT 10//存储空间分配增量 
 typedef int SElemType; 
 typedef struct { 
	SElemType *base;//在构造前和销毁后，base的值为NULL 
	SElemType *top;//栈顶指针 
	int stacksize;//当前已分配的空间，以元素为单位 
 }SqStack;//定义栈 
 typedef enum { 
	OK, 
 	OVERFLOW, 
	ERROR 
 }Status;//定义返回值的枚举类型 
 typedef enum { 
	 false, 
	 true 
 } bool;//定义返回值 
 
 	  //栈的基本操作函数声明 
 Status InitStack(SqStack *S); 
 //构造一个空栈S 
 Status DestroyStack(SqStack *S)  ; 
 //销毁S 
 Status ClearStack(SqStack *S); 
 //把S置为空栈 
 bool StackEmpty(SqStack *S); 
 //若S为空栈则返回TRUE,否则返回FALSE 
 int StackLength(SqStack *S); 
 //返回S的元素个数，即栈的长度 
 Status GetTop(SqStack *S, SElemType e); 
 //若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR 
 Status Push(SqStack *S, SElemType e); 
 //插入元素e为新的栈顶元素 
 Status Pop(SqStack *S, SElemType *e); 
 //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR 
 Status StackTraverse(SqStack *S, Status(*visit)(SElemType)); 
 //从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败,则操作失败 
 Status visit(SElemType e); 
 //打印栈中元素 
 Status conversion(SqStack *S, int input, int d); 
 //实现数制转换 