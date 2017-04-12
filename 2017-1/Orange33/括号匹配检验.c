#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100  //存储空间初始分配
#define STACKINCREMENT 10  //存储空间分配增量
#define OVERFLOW -2
  

typedef struct
{
	char *base;    //在栈构造之前和销毁之后base的值为NULL
	char *top;    //栈顶指针
	char StackSize;        //当前已分配的存储空间，以元素为单位
}SqStack;


//构造一个空栈
int InitStack (SqStack *S)
{
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));    //分配基本空间
	if(!S->base)            //判断是否分配成功
		return OVERFLOW;
	S->top = S->base;        //指向栈顶
	S->StackSize = STACKINCREMENT;    //初始链表最大长度
	return 0;
}


//若S为空栈返回OK 否则返回ERROR
int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else
		return 0;
}


//若栈不空则用e返回栈顶数据并返回OK否则返回ERROR
int GetTop(SqStack *S, char *e)
{
    if(S->top == S->base)
		return 1;
	*e = *(S->top - 1);
	return 0;
}

//插入新的栈顶数据
int Push(SqStack *S, int e)
{
	if(S->top - S->base >=S->StackSize)    //空间不足
	{
		S->base = (char *)realloc(S->base, (S->StackSize + STACKINCREMENT) * sizeof(char));
		if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->StackSize;
		S->StackSize += STACKINCREMENT;
	}
	S->top++;
	*S->top = e;
	return 0;
}

//若栈不空 则删除栈顶数据并用e返回且返回OK 否则返回ERROR
int Pop(SqStack *S,char *e)
{
	if(StackEmpty(*S))    //空栈
		return 1;
	*e = *--S->top;
	return 0;
}


void Matching(char e[])
{
	unsigned int i = 0;
	int state = 1;
	char z;
    SqStack S;
	
	while((int)(i <= strlen(e)) && state && e[i] != '\0')    //结束条件 超出数组长度或state为0或字符串结束
    {
        switch(e[i])
        {
        case '(':
        case '{':
            Push(&S,e[i]);    //遇到({则进栈
            i++;
            break;
        case ')':
            GetTop(&S,&z);
            if(!StackEmpty(S) && z == '(')    //遇到)则判断栈顶是不是(，是的话出栈，不是则不匹配
            {
                Pop(&S,&z);
                i++;
            }
            else
                state = 0;
            break;
        case '}':
            GetTop(&S,&z);
            if(!StackEmpty(S) && z == '{')//遇到}则判断栈顶是不是{，是则出栈，不是则不匹配
            {
                Pop(&S,&z);
                i++;
            }
            else
                state = 0;
            break;
        }
    }
    if(StackEmpty(S) && state)    //空栈且state不为0则全部匹配
        printf("括号全部匹配\n");
    else
        printf("括号不匹配\n");
}

int main()
{   
	char test[100];
	SqStack S;
	InitStack(&S);
	printf("请输入括号:");
    scanf_s("%s",test);
    Matching(test);

	return 0;
}