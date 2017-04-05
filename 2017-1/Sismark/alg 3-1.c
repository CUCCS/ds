#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define SIZE 100
#define CREAT 10

typedef  int SElemType ;
typedef  int Status ;
/*1.声明顺序栈*/
typedef struct {
  SElemType *base;/*栈底*/
  SElemType *top;/*栈顶*/
  int stacksize;/*栈的大小*/
}SqStack;
/*2.构造一个空栈*/
Status InitStack(SqStack *ps){
	  (*ps).base = (SElemType * )malloc(SIZE * sizeof(SElemType));/*分配存储*/
	  if(!(*ps).base) exit (-1);
	  (*ps).top = (*ps).base ;/*栈顶指向栈底*/
	  (*ps).stacksize = SIZE;
	  return OK;
}

Status push(SqStack *pS,SElemType e){
	  if((*pS).top -( *pS).base >= (*pS).stacksize ){
	  (*pS).base =(SElemType * )realloc((*pS).base,((*pS).stacksize + CREAT)*sizeof(SElemType));
	  if(!(*pS).base ) exit (-1);
	  (*pS).top = (*pS).base + (*pS).stacksize ;
	  (*pS).stacksize +=CREAT;
	  }
 *(*pS).top ++=e;
 printf("%d\n", e);/*逆序输出八进制数*/
 return OK;
}

Status Pop(SqStack *pS,SElemType *pe){
	if((*pS).top == (*pS).base) return ERROR;
	*pe =*--(*pS).top ;
	return OK;
	return *pe;
}

Status StackEmpty(SqStack *pS){
   if((*pS).base == (*pS).top ) return TRUE;
   else return FALSE;
}

void conversion(){
	SqStack S;
	InitStack(&S);
	int N,e;
	srand(time(0));
	N = rand() % 10000;
	printf("%d",N);
	//scanf("%d",&N);
	while(N){
		  push(&S,N%8);
		  N=N/8;
	}
	printf("转换成八进制数:");
	while(!StackEmpty(&S)){
          Pop(&S,&e);
		  printf("%d",e);
	}
}	

int main() {
	conversion();
	printf("\n");
	return OK;
}