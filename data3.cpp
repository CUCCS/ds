#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef char SElemType;
typedef struct Sq_Stack {
    SElemType *base;
    SElemType *top;
    int stacksize;

} SqStack;
typedef enum {
    OK,
    ERROR,
    OVERFLOW,

} Status;


Status InitStack(SqStack &stack);//构造一个空栈
void DestroyStack(SqStack &stack);//销毁已经存在的栈
Status Push(SqStack &stack, SElemType e);//把一个新的元素添加到栈中
SElemType Pop(SqStack &stack, SElemType &e);//删除栈顶的元素,并用e返回其值
bool StackEmpty(SqStack &stack);//判断一个栈是否为空
Status GetTop(SqStack &stack);//回到栈顶
void LineEdit(SqStack *stack);//利用字幅栈S,从终端接受一行,并传送至调用过程的数据区
void ClearStack(SqStack &stack);//重置S为空栈

Status InitStack(SqStack &stack)//构造一个空栈

{
    //stack=(SqStack*)malloc(STACK_INIT_SIZE * sizeof(int));
    stack.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(char));
    if (!stack.base)
        // exit(OVERFLOW);
    {
        return OVERFLOW;
        //exit(1);
    }// 存储分配失败
    stack.stacksize = STACK_INIT_SIZE;
    stack.top = stack.base;
    return OK;
}

void DestroyStack(SqStack &stack)//销毁已经存在的栈3
{
    free(stack.base);
    stack.top = stack.base;
}

Status Push(SqStack &stack, SElemType e)//把一个新的元素添加到栈中
{
    if (stack.top - stack.base >= stack.stacksize) {   //stack->top
        stack.base = (SElemType *) realloc(stack.base, (stack.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!stack.base) {
            return OVERFLOW;
        }
        stack.top = stack.base + stack.stacksize;
        stack.stacksize = stack.stacksize + STACKINCREMENT;
        return OK;

    }
    *stack.top++ = e;
    return OK;
}

SElemType Pop(SqStack &stack, SElemType &e)//删除栈顶的元素,并用e返回其值
{
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack.top--;
    e = *stack.top;

    return e;
}

bool StackEmpty(SqStack &stack)// 判断一个栈是否为空栈
{

    if (stack.base == stack.top)
        return true;
    else
        return false;

}

Status GetTop(SqStack &stack)//回到栈顶
{
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack.top--;
    return OK;
}

void ClearStack(SqStack &stack)//重置S为空栈
{
    stack.top = stack.base;

}

void LineEdit()//利用字幅栈S,从终端接受一行,并传送至调用过程的数据区

{
    SqStack stack, Dstack;
    SElemType e, ch;
    InitStack(Dstack);
    InitStack(stack);//构造空栈S
    ch = getchar();//从终端接受第一个字符
    while (ch != EOF)//EOF为全文结束符
    {
        while (ch != EOF && ch != '\n') {
            switch (ch) {
                case '#':
                    Pop(stack, e);//仅当栈非空时退栈
                    break;
                case '@':
                    ClearStack(stack);//重置S为空栈
                    break;
                default:
                    Push(stack, ch);//有效字符进栈,未考虑栈满情况
                    break;

            }
            ch = getchar();//从终端接收下一个字符
        }
        while (!StackEmpty(stack)) {
            e = Pop(stack, e);
            Push(Dstack, e);
        }
        while (!StackEmpty(Dstack)) {
            e = Pop(Dstack, e);
            printf("%c", e);
        }
        ClearStack(stack);//重置S为空栈
        if (ch != EOF)
            ch = getchar();
    }
    DestroyStack(stack);

}

int main() {
    LineEdit();
    return 0;
}