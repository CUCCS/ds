#include <stdio.h>
#include <string>
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

Status Pop(SqStack &S , SElemType &e){
    if(S.top  == S.base ) return ERROR;
	e = *--S.top ;
	return e;
	return OK;
}

Status ClearStack(SqStack &S){
	if(S.base ==S.top ) return ERROR;
	while(S.base !=S.top ){ *S.top=*--S.top ; }
	return *S.top ;
	return OK;
}

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

Status DestroyStack(SqStack &S){
	S.top =NULL;
	S.stacksize   =0;
	free(S.base );
	return OK;
}

Status StackEmpty(SqStack &S){
if(S.base ==S.top ) return TRUE;
else return FALSE;
}
void Lineedit(){
	int i=0;
	char ch[200]="@11#2\n2@#3";
	SqStack S;
	SElemType e=ch[i];
	InitStack(S); //�����ջ    �������������������������������������������������
		while(ch[i]!='\0'){
			e=ch[i];
		    switch(ch[i]){
				case '#': 
					Pop(S,e);               break;//����ջ�ǿ�ʱ��ջ���������������������������������������
				case '@': {
					if(StackEmpty(S)) break;
					while(e!='\n'){Pop(S,e);};  
					if(StackEmpty(S)||e=='\n') { Push(S,e); break; }     break;
						  }//����Ϊ��ջ�������������������������������������������
				default: 
					Push(S,ch[i]);             break;//��Ч�ַ���ջ�������������������������������������������
			}
			i++;
		//����ջ�׵�ջ����ջ���ַ����������ù��̵�������
		//ClearStack(S);//����SΪ��ջ
	}
		char pa[100];
		int j=0;
		while(!StackEmpty(S)){
		    pa[j]= Pop(S,e);
			j++;
		    //printf("%c",e);
		}
		do{
		j--;
		printf("%c",pa[j]);
		}while(j>=0);
		DestroyStack(S);
}
int main(){
	Lineedit();
	//printf("123321");
	return OK;
}
//whli##ilr#e(s#*s)\noutchar@\nputchar(*s=#++)\0
//@11#2\n2@#3
//abcd\nputchar@whli##ilr#e(s#*s)\noutchar@\nputchar(*s=#++)\0

