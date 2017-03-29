#include"3.2.2.h"
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

Status brackets(SqStack *s,char*test)
{//括号匹配函数
	int i,j=0;//定义整数i，j，使j的值等于0
	SElemType e,m,n;//定义字符串emn
    for(i=0;test[i] != '\0';i++){//当test中还有字符串时
		switch(test[i])//switch选择语句
		{
		case'{':
		case'[':
		case'(':
			{//若进入栈的字符为{[（
				Push(s,test[i]);//插入栈中为新的栈顶元素
				SElemType*l = s->base;//中间的指针指向栈底指针
				while(l != s->top)//当l不是栈顶指针时
				{
					printf("%c",*l);//输出l
				    l++;//l自加
				}
				printf("\n");//换行
				break;//跳出此次switch语句
			}
		case'}'://若进入栈的字符为}
			{
				GetTop(s,&e);//得到栈顶元素
				if(e == '{')//如果栈顶元素为{
				{
					if(StackEmpty == false)//栈中还有元素，即不是空栈
					{
						Pop(s,&m);//删除栈顶元素
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
					}
				}
				else//如果得到的栈顶元素不是{
				{
					Push(s,test[i]);//插入得到的元素为新的栈顶元素
					Pop(s,&m);//删除原来的栈顶元素名称
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
					}
				break;//跳出此次switch语句
				}
		case']'://若进入栈的字符为]
			{
				GetTop(s,&e);//得到栈顶元素
				if(e == '[')//如果栈顶元素为[
				{
					if(StackEmpty == false)//栈中还有元素，即不是空栈
					{
						Pop(s,&m);//删除栈顶元素
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
					}
				}
				else//如果得到的栈顶元素不是[
				{
					Push(s,test[i]);//插入得到的元素为新的栈顶元素
					Pop(s,&m);//删除原来的栈顶元素名称
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
					}
				break;//跳出此次switch语句
				}
		case')'://若进入栈的字符为)
			{
				GetTop(s,&e);//得到栈顶元素
				if(e == '(')//如果栈顶元素为(
				{
					if(StackEmpty == false)//栈中还有元素，即不是空栈
					{
						Pop(s,&m);//删除栈顶元素
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
					}
				}
				else//如果得到的栈顶元素不是(
				{
					Push(s,test[i]);//插入得到的元素为新的栈顶元素
					Pop(s,&m);//删除原来的栈顶元素名称
						SElemType*l = s->base;//更新栈底元素
						while(l != s->top)//当l不是栈顶指针时
						{
					       printf("%c",*l);//输出l
				           l++;//l自加
				         }
				        printf("\n");//换行
				}//end else
				break;//跳出此次switch语句
				}//end case
			}//end switch
			}//end for
     if(StackEmpty(s) == true){//如果栈为空
		 return OK;//返回OK，匹配成功
	 }
}//brackets

bool StackEmpty(SqStack *s)
{//若栈s为空栈，则返回TRUE，否则返回FALSE
	if(s->base == s->top){//若栈顶指针等于栈底指针
		return true;//则栈s为空栈
	}
	else{//若栈顶指针不等于栈底指针
		return false;//则栈s不是空栈
	}
}//StackEmpty

Status Pop(SqStack *s,SElemType *e)
{//若栈不空，则删除s的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(s->top == s->base){//栈为空栈
		return ERROR;//返回ERROR
	}
	else{
		*e = * --s->top;//栈顶指针自减，指向上一个元素
	}
}//Pop

Status GetTop(SqStack *s,SElemType *e)
{//若栈不空，则用e返回s的栈顶元素，并返回OK；否则返回ERROR
	if(s->top == s->base){//栈为空栈
        return ERROR;//返回ERROR
	}
	*e = *(s->top -1);//e指向栈顶元素
	return OK;//返回OK
}//GetTop