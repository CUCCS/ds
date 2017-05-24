#ifndef _STACK_H_
#define _STACK_H_

#include "myds.h"

//----- 栈的顺序存储表示 -----
#define  STACK_INIT_SIZE  100 
typedef int SElemType;
typedef struct {
    SElemType  *base;    
    SElemType  *top;  
    int  stacksize;    
} SqStack;

typedef enum {
    false,
    true 
} bool;

Status InitStack(SqStack *S, int maxsize);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
bool IsEmptyStack(SqStack S);
void DestroyStack(SqStack *S);

#endif
