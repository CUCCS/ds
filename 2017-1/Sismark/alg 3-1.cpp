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
Status InitStack(SqStack &s){
	  s.base = (SElemType * )malloc(SIZE * sizeof(SElemType));/*分配存储*/
	  if(!s.base) exit (-1);
	  s.top =s.base ;/*栈顶指向栈底*/
	  s.stacksize = SIZE;
	  return OK;
}

Status push(SqStack &S,SElemType e){
	  if(S.top -S.base >=S.stacksize ){
	  S.base =(SElemType * )realloc(S.base,(S.stacksize + CREAT)*sizeof(SElemType));
	  if(!S.base ) exit (-1);
	  S.top = S.base + S.stacksize ;
	  S.stacksize +=CREAT;
	  }
 *S.top ++=e;
 printf("%d\n",e);/*逆序输出八进制数*/
 return OK;
}

Status Pop(SqStack &S,SElemType &e){
	if(S.top == S.base) return ERROR;
	e=*--S.top ;
	return OK;
	return e;
}

Status StackEmpty(SqStack S){
   if(S.base == S.top ) return TRUE;
   else return FALSE;
}

void conversion(){
	SqStack S;
	InitStack(S);
	int N=1348,e;
	scanf("%d",&N);
	while(N){
		  push(S,N%8);
		  N=N/8;
	}
	printf("转换成八进制数:");
	while(!StackEmpty(S)){
          Pop(S,e);
		  printf("%d",e);
	}
}	

int main(){
	conversion();
	printf("\n");
	return OK;
}