#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define  SElemType int 

typedef struct _Sqstack
{
	SElemType *base;
	SElemType *top;
	int Stacksize;
}Sqstack;

typedef enum 
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum{
	true,
	false
}bool;

Status InitStack(Sqstack *s);
void Push(Sqstack* ,SElemType );
Status Pop(Sqstack* , SElemType* );
void conversion (Sqstack , int );
bool StackEmpty(Sqstack* );


Status InitStack(Sqstack *s)
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	/*if(StackEmpty)*/	
	if(!s->base){
		return OVERFLOW;
	}
	s->top = s->base;
	s->Stacksize = STACK_INIT_SIZE;
	return OK;
}

void Push(Sqstack *s, SElemType e)
{
	//e新插入的栈顶元素
	if(s->top - s->base >= s->Stacksize){
		s->base = (SElemType *)realloc(s->base ,(STACK_INIT_SIZE + STACKINCREMENT)*sizeof(SElemType));
		while(!s->base)
		{
			s->base = (SElemType *)realloc(s->base ,(STACK_INIT_SIZE + STACKINCREMENT)*sizeof(SElemType));
		}//存储分配失败，进行重新分配
		s->top = s->base + s->Stacksize;
		s->Stacksize += STACKINCREMENT;
	}		
	*(s->top )= e;
	s->top ++;
}

bool StackEmpty(Sqstack *s)
{//如果栈为空，返回true 不空返回false
	/*if(s->top == s->base)
	return true;
	else 
	return false;*///WWW1
	if(s){
		return s->base == s->top;
	}
	return true;//HDD
}

Status Pop(Sqstack *s, SElemType* e)
{
	if(StackEmpty(s))
		return OVERFLOW;
	*e = *(--s->top);
	//s->top--;//WWW2--此处需要free吗?
	return OK;
}

void conversion (Sqstack _s, int _d)
{
	int e;
	int number = rand()%1024;
	//int number = 1348;
	printf("生成的随机数：%d (10) = ",number);
	while (number) {
		Push(&_s, number % _d);
		number = number/_d;
	}
	while (!StackEmpty(&_s)) {
		Pop(&_s, &e);
		printf ( "%d",e);
	}
	printf("(8)\n");
}
int main()
{
	Sqstack S;
	int d = 8; //进制数
	int input = rand()%1024;
	srand(time(NULL));
	InitStack(&S); 
	conversion (S,d) ;
	return 0;

}
