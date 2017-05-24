#include <stdlib.h>

#include "stack.h"
#include "myds.h"

Status InitStack (SqStack *S, int maxsize)
{
    // 构造一个最大空间为 maxsize 的空顺序栈 S
    S->base = (SElemType *)malloc(maxsize * sizeof(SElemType));
    if (!S->base) {
        return OVERFLOW; //存储分配失败
    }
    S->top = S->base;
    S->stacksize = maxsize;
    return OK;
}

void DestroyStack(SqStack *S)
{
    if(S->base != NULL)
    {
        free(S->base);
    }
}


Status Push (SqStack *S, SElemType e) 
{ // 若栈不满，则将 e 插入栈顶
    if (S->top - S->base >= S->stacksize) { //栈满
        return OVERFLOW;
    }
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e) {
    // 若栈不空，则删除S的栈顶元素，
    // 用 e 返回其值，并返回OK；
    // 否则返回ERROR
    if (S->top == S->base) { 
        return ERROR;
    }
    *e = *--S->top;
    return OK;
}

bool IsEmptyStack(SqStack S)
{
    return S.base == S.top;
}

