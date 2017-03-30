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
/*1.����˳��ջ*/
typedef struct {
  SElemType *base;/*ջ��*/
  SElemType *top;/*ջ��*/
  int stacksize;/*ջ�Ĵ�С*/
}SqStack;
/*2.����һ����ջ*/
Status InitStack(SqStack &s){
	  s.base = (SElemType * )malloc(SIZE * sizeof(SElemType));/*����洢*/
	  if(!s.base) exit (-1);
	  s.top =s.base ;/*ջ��ָ��ջ��*/
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
 printf("%d\n",e);/*��������˽�����*/
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
	printf("ת���ɰ˽�����:");
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