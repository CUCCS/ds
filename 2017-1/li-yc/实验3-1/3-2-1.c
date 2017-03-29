#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "3-2-1.h"

Status InitStack(SqStack *s){
	printf("��ʼ��һ��ջ\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("��ʼ��һ��ջ���\n");
}

Status Push(SqStack *s,SElemType e){
	if(s->top - s->base > s->stacksize){
		return OVERFLOW;
	}
	printf("����Ԫ�� %d ��Ϊջ��Ԫ��\n",e);
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
	printf("ת���������:\n");
	while(!StackEmpty(s)){
		Pop(s, &e);
		printf("%d", e);
	}
	printf("\n");
	printf("ת������\n");
}