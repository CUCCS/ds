#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "3-2-2.h"

Status InitStack(SqStack *s){
	printf("��ʼ��һ��ջ\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("��ʼ��һ��ջ���\n\n");
}

Status Push(SqStack *s,char e){
	printf("�����µ��ַ� %c ��ջ��\n",e);
	if(s->top - s->base > s->stacksize){
		return OVERFLOW;
	}
	*s->top++ = e;
	return OK;
}

Status Pop(SqStack *s,char *e){
	if(isStackEmpty(s)){
		return ERROR;
	}
	printf("�� %c ����ջ����\n",*e);
	*e = *--s->top;
	return OK;
}

bool isStackEmpty(SqStack *s){
	if(s->base==s->top){
		return true;
	}
	else{
		return false;
	}
}
Status GetTop(SqStack s,char *e){
	if(s.top==s.base){
		return ERROR;
	}
	printf("ջ���ַ�Ϊ %c\n",*e);
	*e=*(s.top-1);
	return OK;
}
Status matching(char *exp){
	SqStack s;
	InitStack(&s);
	int i=0;
	int state=1;
	int length=0;
	length=strlen(exp);
	while(i<length&&state){
		switch(exp[i]){
		case '(':
			Push(&s,exp[i]);
			i++;
			break;
		case ')':
			GetTop(s,&exp[i]);
			if(!isStackEmpty(&s)&&exp[i] =='('){
				Pop(&s,&exp[i]);
				i++;
			}
			else{
				state=0;
			}
			break;
		case '[':
			Push(&s,exp[i]);
			i++;
			break;
		case ']':
			GetTop(s,&exp[i]);
			if(!isStackEmpty(&s)&&exp[i] =='['){
				Pop(&s,&exp[i]);
				i++;
			}
			else{
				state=0;
			}
			break;
		case '{':
			Push(&s,exp[i]);
			i++;
			break;
		case '}':
			GetTop(s,&exp[i]);
			if(!isStackEmpty(&s)&&exp[i] =='{'){
				Pop(&s,&exp[i]);
				i++;
			}
			else{
				state=0;
			}
			break;
		}
	}
	if(isStackEmpty(&s)==true&&i==length-1){
		printf("�����������ƥ���\n");
	}
	else{
		printf("����������ǲ�ƥ���\n");
	}
	return OK;
}
void Traverse(char *exp){
	while(*exp!='\0'){
		printf("%c ",*exp);
		exp++;
	}
	printf("\n\n");
}