//
//  main.c
//  数制转换
//
//  Created by Huhongbo on 2017/4/2.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
typedef enum
{
    Error,
    OK
}Status;
#define Status int
#define Error 0
#define OK 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
    int *base;
    int *top;
    int stacksize;
}SqStack;
//创建空栈
Status InitStack(SqStack *s)
{
    s->base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!s->base)
        return Error;
    else
    {
        s->top=s->base;
        s->stacksize=STACK_INIT_SIZE;
        return OK;
    }
}
//插入栈顶元素
Status Push(SqStack *s,int e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(int*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(int));
        if(!s->base)
            return Error;
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top=e;
    s->top++;
    return OK;
}
//判断是否为空
int StackEmpty(SqStack *s)
{
    if(s->top==s->base)
    {
        return 0;
    }
    else
        return 1;
}
//删除栈顶元素并返回其值
int Pop(SqStack *s)
{
    if(s->top==s->base)
        return 0;
    else
    {
        s->top--;
        return *s->top;
    }
}
int main()
{
    int n;
    SqStack S;
    InitStack(&S);
    printf("输入待转换的十进制数:\n");
    scanf("%d",&n);
    printf("转换为八进制为:\n");
    while(n)
    {
        Push(&S,n%8);
        n=n/8;
    }
    while(StackEmpty(&S))
    {
        printf("%d",Pop(&S));
    }
    return 0;
}
