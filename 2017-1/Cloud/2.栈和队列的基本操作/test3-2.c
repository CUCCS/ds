#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define  SElemType char 
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
void Push(Sqstack* ,SElemType* );
Status Pop(Sqstack* , SElemType* );
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

void Push(Sqstack *s, SElemType *e)
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
	*(s->top )= *e;
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
	*e = *(s->top - 1);
	s->top--;//WWW2--此处需要free吗?
	return OK;
}


Status ParenthesisJudge(char f, char l){
	switch(f){
	case '(' :if(l == ')'){
		return OK;
			  }
			  else {
				  return ERROR;
			  }
			  break;
	case '[' :if(l == ']'){
		return OK;
			  }
			  else {
				  return ERROR;
			  }
			  break;
	case '{' :if(l == '}'){
		return OK;
			  }
			  else {
				  return ERROR;
			  }
			  break;

	default:
		break;
	}


}

Status ParenthesisTest(Sqstack *_s){
	char now,_t;
	char * t = &_t;//仅仅是为了迎合下文Pop的调用
	printf("请输入括号(输入‘！’以结束输入)....\n");
	scanf("%c",&now);
	if(now != '!'){
		Push(_s,&now);
	}//栈底元素
	scanf("%c",&now);
	while(now != '!'){
		if( ParenthesisJudge( *(_s->top - 1),now) == OK ){
			Pop(_s,t);
		}
		else{
			Push(_s, &now);
		}
		scanf("%c",&now);
	}
	if(StackEmpty(_s)){
		return OK;
	}else{
		return ERROR;
	}
}
int main(){
	Sqstack S;
	InitStack(&S);
	if (!ParenthesisTest(&S)){
		printf("括号输入无误！");
	}else{
		printf("括号输入不匹配。");
	}
	return 0;
}
