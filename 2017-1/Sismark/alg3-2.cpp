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

Status InitStack(SqStack &S){
	S.base = (SElemType * )malloc(SIZE*sizeof(SElemType));
	if(!S.base ) exit (OVERFLOW); //�洢����ʧ��
	S.top =S.base ;
	S.stacksize =SIZE;
	return OK;
}
//���ջ
Status Pop(SqStack &S , SElemType &e){
    if(S.top  == S.base ) return ERROR;
	e = *--S.top ;
	return e;
	return OK;
}
//��ջ
Status Push(SqStack &S , SElemType e){
	if(S.top -S.base >=S.stacksize ){
			S.base =(SElemType *)realloc(S.base , (S.stacksize + CREAT)*sizeof(SElemType));
			if(!S.base ) exit (OVERFLOW);
			S.top = S.base + S.stacksize ;
			S.stacksize += CREAT;
	}
	*S.top ++ = e;
	return OK;
}
//��ջ
Status StackEmpty(SqStack S){
   if(S.base == S.top ) return TRUE;
   else return FALSE;
}
//�ж�
void ParMat(){
	SElemType e;
    SqStack S;
	InitStack(S);//��ջ
	int i=0;
    char pa[100]="[([][])]";
	printf("%s\n",pa);
	//scanf("%s",pa);
	Push(S,pa[i]);
	e=pa[i];
	while(pa[i+1]!='\0'){
		i++;
		if(pa[i]==']'){
			Pop(S,e);
			if(e !='[') { printf("ƥ��ʧ��\n"); break; }
		}
		if(pa[i]=='}'){
			Pop(S,e);
			if(e!='{') { printf("ƥ��ʧ��\n"); break; }
		}
		if(pa[i]==')'){
			Pop(S,e);
			if(e!='(') { printf("ƥ��ʧ��\n"); break; }
		}
		if(pa[i]=='['||pa[i]=='{'||pa[i]=='(') { Push(S,pa[i]);  }
	}
	if(StackEmpty(S) ) printf("ƥ��ɹ�\n");
	else printf("ƥ��ʧ��\n");
}
int main(){
    ParMat();
	return 0;
}