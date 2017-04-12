#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef int SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
enum bool{ false, true };
typedef struct _SqStack{
	SElemType   *base;
	//��֮ǰ������֮��base��ֵΪNULL
	SElemType *top; //ջ��ָ��
	int stracksize;
}SqStack;
Status InitStack(SqStack *S){
	//����һ����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e){
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S->top - S->base >= S->stracksize){//ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//�洢����ʧ��
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}
int main() 
{//�Ӻ�������
SqStack S;
SElemType e;
  InitStack( &S);//��ʼ����ջ 
  StackEmpty( &S);//�п�  
  Push( &S, e);//��ջ 
  Pop(  &S, &e);//��ջ 
 //��������ʼ 
 char ch[100],*p;int ei; 
 p=ch; 
 printf("��һ��������()[]{}�����ű��ʽ:\n"); 
gets(ch); 
 while(*p) 
 { 
 switch (*p) 
 { 
 case '{': 
 case '[': 
 case '(': 
 Push(&S,*p++);
 break;//ֻҪ�������ž���ջ 
 case '}': 
 case ']': 
 case ')':
 Pop(&S,&ei); 
 if ((ei=='{' && *p=='}')||(ei=='[' && *p==']') || (ei=='(' && *p==')')) 
 p++; 
 else 
 {printf("���Ų�ƥ��!");exit(OVERFLOW); break;} 
 
 default :p++;//�����ַ��ͺ��� 
 } 
 } 
 if (StackEmpty(&S)) 
 printf("����ƥ��ɹ�"); 
 else 
 printf("���Ų�ƥ��"); 
 printf("\n"); 
} 
