#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;
Status InitStack(SqStack *);
Status StackEmpty(SqStack *);
Status Push(SqStack *,SElemType );
Status Pop(SqStack *,SElemType &);
Status Convert(int ,SqStack *);

int main()
{
	SElemType e;
	int N;
	SqStack S;
	InitStack(&S);
	scanf("%d",&N);
	Convert(N,&S);
	system("pause");
	return 0;
}
Status InitStack(SqStack *s)
{
	s->base=(SElemType *)malloc(STACK_INIT_SIZE  * sizeof(SElemType));
	if(!s->base)
		return OVERFLOW;
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE ;
	return OK;
}
Status StackEmpty(SqStack *s)
{
	if(s->base==s->top)
		return OK;
	else
		return ERROR;
}
Status Push(SqStack *s,SElemType e)
{
	if(s->top - s->base>=s->stacksize)//Õ»Âú£¬×·¼Ó´æ´¢¿Õ¼ä
	{
		//s->base=(SElemType *)realloc(s->base,(s->stacksize+STACKINCREMENT) * sizeof(SElemType));
	    //if(!s->base)
			return OVERFLOW;//´æ´¢·ÖÅäÊ§°Ü
	    //s->top=s->base+s->stacksize;
		//s->stacksize+=STACKINCREMENT;
	}
	else{
	*s->top++ = e;
	return OK;
	}

}
Status Pop(SqStack *s,SElemType &e)
{
	if(s->top==s->base)//ÅÐ¶ÏÊÇ·ñÎª¿ÕÕ»
		return ERROR;
	e = * --s->top;
	return OK;
}
Status Convert(int input,SqStack *S)
{
	SElemType e;
	e = *S->top;
	while(input)
	{
		Push(S,input%8);
		input=input/8;
	}
	while(!StackEmpty(S))
	{
		Pop(S,e);
		printf("%d",e);
	}
	return OK;
}



//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//#define MAXNUM 100
//typedef char SElemType ;
//typedef enum{
//    ERROR,
//	OK,
//	OVERFLOW
//}Status;
//typedef struct {
//    SElemType *base;
//	SElemType *top;
//	int stacksize;
//}SqStack;
//
////create a new stack
//Status InitStack(SqStack *S)
//{
//	//need free
//    S->base = (SElemType *)malloc(STACK_INIT_SIZE * 
//		sizeof(SElemType));
//	if(!S->base) {
//		return OVERFLOW;//fail to allocate memory
//	}
//	S->top = S->base;
//	S->stacksize = STACK_INIT_SIZE;
//
//	return OK;
//}//end of InitStack
//
//Status Push(SqStack *S, SElemType e)//
//{
//	//if(S->top - S->base >= S->stacksize) {
//	//	//re-alloc
//	//		return OVERFLOW;
//	//}//»Æ´ó´ó
//	if(S->top - S->base >= S->stacksize)
//	{
//      S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
//	  if(!S->base)
//	  {
//		  return OVERFLOW;
//	  }
//      S->top = S->base + S->stacksize;
//      S->stacksize += STACKINCREMENT;
//	}//¿Î±¾
//	*S->top++ = e;
//	return OK;
//}//end of Push
//
//Status Pop(SqStack *S, SElemType *e) 
//{
//	if(S->top == S->base) 
//	{
//		return ERROR;
//	}
//	*e = * --S->top;//´ý¼ì²â
//	return OK;
//}//end of Pop
//
////ÅÐ¶Ï¿ÕÕ»
//Status StackEmpty(SqStack *S)
//{
//	if(S->base == S->top)
//	{
//		return OK;
//	}
//	else{
//		return ERROR;
//	}
//}//end of StackEmpty
//
////»ñÈ¡Õ»¶¥ÔªËØµÄº¯Êý
//Status GetTop(SqStack *S, SElemType *e)
//{
//	if(S->top == S->base){
//	    return ERROR;
//	}
//	*e = *(S->top-1);
//	return OK;
//}//end of GetTop
//
////Çå¿ÕÕ»
//Status ClearStack(SqStack *S)
//{
//	if(S->top==S->base)
//		return ERROR;
//    S->top=S->base;
//	return OK;
//}//end of ClearStack
//
////Ïú»ÙÕ»
//Status DestroyStack(SqStack *S)
//{
//	free(S->base);
//	S->base = NULL;
//	S->top = NULL;
//	S->stacksize = 0;
//	return OK;
//}//end of destroy Stack
//
//Status LineEdit(SqStack *S)
//{
//	//SqStack *S;
//	SElemType e;//Õ»¶¥ÔªËØ
//	SElemType *b;//Ö¸ÏòÕ»µ×£¬ÓÃÓÚÊä³ö
//	char ch;
//	//InitStack(S);
//	ch = getchar();
//	while(ch != EOF)
//	{
//		while(ch!=EOF&&ch!='\n')
//		{
//			switch(ch){
//			case '#':
//				Pop(S,&e);
//				break;
//			case '@':
//				ClearStack(S);
//				break;
//			default:
//				Push(S,ch);
//				break;
//			}
//			ch = getchar();
//		}
//		b = S->base;
//	    while(b!=S->top)
//	    {
//		    printf("%c",*b);
//		    ++b;
//	    }
//		ClearStack(S);
//        if( ch!=EOF )
//		    ch = getchar();
//	}
//	
//	
//	//DestroyStack(S);
//	return OK;
//}//end of LineEdit
//
//int main()
//{
//	SqStack S;
//	InitStack(&S);
//	printf("Create a statement as you like!\n");
//	LineEdit(&S);
//	return 0;
//}
////whil##ilr#e(s#*s)
////outcha@putchar(*s=#++)