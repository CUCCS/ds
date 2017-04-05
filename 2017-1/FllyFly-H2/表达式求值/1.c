#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef char SElemType;

typedef struct Sq_Stack {
    SElemType *base;
    SElemType *top;
    int stacksize;

} SqStack;//存储运算数和运算符的结构体
typedef enum {
    OK,
    ERROR,
    OVERFLOW,

} Status;
typedef enum {
    true,
	false

}bool;
unsigned char opchartab[7][7]=
        {
                '>', '>', '<', '<', '<', '>', '>',
                '>', '>', '<', '<', '<', '>', '>',
                '>', '>', '>', '>', '<', '>', '>',
                '>', '>', '>', '>', '<', '>', '>',
                '<', '<', '<', '<', '<', '=', ' ',
                '>', '>', '>', '>', ' ', '>', '>',
                '<', '<', '<', '<', '<', ' ', '='

        };
char OPERATORS[]={'+','-','*','/','(',')','$'};//运算符数组

Status InitStack(SqStack *stack);//构造一个运算数空栈
void DestroyStack(SqStack *stack);//销毁已经存在的运算数栈
Status Push(SqStack *stack, SElemType e);//把一个新的元素添加到运算数栈中
Status Pop(SqStack *stack, SElemType *e);//删除运算数栈顶的元素,并用e返回其值
bool StackEmpty(SqStack *stack);//判断一个运算数栈是否为空
SElemType GetTop(SqStack s);

bool IsOperator(SElemType e);//判断读入字符是否为运算符
SElemType Precede(SElemType a,SElemType b);//比较运算符的优先级
SElemType Operate(SElemType a,SElemType Operator,SElemType b);//运算
int EvaluateExpression();

Status InitStack(SqStack *stack)//构造一个运算符空栈
{
    //stack=(SqStack*)malloc(STACK_INIT_SIZE * sizeof(int));
    stack->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!stack->base)
        // exit(OVERFLOW);
    {
        return OVERFLOW;
    }// 存储分配失败
    stack->stacksize = STACK_INIT_SIZE;
    stack->top = stack->base;
    return OK;
}
void DestroyStack(SqStack *stack)//销毁已经存在的栈
{

        /*stack = NULL;*/

}
Status Push(SqStack *stack, SElemType e)//把一个新的元素添加到栈中
{
    if (stack->top - stack->base > stack->stacksize) {   //stack->top
        stack->base = (SElemType *) realloc(stack->base, (stack->stacksize + STACKINCREMENT) * sizeof(SElemType *));
        if (!stack->base) {
            return OVERFLOW;
        }
        stack->top = stack->base + stack->stacksize;
        stack->stacksize = stack->stacksize + STACKINCREMENT;

    }
    *stack->top = e;
    stack->top++;
    return OK;
}
Status Pop(SqStack *stack, SElemType *e)//删除运算数栈顶的元素,并用e返回其值
{
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack->top--;
    *e = *stack->top;

    return OK;
}
bool StackEmpty(SqStack *stack)// 判断一个运算数栈是否为空栈
{

        if (stack->base == stack->top)
            return true;
        else
            return false;

}
SElemType GetTop(SqStack stack) {// 返回运算数栈顶元素
    if (!StackEmpty(&stack)) {
        stack.top--;
    }

    return *stack.top;
}
bool IsOperator(SElemType e)//判断读入字符是否为运算符
{
    if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e==')'||e=='#')
        return true;
    else
        return false;
}
SElemType Precede(SElemType a,SElemType b)//比较运算符的优先级
{
    SElemType ch;
    if(a=='+'||a=='-')
    {
        if(b=='+'||b=='-'||b==')'||b=='#')
            ch='>';
        else if(b=='*'||b=='/'||b=='(')
            ch='<';
    }
    else if(a=='*'||a=='/')
    {
        if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
            ch='>';
        else if(b=='(')
            ch='<';
    }
    else if(a=='(')
    {
        if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
            ch='<';
        else if(b==')')
            ch='=';
    }
    else if(a==')')
    {
        if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
            ch='>';
    }
    else if(a=='#')
    {
        if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
            ch='<';
        else if(b=='#')
            ch='=';
    }
    return ch;
}
SElemType Operate(SElemType a,SElemType Operator,SElemType b)//运算
{
    SElemType ch;
    a=a-'0';// 转化成int类
    b=b-'0';//转化成int类
    if(Operator=='+')
        ch=a+b+'0';//在计算的同时转化成char类
    else if(Operator=='-')
        ch=a-b+'0';
    else if(Operator=='*')
        ch=a*b+'0';
    else if(Operator=='/')
        ch=a/b+'0';
    return ch;
}
 int EvaluateExpression()
{
    SqStack Operator,Oprand;
    SElemType ch,a,b,theta,x;
    InitStack(&Operator);//初始化操作符栈
    InitStack(&Oprand);//初始化操作数栈
    Push(&Operator,'#');
    ch=getchar();
    while(ch!='#'||GetTop(Operator)!='#')
    {
        if(!IsOperator(ch))
        {
            Push(&Oprand,ch);
            ch=getchar();
        }
        else
        {
            switch(Precede(GetTop(Operator),ch))
            {
                case '<':
                    Push(&Operator,ch);
                    ch=getchar();
                    break;
                case '>':
                    Pop(&Operator,&theta);
                    Pop(&Oprand,&b);
                    Pop(&Oprand,&a);
                    Push(&Oprand,Operate(a,theta,b));
                    break;
                case '=':
                    Pop(&Operator,x);
                    ch=getchar();
                    break;
            }
        }
    }
    return GetTop(Oprand)-'0';
}
int main()
{
    printf("请输入算术表达式,并以#结束\n");
    printf("结果是: %d\n",EvaluateExpression());
    return 0;
}
