//
//  main.c
//  后缀表达式求值
//
//  Created by Huhongbo on 2017/4/5.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tag_STACK_STRU
{
    float valueData;
    struct tag_STACK_STRU *pNext;
}stackList;                 //用链表实现数据的存储

stackList *g_stOperand = NULL;          //操作数
stackList *g_stOperator = NULL;                 //操作符

void makeEmpty(stackList *stack);           //清空栈
char isEmpty(stackList *stack);         //判断栈是否为空

void push(stackList *stack, float data);        //入栈操作
void pop(stackList *stack);             //出栈操作
void calculate(char *p);                //计算
void changeStr(char *p);                //将中缀表达式转换为后缀表达式

char suffixStr[1024];

int main()
{
    
    
    char *p = (char *)malloc(sizeof(char));
    
    g_stOperand = (stackList *)malloc(sizeof(stackList));
    g_stOperand->pNext = NULL;
    makeEmpty(g_stOperand);
    
    g_stOperator = (stackList *)malloc(sizeof(stackList));
    g_stOperator->pNext = NULL;
    makeEmpty(g_stOperator);
    
    scanf("%s",p);      //获取输入的中缀表达式
    
    changeStr(p);       //将中缀表达式转换成后缀表达式
    calculate(suffixStr);   //通过后缀表达式进行计算
    
    printf("%d", (int)g_stOperand->pNext->valueData); //打印出最后结果
    return 0;
}

//清空栈的操作
void makeEmpty(stackList *stack)
{
    if (stack == NULL)
        printf("must creat stack first");
    
    while(!isEmpty(stack))
        pop(stack);
}
//判断栈是否为空
char isEmpty(stackList *stack)
{
    return (stack->pNext == NULL);
}
//入栈操作
void push(stackList *stack, float data)
{
    stackList *pTemp = (stackList *)malloc(sizeof(stackList));
    if (stack == g_stOperand)   //操作数入栈
    {
        if (pTemp == NULL)
            return;
        pTemp->valueData = data;
        pTemp->pNext = stack->pNext;
        stack->pNext = pTemp;
    }
    if (stack == g_stOperator)  //操作符入栈
    {
        if (pTemp == NULL)
            return;
        pTemp->valueData = data;
        pTemp->pNext = stack->pNext;
        stack->pNext = pTemp;
    }
}
//出栈操作
void pop(stackList *stack)
{
    stackList *pTop = NULL;
    if (isEmpty(stack))
        return;
    pTop = stack->pNext;
    stack->pNext = stack->pNext->pNext;
    free(pTop);
}
//计算
void calculate(char *p)
{
    float a, b, t;
    char temp[100];
    int i = 0;
    
    makeEmpty(g_stOperand);
    makeEmpty(g_stOperator);
    
    while(*p)
    {
        if((*p >= '0') && (*p <= '9'))
        {
            
            while((*p >= '0') && (*p <= '9'))
            {
                temp[i] = *p;
                p++;
                i++;
            }
            push(g_stOperand, atoi(temp));
            memset(temp, 0, sizeof(temp));
            i = 0;
        }
        if (*p == '+')
        {
            a = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            b = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            t = b + a;
            push(g_stOperand, t);
        }
        if (*p == '-')
        {
            a = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            b = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            t = b - a;
            push(g_stOperand, t);
        }
        if (*p == '*')
        {
            a = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            b = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            t = b * a;
            push(g_stOperand, t);
        }
        if (*p == '/')
        {
            a = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            b = g_stOperand->pNext->valueData;
            pop(g_stOperand);
            t = b / a;
            push(g_stOperand, t);
        }
        p++;
    }
}

void changeStr(char *p)
{
    stackList *k = (stackList *)malloc(sizeof(stackList));
    int i = 0;
    k = g_stOperator;
    while(*p)
    {
        if((*p >= '0') && (*p <= '9'))
        {
            while((*p >= '0') && (*p <= '9'))
            {
                suffixStr[i] = *p;
                p++;
                i++;
            }
            suffixStr[i++] = ',';
        }
        if (*p == '+')
        {
            if ( ( isEmpty(g_stOperator) ) )
                push(g_stOperator, 1);
            else if ( (g_stOperator->pNext->valueData - 1) > 2 )
            {
                while ( !isEmpty(g_stOperator) )
                {
                    switch ((int)g_stOperator->pNext->valueData)
                    {
                        case 1: suffixStr[i++] = '+'; suffixStr[i++] = ','; break;
                        case 2: suffixStr[i++] = '-'; suffixStr[i++] = ','; break;
                        case 5: suffixStr[i++] = '*'; suffixStr[i++] = ','; break;
                        case 6: suffixStr[i++] = '/'; suffixStr[i++] = ','; break;
                    }
                    pop(g_stOperator);
                }
                push(g_stOperator, 1);
            }
            else
                push(g_stOperator, 1);
            p++;
        }
        if (*p == '-')
        {
            if ( ( isEmpty(g_stOperator) ) )
                push(g_stOperator, 2);
            else if ( (g_stOperator->pNext->valueData - 1) > 2 )
            {
                while ( !isEmpty(g_stOperator) )
                {
                    switch ((int)g_stOperator->pNext->valueData)
                    {
                        case 1: suffixStr[i++] = '+'; suffixStr[i++] = ','; break;
                        case 2: suffixStr[i++] = '-'; suffixStr[i++] = ','; break;
                        case 5: suffixStr[i++] = '*'; suffixStr[i++] = ','; break;
                        case 6: suffixStr[i++] = '/'; suffixStr[i++] = ','; break;
                    }
                    pop(g_stOperator);
                }
                push(g_stOperator, 2);
            }
            else
                push(g_stOperator, 2);
            p++;
        }
        if (*p == '*')
        {
            push(g_stOperator, 5);
            p++;
        }
        if (*p == '/')
        {
            push(g_stOperator, 6);
            p++;
        }
    }
    while ( !isEmpty(g_stOperator) )
    {
        switch ((int)g_stOperator->pNext->valueData)
        {
            case 1: suffixStr[i++] = '+'; suffixStr[i++] = ','; break;
            case 2: suffixStr[i++] = '-'; suffixStr[i++] = ','; break;
            case 5: suffixStr[i++] = '*'; suffixStr[i++] = ','; break;
            case 6: suffixStr[i++] = '/'; suffixStr[i++] = ','; break;
        }
        pop(g_stOperator);
    }
}

