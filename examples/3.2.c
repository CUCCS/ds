#include <stdio.h>
#include <stdlib.h>

#include "3.2.h"


Status InitStack(SqStack *S, int size) {
    S->base = (SElemType *)malloc(sizeof(SElemType) * size);
    if(!S->base) {
        return OVERFLOW;
    }

    S->top = S->base;
    S->stacksize = size;

    return OK;
}

void DestroyStack(SqStack *S) {
    if(S->base) {
        free(S->base);
    }
}

bool IsStackEmpty(SqStack *S) {
    if(S) {
        return S->base == S->top;
    }

    return false;
}

Status Push(SqStack *S, SElemType e) {
    if(S->top - S->base >= S->stacksize) {
        // TODO re-allocate space for new stack
        return OVERFLOW;
    }

    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e) {
    if(IsStackEmpty(S)) {
        return ERROR;
    }

    *e = *--S->top;

    return OK;
}

SElemType GetTop(SqStack S) {
    if(IsStackEmpty(&S)) {
        return ' ';
    }

    return *(S.top - 1);
}




