#include <stdio.h>
#include <stdlib.h>

typedef int Status; 
typedef char SElemType;

#define SIZE 100
#define CREAT 10

#define OVERFLOW -1
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0

typedef struct {
   SElemType *base;//ջ��ָ��
   SElemType *top;//ջ��ָ��
   int stacksize;
} SqStack;

Status InitStack(SqStack * pS){
	(*pS).base = (SElemType * )malloc(SIZE*sizeof(SElemType));
	if(!(*pS).base ) exit (OVERFLOW); //�洢����ʧ��
	(*pS).top = (*pS).base ;
	(*pS).stacksize =SIZE;
	return OK;
}
//���ջ
Status Pop(SqStack *pS , SElemType *pe){
    if((*pS).top  == (*pS).base )  return ERROR;
	(*pe) = *--(*pS).top ;
	return *pe;
	return OK;
}
//��ջ
Status Push(SqStack *pS , SElemType e){
	if((*pS).top - (*pS).base >= (*pS).stacksize ){
		(*pS).base =(SElemType *)realloc((*pS).base , ((*pS).stacksize + CREAT)*sizeof(SElemType));
			if(!(*pS).base ) exit (OVERFLOW);
			(*pS).top = (*pS).base + (*pS).stacksize ;
			(*pS).stacksize += CREAT;
	}
	*(*pS).top ++ = e;
	return OK;
}
//��ջ
Status StackEmpty(SqStack *pS){
   if((*pS).base == (*pS).top ) return TRUE;
   else return FALSE;
}
//�ж�
void ParMat(){
	SElemType e;
    SqStack S;
	InitStack(&S);//��ջ
	int i=0,flag=0;
    char pa[100]="{([][])]";
	printf("%s\n",pa);
	//scanf("%s",pa);
	Push(&S,pa[i]);
	e=pa[i];
	while(pa[i+1]!='\0'){
		i++;
		if(pa[i]==']'){
			Pop(&S,&e);
			if(e !='[') { flag++; break; }
		}
		if(pa[i]=='}'){
			Pop(&S,&e);
			if(e!='{') { flag++; break; }
		}
		if(pa[i]==')'){
			Pop(&S,&e);
			if(e!='(') { flag++; break; }
		}
		if(pa[i]=='['||pa[i]=='{'||pa[i]=='(') { Push(&S,pa[i]);  }
	}
	if(StackEmpty(&S)&& flag==0) printf("ƥ��ɹ�\n");
	else printf("ƥ��ʧ��\n");
}
int main(){
    ParMat();
	return 0;
}