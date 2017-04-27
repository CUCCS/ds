#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100    //存储空间初始分配量
#define STACK_SIZE 100            //存储空间分配增量
#define STACKINCREMENT 10         //存储空间分配增量

struct  //设定运算符优先级
{
    char ch;   //运算符
    int pri;   //优先级
}
lpri[]= {{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
rpri[]= {{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};

typedef char SElemType ;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //枚举定义（返回状态）

typedef enum{
	False,
	True
}Bool;                            //定义布尔类型

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;  

Status InitStack(SqStack *S)       //构造顺序栈
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
		return  OVERFLOW; 
	}                         //存储分配失败
	S->top = S->base;         //初始化
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


Bool IsStackEmpty(SqStack *S)
{
	if(S->top == S->base)
	{
		return True;
	}
	else
	{
		return False;
	}
}

SElemType GetTop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

 //删除 S 的栈顶元素，并用 e 返回其值
Status Pop(SqStack *S,SElemType *e)          
{
	if(IsStackEmpty(S))
	{
		return OK;
	}
	*e = *--S->top;
	return ERROR;
}


int leftpri(char op)    
{
    int i;
    for (i=0; i<STACK_INIT_SIZE; i++)
        if (lpri[i].ch==op)
            return lpri[i].pri;
}//求左运算符op的优先级


int rightpri(char op)  
{
    int i;
    for (i=0; i<STACK_INIT_SIZE; i++)
        if (rpri[i].ch==op)
            return rpri[i].pri;
}//求右运算符op的优先级

  
Bool InOp(char ch)     //判断字符ch是否为运算符
{
	switch (ch)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':     
		return True;
	default:
		return False;
	}
}

int Precede(char op1,char op2) 
{
    if (leftpri(op1)==rightpri(op2))
        return 0;
    else if (leftpri(op1)<rightpri(op2))
        return -1;
    else
        return 1;
}

void trans(char *exp,char postexp[])     //中缀转后缀（有参考）
{
    struct
    {
        char data[STACK_SIZE]; //存放运算符
        int top;            //栈指针
    } op;               //定义运算符栈
    int i=0;                //i作为postexp的下标
    op.top=-1;
    op.top++;                  //将'='进栈
    op.data[op.top]='=';
    while (*exp!='\0')      //exp表达式未扫描完时循环
    {
        if (!InOp(*exp))        //为数字字符的情况
        {
            while (*exp>='0' && *exp<='9') //判定为数字
            {
                postexp[i++]=*exp;
                exp++;
            }
            postexp[i++]=' ';   //用#标识一个数值串结束
        }
        else    //为运算符的情况
            switch(Precede(op.data[op.top],*exp))
            {
            case -1:           //栈顶运算符的优先级低:进栈
                op.top++;
                op.data[op.top]=*exp;
                exp++;     //继续扫描其他字符
                break;
            case 0:        //只有括号满足这种情况
                op.top--;      //将(退栈
                exp++;     //继续扫描其他字符
                break;
            case 1:             //退栈并输出到postexp中
                postexp[i++]=op.data[op.top];
                op.top--;
                break;
            }
    } //while (*exp!='\0')
    while (op.data[op.top]!='=')
    //此时exp扫描完毕,退栈到'='为止
    {
        postexp[i++]=op.data[op.top];
        op.top--;
    }
    postexp[i]='\0';    //给postexp表达式添加结束标识
}

float compvalue(char exp[])          //计算后缀表达式的值(有参考）
{
    struct
    {
        float data[STACK_SIZE];     //存放数值
        int top;                   //栈指针
    } st;                         //定义数值栈
    float d;
    char ch;
    int t=0;                   //t作为exp的下标
    st.top=-1;
    ch=exp[t];
    t++;
    while (ch!='\0')    //exp字符串未扫描完时循环
    {
        switch (ch)
        {
        case'+':
            st.data[st.top-1]=st.data[st.top-1]+st.data[st.top];
            st.top--;
            break;
        case '-':
            st.data[st.top-1]=st.data[st.top-1]-st.data[st.top];
            st.top--;
            break;
        case '*':
            st.data[st.top-1]=st.data[st.top-1]*st.data[st.top];
            st.top--;
            break;
        case '/':
            if (st.data[st.top]!=0)
                st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
            else
            {
                printf("\n\t除零错误!\n");                  //异常退出
            }
            st.top--;
            break;
        default:
            d=0;                          //将数字字符转换成数值存放到d中
            while (ch>='0' && ch<='9')   //为数字字符
            {
                d=10*d+ch-'0';
                ch=exp[t];
                t++;
            }
            st.top++;
            st.data[st.top]=d;
        }
        ch=exp[t];
        t++;
    }
    return st.data[st.top];
}

int main()
{
	int i = 0;
    char exp[] = "(56-20)/(4+2)" ;
    char postexp[STACK_SIZE];
    trans(exp,postexp);
    printf("中缀表达式:%s\n",exp);
    printf("后缀表达式:%s\n",postexp);
    printf("表达式的值:%g\n",compvalue(postexp));
    return 0;
}