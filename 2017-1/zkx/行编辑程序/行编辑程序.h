#include <stdio.h>  
#include<stdlib.h>

#define STACKINCREMENT 10  
#define STACK_INIT_SIZE 100  

#define DEBUG 1

typedef enum Status {ERROR,OVERFLOW,OK}; 

typedef char SElemType;  

typedef struct  
{  
    SElemType *base;  
    SElemType *top;  
    int stacksize;  
}SqStack;  

Status  InitStack (SqStack* pS);

Status Push (SqStack *S , SElemType e);

Status GetTop (SqStack *S , SElemType e);

int StackEmpty (SqStack *S);

Status Pop (SqStack S ,SElemType *e);

char GetTop(SqStack *S);

Status ClearStack(SqStack *S);

void LineEdit(SqStack *S);