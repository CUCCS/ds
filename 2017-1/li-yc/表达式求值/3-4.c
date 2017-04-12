#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3-4.h"

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
	*e = *--s->top;
	return OK;
}
bool StackEmpty(SqStack *s){
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
	*e=*(s.top-1);
	printf("ջ���ַ�Ϊ %c\n",*e);
	return OK;
}
void Traverse(SqStack s){
	printf("��ʼ����:\n");
	while(!StackEmpty(&s)){
		printf("%c\n",*(s.top-1));
		--s.top;
	}
}
bool IN(char ch){
	if(ch<='100'&&ch>='0'){
		return false;
	}
	else{
		return true;
	}
}
char Precede(char exist,char read){
	switch(exist){
	case '+':
		if(read=='+'||read=='-'||read==')'||read=='#'){
			return '>';
		}
		else{
			return '<';
		}
		break;
	case '-':
		if(read=='+'||read=='-'||read==')'||read=='#'){
			return '>';
		}
		else{
			return '<';
		}
		break;
	case '*':
		if(read=='('){
			return '<';
		}
		else{
			return '>';
		}
		break;
	case '/':
		if(read=='('){
			return '<';
		}
		else{
			return '>';
		}
		break;
	case '(':
		if(read==')'){
			return '=';
		}
		else{
			return '<';
		}
		break;
	case ')':
		return '>';
		break;
	case '#':
		if(read=='#'){
			return '=';
		}
		else{
			return '<';
		}
		break;
	}
	return OK;
}
int EvaluateExpression(char *exp){
	SqStack OPTR;
	SqStack OPND;
	char e;
	char a,b,theta;
	char x;
	int len;
	int i=0;
	len=strlen(exp);
	exp[len]='#';

	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR,'#');
	GetTop(OPTR,&e);
	while(exp[i]!='#'||e!='#'){
		if(!IN(exp[i])){
			printf("���� %c ��������ջ��\n",exp[i]);
			Push(&OPND,exp[i]);
			i++;
		}
		else{
			switch(Precede(e,exp[i])){
			case '<':
				printf("���� %c �������ջ��\n",exp[i]);
				Push(&OPTR,exp[i]);
				i++;
				break;
			case '=':
				Pop(&OPTR,&x);
				printf("�� %c ����ջ����\n",x);
				i++;
				break;
			case '>':
				printf("\n���кϲ�ǰ���б���:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				Pop(&OPTR,&theta);
				if(*(OPTR.top-1)=='('){
					Pop(&OPTR,&x);
					exp[i]='#';
				}
				printf("�� %c ����ջ����\n",theta);
				Pop(&OPND,&b);
				printf("�� %c ����ջ����\n",b);
				Pop(&OPND,&a);
				printf("�� %c ����ջ����\n",a);
				Push(&OPND,Operate(a,theta,b));
				printf("\n���кϲ�����б���:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				if(OPTR.base==OPTR.top){
					exp[i]='#';
				}
				break;
			}
		}
		GetTop(OPTR,&e);
	}
	GetTop(OPND,&e);
	printf("������Ϊ%d\n",e-'0');
	return e-'0';
}
char Operate(char a,char thete,char b){
	switch(thete){
	case '+':
		return (a-'0')+(b-'0')+'0';
		break;
	case '-':
		return (a-'0')-(b-'0')+'0';
		break;
	case '*':
		return (a-'0')*(b-'0')+'0';
		break;
	case '/':
		return (a-'0')/(b-'0')+'0';
		break;
	}
}