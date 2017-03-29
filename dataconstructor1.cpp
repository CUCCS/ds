#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef int SElemType;
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


Status InitStack(SqStack *stack);//构造一个空栈
void DestroyStack(SqStack *stack);//销毁已经存在的栈
Status Push(SqStack *stack, SElemType e);//把一个新的元素添加到栈中
Status Pop(SqStack *stack, SElemType *e);//删除栈顶的元素,并用e返回其值
bool StackEmpty(SqStack *stack);//判断一个栈是否为空
Status GetTop(SqStack stack);//返回栈顶
void Conversion(SqStack *stack, SElemType input, SElemType mod);//将十进制数转化为八进制


Status InitStack(SqStack *stack)//构造一个空栈
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

void DestroyStack(SqStack *stack)//销毁已经存在的栈3
{
    if (stack) {
        stack = NULL;
    }
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

Status Pop(SqStack *stack, SElemType *e)//删除栈顶的元素,并用e返回其值
{
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack->top--;
    *e = *stack->top;

    return OK;
}

bool StackEmpty(SqStack *stack)// 判断一个栈是否为空栈
{
    if (stack) {
        if (stack->base == stack->top)
            return true;
        else
            return false;
    }
}

Status GetTop(SqStack *stack) {// 返回栈顶元素
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack->top--;
    return OK;
}

void Conversion(SqStack *stack, SElemType input, SElemType mod) {//将十进制数转化为八进制
    SElemType e;
    while (input) {
        Push(stack, input % mod);
        input = input / mod;
    }
    while (!StackEmpty(stack)) {
        Pop(stack, &e);
        printf("%d", e);
    }
    printf("\n");

}

int main() {
    int integer;
    //SqStack * Stack;
    SqStack *Stack;
    srand(time(NULL));
    int Mod = 8;
    integer = rand() / 3;
    printf("The integer is %d\n", integer);
    printf("After the transformation:");
    InitStack(Stack);
    Conversion(Stack, integer, Mod);
    return 0;
}