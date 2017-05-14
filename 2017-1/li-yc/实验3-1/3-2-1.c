#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "3-2-1.h"

Status InitStack(SqStack *s){
	printf("初始化一个栈\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("初始化一个栈完毕\n");
}

Status Push(SqStack *s,SElemType e){
	if(s->top - s->base > s->stacksize){
		return OVERFLOW;
	}
	printf("插入元素 %d 作为栈顶元素\n",e);
	*s->top++ = e;
	return OK;
}

Status Pop(SqStack *s,SElemType *e){
	if(StackEmpty(s)){
		return ERROR;
	}
	*e = *--s->top;
	return OK;
}

bool StackEmpty(SqStack *s){
	if(s) {
		return s->base == s->top;
	}
	return true;
}

Status conversion(SqStack *s,int input,int d ){
	SElemType e;

	if(d > 10){
		return ERROR;
	}
	while(input){
		Push(s, input % d);
		input = input / d;
	}
	printf("转化后的数字:\n");
	while(!StackEmpty(s)){
		Pop(s, &e);
		printf("%d", e);
	}
	printf("\n");
	printf("转化结束\n");
}