#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INIT_SIZE 100   
#define STACKINCREMENT 10 

typedef char SElemType; 

typedef enum{
	False,
	True
}Bool;                            //���岼������

typedef enum{ 
	ERROR, 
	OK, 
	OVERFLOW 
}Status;  //ö�ٶ��壨����״̬��

typedef struct { 
	SElemType *base; 
	SElemType *top; 
	int stacksize; 
}SqStack;      //˳��ջ�Ķ���

Status InitStack(SqStack *S)      //����˳��ջ
{ 
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType)); 
	if(!S->base) 
	{ 
		return OVERFLOW; 
	} //�洢����ʧ��
	S->top = S->base; 
	S->stacksize = STACK_INIT_SIZE; 
    return OK; 
}

Bool IsStackEmpty(SqStack *S)//�ж�ջ���Ƿ�Ϊ�գ�
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status Push(SqStack *S,SElemType e) //����Ԫ��Ϊe���µ�ջ��Ԫ��
{ 
	if((S->top - S->base) >= S->stacksize) 
	{ 
		S->base = (SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType)); 
		if(!S->base) 
		{ 
			return OVERFLOW; 
		} 
		S->top = S->base + S->stacksize; 
		S->stacksize += STACKINCREMENT; 
	} 
	*S->top++ = e; 
	return OK; 
}

Status Pop(SqStack *S,SElemType *e)//��ջ��Ϊ�գ���ɾ��s��ջ��Ԫ�أ���e����ֵ��������OK�����򷵻�ERROR��
{ 
	if(IsStackEmpty(S))  
		return ERROR; 
	*e = *--S->top; 
	return OK; 
}

Status ClearStack(SqStack *S) //���ջ
{ 
	S->top = S->base; 
	return OK; 
} 

Status DestroyStack(SqStack *S) //����ջs��s������
{ 
	S->top = S->base; 
	free(S->base); 
	S->top = NULL; 
	S->base = NULL; 
	S->stacksize = 0;
	return OK; 
}

void LineEdit(SqStack *S) 
{ 
	//�����ַ�ջs�����ն˽���һ�в����������ù��̵������� 
	char ch,c;
	SElemType *b; 
	InitStack(S); 
	ch = getchar(); //���յ�һ����ĸ
	while( ch != EOF) 
	{ 
		while(ch != EOF&&ch!='\n') 
		{ 
			switch(ch) 
			{ 
			case '#':Pop(S,&c); 
				break; //����ջ�ǿ�ʱ��ջ
			case '@':ClearStack(S); 
				break; //����SΪ��ջ
			default :  
				Push(S, ch); //��Ч�ַ���ջ��δ����ջ������
			} 
			ch = getchar(); //���ն˽�����һ���ַ�
		} 
		b = S->base; 
		while(b != S->top) 
		{ 
			printf("%c",*b); 
			b++; 
		} 
		ClearStack(S); 
		if( ch!=EOF) 
			ch = getchar(); 
	} 
	DestroyStack(S); 
} 
int main() 
{ 
	SqStack S; 
	printf("���:\n"); 
	LineEdit(&S); 
	DestroyStack(&S); 
	return 0; 
} 