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
char GetTop(SqStack &stack, char e);

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

char GetTop(SqStack &stack, char e) {
    if (StackEmpty(stack)) {
        return ERROR;
    }
    stack.top--;
    e = *stack.top;
    return e;
}

void ClearStack(SqStack &stack) {
    stack.top = stack.base;

}

void Matching(char e[])//括号匹配
{
    SqStack stack;

    int i = 0;
    int status;
    status = 1;// 判断括号匹配是否结束
    char z;
    int length = strlen(e);
    InitStack(stack);
    while ((i <= length) && (status == 1) && (e[i] != '\0')) {
        switch (e[i]) {
            case '{':
                Push(stack, e[i]);
                status = 0;
                i++;
                break;
            case '(':
                Push(stack, e[i]);
                status = 0;
                i++;
                break;
            case '[':
                Push(stack, e[i]);
                status = 0;
                i++;
                break;
            case ')':
                GetTop(stack, z);
                /*printf("top-%x\n",stack.top);
                printf("base-%x\n",stack.base);
                printf("top-%c\n",*stack.top);
                printf("base-%c\n",*stack.base);*/


                if (stack.top != stack.base) {
                    if (z == '(') {

                        Pop(stack, z);
                        status = 1;
                        i++;


                    }
                }
                else
                    status = 0;
                break;
            case '}':
                GetTop(stack, z);
                /*printf("top-%x\n",stack.top);
               printf("base-%x\n",stack.base);
               printf("top-%c\n",*stack.top);
               printf("base-%c\n",*stack.base);*/


                if (stack.top != stack.base) {
                    if (z == '{') {
                        Pop(stack, z);
                        status = 1;
                        i++;

                    }
                }

                else
                    status = 0;
                break;
            case ']':

                GetTop(stack, z);
                /* printf("top-%x\n",stack.top);
                 printf("base-%x\n",stack.base);
                 printf("top-%c\n",*stack.top);
                 printf("base-%c\n",*stack.base);*/

                if (stack.base != stack.top) {
                    if (z == '[') {

                        Pop(stack, z);
                        status = 1;
                        i++;

                    }
                }

                    else
                        status = 0;
                    break;
                    default:
                        break;

                }
        }
        //printf("%d \n", status);
        if (status == 1 && StackEmpty(stack)) {
            printf("括号全都匹配");
        }
        else
            printf("括号不完全匹配");
        DestroyStack(stack);
    }

    int main() {
        char *e;
        e = (char *) malloc(sizeof(char) * STACK_INIT_SIZE);
        int i = 0;
        int length;
        gets(e);
        /*while(e[i]!='\0')
        {
            printf("%c ",e[i]);
            i++;
        }*/
        Matching(e);
        return 0;
    }