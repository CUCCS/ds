/*******************************************************************************
  文件名: 
  项目:   
  模块:   
  作者:   huangwei
  版本:   0.1
  创建于:  
  描述:

  修改历史:
  日期:     修改人:    修改描述:

 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "myds.h"

Status ModConv(SqStack S, int input, int d)
{
    int integer;
    int remainder;
    SElemType e;

    if(d > 10) {
        fprintf(stderr, "it does not make sense with division greater than 10\n");
        return ERROR;
    }

    while(input) {
        Push(&S, input % d);
        input = input / d;
    }

    while(!IsEmptyStack(S)) {
        Pop(&S, &e);
        printf("%d", e);
    }
    printf("\n");
    return OK;
}


int main(int argc, char* argv[])
{
    SqStack S;
    int maxsize = STACK_INIT_SIZE;
    int input;
    int d;

    scanf("%d", &input);
    scanf("%d", &d);

    InitStack(&S, maxsize);
    ModConv(S, input, d);
    DestroyStack(&S);

    return 0;
}

