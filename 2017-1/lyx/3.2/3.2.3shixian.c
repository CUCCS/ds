#include"3.2.3.h"
Status LineEdit(SqStack *s,char *a)
{ //文本编辑器函数
	char c,ch,l;//定义字符串c，ch
	ch=getchar();//输入字符串ch
	while (ch != EOF)//如果ch不为空
	{
		while(ch != EOF&&ch != '\n')//如果ch不为空且不为结束
		{
			switch(ch)//switch选择语句
			{
			case '#'://若ch为#
				{
					Pop(s,&c);//删除栈顶元素，c返回值
					SElemType*l = s->base;//更新栈底元素
					while (l != s->top)//l不为栈顶元素时
					{
						printf("%c",*l);//输出l
						l++;//l自加
					}
					printf("\n");//换行
					break;//跳出switch语句
				}
			case '@'://若ch为@
				{
					ClearStack(s);//清空栈
					SElemType*l = s->base;//更新栈底元素
					while (l != s->top)//l不为栈顶元素时
					{
						printf("%c",*l);//输出l
						l++;//l自加
					}
					printf("\n");//换行
					break;//跳出switch语句
				}
			default://其他情况
				{
					Push(s,ch);//插入s为新的栈顶元素
					SElemType*l = s->base;//更新栈底元素
					while (l != s->top)//l不为栈顶元素时
					{
						printf("%c",*l);//输出l
						l++;//l自加
					}
					printf("\n");//换行
				}//end default
			}//end switch
	
		ch = getchar();//输入ch
	}//end while
	int i=0;//定义整数i为0
	while (s->top != s->base)//当栈非空时
	{
		a[i] = *(s->base);//a[i]为栈底元素
		s->base++;//栈底元素指向下一个
		i++;//i自加
	}
	a[i] = '\0';//当栈底元素为结束时
	printf("result:\n");//输出结果
	puts(a);//输出a[i]
	ClearStack(s);//清空栈
	if(ch != EOF)//当ch不为结束时
	{
		ch = getchar();	//输入ch
	}
	}//end while
	DistoryStack(s);//销毁栈
		return OK;//返回OK 成功
}// LineEdit

bool StackEmpty(SqStack *s)
{//若栈s为空栈，则返回TRUE，否则返回FALSE
	if(s->base == s->top){//若栈顶指针等于栈底指针
		return true;//则栈s为空栈
	}
	else{//若栈顶指针不等于栈底指针
		return false;//则栈s不是空栈
	}
}//StackEmpty

Status ClearStack(SqStack *s)
{//把S置为空栈
	s->top = s->base;//栈底指针等于栈顶指针
	return OK;//返回OK
}//ClearStack

Status DistoryStack(SqStack *s)
{//销毁栈s，s不再存在
	while (!StackEmpty)//当栈内还有元素时
	{
		s->top = NULL;//栈顶指针为空
		s->top--;//栈顶指针自减
	}
	s->base = NULL;//栈底指针
	free(s->base);//释放栈底指针
	free(s->top);//释放栈顶指针
	return OK;//返回OK
}//DistoryStack

Status InitStack(SqStack *s)
{//构造一个空栈
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//分配存储空间
	if(!s->base){//若溢出
		return OVERFLOW;
	}
	s->top = s->base;//使栈顶指针等于栈底指针
	s->stacksize = STACK_INIT_SIZE;//中间量等于申请的栈的大小
	return OK;
}//InitStack

Status Push(SqStack *s,SElemType e)
{//插入元素e为新的栈顶元素
	if(s->top - s->base > s->stacksize){//栈满，追加存储空间
		s->base = (SElemType*)realloc(s->base,(s->stacksize + 2*STACK_INIT_SIZE)*sizeof(SElemType));//追加存储空间
		if(!s->base){//若溢出
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;//更新栈顶元素
		s->stacksize += 2 * STACK_INIT_SIZE;//追加存储空间
	}
	*s->top = e;//插入元素e为新的栈顶元素
	s->top++;//s更新，指向top元素
	return OK;
}//Push

Status Pop(SqStack *s,SElemType *e)
{//若栈不空，则删除s的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(s->top == s->base){//栈为空栈
		return ERROR;//返回ERROR
	}
	else{
		*e = * --s->top;//栈顶指针自减，指向上一个元素
	}
}//Pop



