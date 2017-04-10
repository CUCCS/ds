//
//  main.c
//  houzhui
//
//  Created by Huhongbo on 2017/4/10.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char SElemType;
typedef double SElem;
typedef enum
{
    OK,
    ERROR,
    OVERFLOW
}Status;
typedef struct _SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

typedef struct _SqStack1
{
    SElem *base;
    SElem *top;
    int stacksize;
}SqStack1;

typedef enum
{
    true,
    false
}bool;

Status Pop(SqStack*s, SElemType*e);
bool StackEmpty(SqStack*s);
Status InitStack(SqStack*s);
Status Push(SqStack*s, SElemType e);
Status GetTop(SqStack *s, SElemType *e);


Status Pop1(SqStack1*s, SElem*e);
bool StackEmpty1(SqStack1*s);
Status InitStack1(SqStack1*s);
Status Push1(SqStack1*s, SElem e);


int Level(char character);
bool IN(char ch);
Status Pass(char suffix[50], char ch);
bool Precede(SElemType*c, char ch);

void transform(char suffix[100], char exp[100], SqStack*s);

void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100]);

//存储字符型数据的栈；
Status Pop(SqStack*s, SElemType*e)
{
    if (s->top == s->base)
    {
        return ERROR;
    }
    else
    {
        *e = *--s->top;
        return OK;
    }
    
}
bool StackEmpty(SqStack*s)
{
    if (s->base == s->top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Status InitStack(SqStack*s)
{
    s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->base)
    {
        return OVERFLOW;
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status Push(SqStack*s, SElemType e)
{
    if (s->top - s->base > s->stacksize)
    {
        s->base = (SElemType*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElemType));
        if (!s->base)
        {
            return OVERFLOW;
        }
        s->top = s->base + s->stacksize;
        s->stacksize += 2 * STACK_INIT_SIZE;
    }
    *s->top = e;
    s->top++;
    return OK;
    
}

Status GetTop(SqStack *s, SElemType *e)
{
    if (s->top == s->base)
    {
        return ERROR;
    }
    *e = *(s->top - 1);
    return OK;
}

Status DistoryStack(SqStack *s)
{
    while (StackEmpty(s) == false)
    {
        s->top = NULL;
        s->top--;
    }
    s->base = NULL;
    free(s->base);
    free(s->top);
    return OK;
}


//存储整型数据的栈；
Status Pop1(SqStack1*s, SElem*e)
{
    if (s->top == s->base)
    {
        return ERROR;
    }
    else
    {
        *e = *--s->top;
        return OK;
    }
    
}
bool StackEmpty1(SqStack1*s)
{
    if (s->base == s->top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Status InitStack1(SqStack1*s)
{
    s->base = (SElem*)malloc(STACK_INIT_SIZE * sizeof(SElem));
    if (!s->base)
    {
        return OVERFLOW;
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status Push1(SqStack1*s, SElem e)
{
    if (s->top - s->base > s->stacksize)
    {
        s->base = (SElem*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElem));
        if (!s->base)
        {
            return OVERFLOW;
        }
        s->top = s->base + s->stacksize;
        s->stacksize += 2 * STACK_INIT_SIZE;
    }
    *s->top = e;
    s->top++;
    return OK;
    
}

Status DistoryStack1(SqStack1 *s)
{
    while (StackEmpty(s) == false)
    {
        s->top = NULL;
        s->top--;
    }
    s->base = NULL;
    free(s->base);
    free(s->top);
    return OK;
}



//判断运算符的优先级；
int Level(char character)
{
    int num;
    switch (character)
    {
        case'(':
            num = 9;
            break;
        case')':
            num = 1;
            break;
        case'*':
            num = 3;
            break;
        case'/':
            num = 4;
            break;
        case'+':
            num = 5;
            break;
        case'-':
            num = 6;
            break;
        case'#':
            num = 8;
            break;
        default:
            num = 0;
            break;
    }
    return num;
}

bool Precede(SElemType*c, char ch)
{
    
    if (Level(*c) != 0 && Level(ch) != 0)
    {
        if (Level(*c) - Level(ch)>1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}


//判断数据是否为0-9的操作数；
bool IN(char ch)
{
    if (ch >= '0'&&ch <= '9')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//向后缀式数组中填充数据；
Status Pass(char suffix[50], char ch)
{
    static int i = 0;
    if (i <= 50)
    {
        suffix[i] = ch;
        suffix[i + 1] = '\0';
        i++;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

//建立后缀式；
void transform(char suffix[100], char exp[100], SqStack*s)
{
    Push(s, '#');
    char*p = exp;
    char ch;
    ch = *p;
    int i = 0;
    SElemType c;
    while (StackEmpty(s) == false)
    {
        if (IN(ch) == false)//判断是否为操作数；
        {
            Pass(suffix, ch);
        }
        else
        {
            switch (ch)
            {
                case'(':
                    Push(s, ch);
                    break;
                case ')':
                    Pop(s, &c);
                    while (c != '(')
                    {
                        Pass(suffix, c);
                        Pop(s, &c);
                        while (suffix[i] != '\0')
                        {
                            printf("%c", suffix[i]);
                            i++;
                        }
                        printf("\n");
                        i = 0;
                    }
                    break;
                default:
                    GetTop(s, &c);
                    while (Precede(&c, ch) == true && ch != '\0')
                    {
                        Pass(suffix, c);
                        Pop(s, &c);
                        GetTop(s, &c);
                        while (suffix[i] != 0)
                        {
                            printf("%c", suffix[i]);
                            i++;
                        }
                        printf("\n");
                        i = 0;
                    }
                    if (ch != '\0')
                    {
                        Push(s, ch);
                        while (suffix[i] != 0)
                        {
                            printf("%c", suffix[i]);
                            i++;
                        }
                        i = 0;
                        printf("\n");
                    }
                    break;
            }
            
        }
        if (ch != '\0')
        {
            p++;
            ch = *p;
        }
        else
        {
            while (*s->top != '#')
            {
                Pop(s, &ch);
                if (ch != '#')
                {
                    Pass(suffix, ch);
                    while (suffix[i] != 0)
                    {
                        printf("%c", suffix[i]);
                        i++;
                    }
                    i = 0;
                    printf("\n");
                }
            }
        }
    }
}


//利用后缀式数据及数据栈和符号栈进行0-9数据的简单+-*/运算；
void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100])
{
    //char a[5] = {'*','/','+','-','#' };
    double x = 0;
    double y = 0;
    char z;
    int i = 0;
    int j = 0;
    int q = 0;
    char*p = suffix;
    char ch;
    Push(s2, '#');
    while (StackEmpty(s2) == false)
    {
        ch = *p;
        if (IN(ch) == false)//判断是否为操作数；
        {
            Push1(s3, ch - '0');
            i++;
        }
        else
        {
            Push(s2, ch);
            j++;
        }
        if (i >= 2 && j>0)
        {
            Pop1(s3, &x);
            Pop1(s3, &y);
            Pop(s2, &z);
            q = Level(z);
            switch (q)
            {
                case 5:
                    x = y + x;
                    Push1(s3, x);
                    break;
                case 6:
                    x = y - x;
                    Push1(s3, x);
                    break;
                case 3:
                    x = (y) * (x);
                    Push1(s3, x);
                    break;
                case 4:
                    x = y / x;
                    Push1(s3, x);
                    break;
                default:
                    break;
            }
            i--;
            j--;
        }
        p++;
        if (*p == '\0')
        {
            break;
        }
    }
}
int main()
{
    int i = 0, j = 0;
    SqStack s1;
    SqStack s2;
    SqStack1 s3;
    
    InitStack(&s1);
    InitStack(&s2);
    InitStack1(&s3);
    
    char suffix[50];
    char exp[50];
    printf("请输入0-9以内数的简单运算式\n");
    gets(exp);
    while (exp[i] != '\0')
    {
        if (exp[i] == '/'&&exp[i + 1] == '0')
        {
            printf("ERROR\n");
            printf("请重新输入\n");
            gets(exp);
            
        }
        i++;
    }
    printf("\n");
    /*for (i = 0; i < 50; i++)
     {
     exp[i] = '#';
     }*/
    printf("后缀式形成过程:\n");
    transform(suffix, exp, &s1);
    EvaluateExpression(&s2, &s3, suffix);
    printf("结果:");
    printf("%2lf", *s3.base);
    
    return 0;
}
