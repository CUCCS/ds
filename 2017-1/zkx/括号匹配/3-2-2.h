#include <stdio.h>  
#include<stdlib.h>

#define STACKINCREMENT 10  
#define STACK_INIT_SIZE 100  

#define DEBUG 1

typedef enum  {ERROR,OVERFLOW,OK} Status;

typedef char SElemType;  

typedef struct  
{  
    SElemType *base;  
    SElemType *top;  
    int stacksize;  
}SqStack;  

Status  InitStack (SqStack* pS);

Status Push (SqStack *S , SElemType e);

int StackEmpty (SqStack *S);

Status Pop (SqStack S , int *e);

void Match(SqStack *S , char *p);