#include "edit.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0

//初始化栈
int InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) {
		return OVERFLOW;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}

//入栈
int Push(SqStack *S, SElemType e) {
	if ((S->top - S->base) >= S->stacksize) {
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base) {
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	//printf("%c\n",e);
	return OK;
}

//删除栈中的元素
int Pop(SqStack *S, SElemType *e) {
	if (S->top == S->base) {
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}


//清空栈中的元素
int ClearStack(SqStack *S) {
	S->top = S->base;
	return OK;
}

//销毁栈
int DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}

//行编辑程序
void LineEdit(SqStack *S) {
	SElemType *p, ch, c;
	InitStack(S);
	ch = getchar();
	while (ch != -1) {
		while (ch != -1 && ch != '\n') {
			switch (ch) {
			case '#':Pop(S, &c); break;//仅当栈非空时退栈
			case '@':ClearStack(S); break;//重置S为空栈
			default:Push(S, ch); break;//有效字符进栈，未考虑栈满情况
			}
			ch = getchar();//从终端接收下一个字符
		}
		p = S->base;
		while (p != S->top) {
			printf("%c", *p);
			++p;
		}
		//将从栈底到栈顶的站内字符传送至调用过程的数据区
		ClearStack(S);//重置S为空栈
		if (ch != EOF)
		{
			ch = getchar();
		}
	}

}