//
//  main.c
//  行编辑程序
//
//  Created by Huhongbo on 2017/4/2.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef enum
{
    Error,
    OK
}Status;

typedef struct {
    char *base;
    char *top;
    int stacksize;
}SqStack;
//创建空栈
Status InitStack(SqStack *s)
{
    s->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
    if (!s->base)
        return Error;
    else
    {
        s->top = s->base;
        s->stacksize = STACK_INIT_SIZE;
        return OK;
    }
}
//插入栈顶元素
Status Push(SqStack *s, char e)
{
    
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (char*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(char));
        if (!s->base)
            return Error;
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *s->top = e;
    s->top++;
    return OK;
}
//若栈不空，则删除栈顶元素并返回
Status Pop(SqStack *s)
{
    if (s->top == s->base)
        return Error;
    s->top--;
    return OK;
}
//清空栈
Status ClearStack(SqStack *s)
{
    s->top = s->base;
    return OK;
}
//输出
Status Print(SqStack *s)
{
    char *p;
    p = s->base;
    while (p != s->top)
    {
        printf("%c", *p);
        p++;
    }
    return OK;
}
//行编辑函数
Status LineEdit(SqStack *s)
{
    char str;
    scanf("%c", &str);
    while (str != '/')
    {
        while (str!='/'&&str != '\n')
        {
            switch (str)
            {
                case '#':
                    Pop(s);
                    break;
                case '@':
                    ClearStack(s);
                    break;
                default:
                    Push(s, str);
                    break;
            }
            scanf("%c", &str);
        }
        Print(s);
        printf("\n");
        if(str!='/')
            scanf("%c", &str);
    }
    return OK;
}

int main()
{
    SqStack s;
    InitStack(&s);
    LineEdit(&s);
    return 0;
}
