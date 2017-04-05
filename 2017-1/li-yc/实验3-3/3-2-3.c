#include <stdio.h>
#include <stdlib.h>

#include "3-2-3.h"

Status InitStack(SqStack *s){
	printf("��ʼ��ʼ��һ��ջ\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("��ʼ��һ��ջ����\n\n");
}

Status Push(SqStack *s,char e){
	printf("����Ԫ�� %cΪջ��Ԫ��\n",e);
	if(s->top - s->base > s->stacksize){
		return OVERFLOW;
	}
	*s->top++ = e;
	return OK;
}

Status Pop(SqStack *s,char *e){
	if(StackEmpty(s)){
		return ERROR;
	}
	printf("���ǰһ��Ԫ��\n");
	*e = *--s->top;
	return OK;
}

bool StackEmpty(SqStack *s){
	if(s) {
		return s->base == s->top;
	}
	return true;
}
Status ClearStack(SqStack *s){
	printf("�������ǰ�������Ԫ��\n");
	s->top=s->base;
	return OK;
}
Status LineEdit(SqStack *s){
	char str[100]={'\0'};
	char c;
	char ch;
	int i=0;
	printf("��ʼ�����ַ���:\n");
	ch=getchar();
	while(ch!= ';'){
		while(ch!=';'&&ch!='\n'){
			switch(ch){
			case '#':Pop(s,&c);
				         printf("\n");
				break;
			case '@':ClearStack(s);
				         printf("\n");
				break;
			default:
				Push(s,ch);
			}
			ch=getchar();
		}
		while(s->top!=s->base){
			str[i]=*(s->base);
			s->base++;
			i++;
		}
		printf("�����������ַ���:\n");
		puts(str);
		ClearStack(s);
		if(ch!=';'){
			ch=getchar();
		}
	}
	DestroyStack(s);
	return OK;
}
Status DestroyStack(SqStack *s){
	while(!StackEmpty(s)){
		free(s->top);
		s->top--;
	}
	s->base=NULL;
	return OK;
}