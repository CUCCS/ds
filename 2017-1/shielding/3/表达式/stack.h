#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 10 // 存储空间初始分配量 
#define STACKINCREMENT 2 // 存储空间分配增量

typedef char SElemType;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;

typedef enum{
	FALSE,
	TRUE
}bool;

typedef struct SqStack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S){ 
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)
		return OVERFLOW; 
	S->top = (*S).base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestroyStack(SqStack *S){
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	return OK;
}

Status ClearStack(SqStack *S){ 
	(*S).top = (*S).base;
	return OK;
}

Status StackEmpty(SqStack *S){
	if ((*S).top == (*S).base)
		return TRUE;
	else
		return FALSE;
}// 若栈S为空栈，则返回TRUE，否则返回FALSE 

int StackLength(SqStack S){
	return S.top - S.base;
}// 返回S的元素个数，即栈的长度

Status GetTop(SqStack *S, SElemType *e){
	if ((*S).top>(*S).base){
		*e = *((*S).top - 1);
		return OK;
	}
	else
		return ERROR;
}// 若栈不空，则用e返回S的栈顶元素

Status Push(SqStack *S, SElemType e){
	if ((*S).top - (*S).base >= (*S).stacksize){//栈满
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base){
			exit(OVERFLOW);
		}//分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}// 插入元素e为新的栈顶元素

Status Pop(SqStack *S, SElemType *e){
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
} // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR 

Status StackTraverse(SqStack S, Status(*visit)(SElemType)){
	while (S.top>S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}// 从栈底到栈顶依次对栈中每个元素调用函数visit()


Status visit(SElemType c){
	printf("%c ", c);
	return OK;
}
