#include <stdio.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100//存储空间初始分配
#define STACKINCREMENT 10//存储空间分配增量
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef char SElemType;

typedef struct {
	SElemType *base; //在栈构造之前和销毁之后base的值为NULL
	SElemType *top;//栈顶指针
	int stacksize; //当前已分配的存储空间，以元素为单位
}SqStack;

//构造一个空栈
int InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));//分配基本空间
	if(!S->base)
	{
		return OVERFLOW; 
	}//判断是否分配成功
	S->top = S->base;              //指向栈顶
	S->stacksize = STACK_INIT_SIZE;         //初始链表最大长度
	return 0;
}

//插入新的栈顶数据
int Push(SqStack *S,SElemType e)
{
	if((S->top-S->base)>=S->stacksize) 
	{
		S->base = (SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return 0;
}

//若栈不空 则删除栈顶数据并用e返回且返回OK 否则返回ERROR
int Pop(SqStack *S,SElemType *e) 
{
	if(S->top  == S->base) 
	{
		return ERROR;
	}
	*e = *--S->top;
	return 0;
}

//清空栈中的元素
int ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

//销毁栈
int DestoryStack(SqStack *S)
{
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}

void LineEdit() 
{
	//利用字符栈S，从终端接收一行并传送至调用过程的数据区。
	char ch,*temp;
	SqStack S;
	InitStack(&S);       //构造空栈S
	printf("请输入一行(#:退格；@:清行)(输入Ctrl+Z的时候结束循环):\n");
	ch = getchar();     //从终端接收第一个字符
	while (ch != EOF)  //EOF为全文结束符)
	{ 
		while (ch != EOF && ch != '\n') 
		{
			switch (ch) 
			{
			case '#': 
				Pop(&S, &ch);    
				break;            // 仅当栈非空时退栈
			case '@':
				ClearStack(&S);
				break;           // 重置S为空栈
			default :
				Push(&S, ch);   
				break;            // 有效字符进栈,未考虑栈满情形
			}
			ch = getchar();  // 从终端接收下一个字符
		}    

		// 将从栈底到栈顶的栈内字符传送至调用过程的数据区；
		temp=S.base;  
		while(temp!=S.top) 
		{
			printf("%c",*temp);    //这里做控制台的输出；依情况讨论              
			++temp;
		}
		ClearStack(&S);      // 重置S为空栈
		printf("\n");
		if (ch != EOF)
		{
			printf("请输入一行(#:退格；@:清行)(输入Ctrl+Z的时候结束循环):\n");
			ch = getchar();
		}
	}
	DestoryStack(&S);
}

int main()
{
	LineEdit();
	return 0;
}
