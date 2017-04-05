//
//  main.c
//  括号匹配
//
//  Created by Huhongbo on 2017/4/2.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define STACKINCREAMENT 10
#define STACK_INIT_SIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int status;
typedef char SElemtype;
typedef struct
{
    SElemtype *base;
    SElemtype *top;
    status stacksize;
}sqstack;

//初始化栈
status InitStack(sqstack *s)
{
    s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
    if(!s->base)
        exit(OVERFLOW);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE ;
    return OK;
}

//获取栈顶元素
status Gettop(sqstack *s, SElemtype e)
{
    if(s->top == s->base)
        return ERROR;
    e = *(s->top-1);
    return OK;
}

//压栈
status Push(sqstack *s, SElemtype e)
{
    if(s->top - s->base >= s->stacksize)
    {
        s->base = (SElemtype *)realloc(s->base, (s->stacksize + STACKINCREAMENT) * sizeof(SElemtype));
        if(!s->base)
            exit(OVERFLOW);
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREAMENT;
    }
    *s->top++ = e;
    return OK;
}

//出栈
status Pop(sqstack *s, SElemtype *e)
{
    if(s->top == s->base)
        return ERROR;
    *e=*--s->top;
    return OK;
}

//判断是否为空栈
status IsStackEmpty(sqstack *s)
{
    if(s->top==s->base)
        return OK;
    return ERROR;
}

//清空栈
status Clearstack(sqstack *s)
{
    if(s->top == s->base)
        return ERROR;
    s->top = s->base;
    return OK;
}

//括号匹配算法
status Match(sqstack *s,char *str)
{
    int i=0, flag=0;
    SElemtype e;
    while(str[i] != '\0')
    {
        switch(str[i])
        {
            case '(':
                Push(s,str[i]);
                break;
            case '[':
                Push(s,str[i]);
                break;
            case ')':
            {
                Pop(s,&e);
                if(e != '(')
                    flag=1;
            }
                break;
            case ']':
            {
                Pop(s,&e);
                if(e!='[')
                    flag=1;
            }
                break;
            default:
                break;
        }
        if(flag)
            break;
        i++;
    }
    
    if(!flag && IsStackEmpty(s))
        printf("括号匹配成功!\n");
    else
        printf("括号匹配失败!\n");
    return OK;
}

int main()
{
    char str[100], enter;
    sqstack s;
    InitStack(&s);
    printf("请输入字符串:\n");
    scanf("%s",str);
    scanf("%c",&enter);
    Match(&s,str);
    return 0;
}
