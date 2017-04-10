#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define  SElemType char 
typedef enum{
	true,
	false
}bool;

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

Status InitStack(Sqstack *s);
void Push(Sqstack* ,SElemType );
Status Pop(Sqstack* , SElemType* );
bool StackEmpty(Sqstack* );
void ClearStack(Sqstack *s);
void DestroyStack(Sqstack *s);
void LineEdit();

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
	*e = *(s->top);
	s->top--;//WWW2--此处需要free吗?
	return OK;
}

void ClearStack(Sqstack *s){
	s->top --;
	for( ;s->top >= s->base ;s->top--)
	{
		*(s->top) = '\0';
	}
	s->base = s->top ;
}

void DestroyStack(Sqstack *s){
	
	for(;s->top >= s->base ;s->top--)
	{
		free(s->top);
	}
}

void PrintStack(Sqstack s){
	for(;s.base <= s.top ;s.base ++ ){
		printf("%c",*s.base);
	}
	printf("\n");
}

void LineEdit(){
	Sqstack _s;
	char ch,t;
	InitStack(&_s);
	ch = getchar();
	while(ch != EOF){
		while(ch != EOF && ch != '\n'){
			switch(ch){
			case '#':Pop(&_s,&t);
				break;
			case '@':ClearStack( &_s);
				break;
			default:Push(&_s, ch);
			}//endswitch
			ch = getchar();
		}
		PrintStack(_s);
		ClearStack(&_s);
		//if(ch != '\n'){
		//	ch = getchar();
		//}//
		if(ch != EOF){
			ch = getchar();
		}//如何才能使ch == EOF?
	}
	DestroyStack(&_s);
}

int main(){
		LineEdit();
		return 0;

}