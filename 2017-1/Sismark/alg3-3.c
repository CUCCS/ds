#include <stdio.h>
#include <string.h>
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
   SElemType *base;//栈底指针
   SElemType *top;//栈顶指针
   int stacksize;
} SqStack;

Status InitStack(SqStack *pS){
	(*pS).base = (SElemType * )malloc(SIZE*sizeof(SElemType));
	if(!(*pS).base ) exit (OVERFLOW); //存储分配失败
	(*pS).top = (*pS).base ;
	(*pS).stacksize =SIZE;
	return OK;
}

Status Pop(SqStack *pS , SElemType *pe){
    if((*pS).top  == (*pS).base ) return ERROR;
	(*pe) = *--(*pS).top ;
	return *pe;
	return OK;
}

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

Status DestroyStack(SqStack *pS){
	(*pS).top =NULL;
	(*pS).stacksize   =0;
	free((*pS).base );
	return OK;
}

Status StackEmpty(SqStack *pS){
if((*pS).base == (*pS).top ) return TRUE;
else return FALSE;
}
void Lineedit(){
	int i=0;
	char ch[200]="whli##ilr#e(s#*s)\noutchar@\nputchar(*s=#++)\0";
	SqStack S;
	SElemType e=ch[i];
	InitStack(&S); //构造空栈    、、、、、、、、、、、、、、、、、、、、、、、完成
		while(ch[i]!='\0'){
			e=ch[i];
		    switch(ch[i]){
				case '#': 
					Pop(&S, &e);               break;//仅当栈非空时退栈
				case '@': {
					if(StackEmpty(&S)) break;
					while(e!='\n'){Pop(&S, &e);};
					if(StackEmpty(&S)||e=='\n') { Push(&S,e); break; }     break;
						  }//重置为空栈
				default: 
					Push(&S,ch[i]);             break;//有效字符进栈
			};
			i++;
		//将从栈底到栈顶的栈内字符传送至调用过程的数据区
		//ClearStack(S);//重置S为空栈
		};
		char pa[100];
		int j=0;
		while(!StackEmpty(&S)){
		    pa[j]= Pop(&S, &e);
			j++;
		};
		do{
		j--;
		printf("%c",pa[j]);
		}while(j>=0);
		DestroyStack(&S);
}
int main(){
	Lineedit();
	return OK;
}


