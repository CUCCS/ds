#include "1.h"
int main()
{
	char x[SUANSHUSHI_NUM];
	int t;
	scanf("%s", x);
	stack mystack;
	initstack(&mystack);
	rank_list(&mystack, x);
	printf("\n 排序完成后 \n");
	Traverse_Stack(mystack);//第一次进行排序之后
	printf("\n*********************************************************\n");
	t = cal_list(mystack);
	printf("公式的计算结果是 %d", t);
	free(mystack.base);
	return 0;
}
//初始化栈  
status initstack(stack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType));
	if (NULL == s->top)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	s->top = s->base;
	int k = DATE_NUM;
	s->top->date = (char*)malloc(sizeof(char) * k);
	s->top->date = "#\0";//怎么不能指向空
	s->base = s->top;//防止出现野指针
	return 1;
}
//检验栈是否为空  是返回0 否返回1
status isStackempty(stack s)
{
	if (s.base == s.top)
	{
		return 0;
	}
	return 1;
}
//进行压栈
status push(stack *s, char *e)
{
	ElemType *p = (ElemType*)malloc(sizeof(ElemType));
	if (NULL == p)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	int k = DATE_NUM;
	p->date = (char*)malloc(sizeof(char) *k);
	strcpy(p->date, e);
	p->pNext = s->top;  //让p的指针域指向上一个节点  
	s->top = p;        //让pTop指针指向栈顶元素  
	return 1;
}
//用于判断是数字还是界限符还是运算符  是数字就返回0
status judgenumber(char x)
{
	int i;
	switch (x)
	{
	case '+':
	case'-':
	case'*':
	case'/':
		i = 1;//运算符返回 1
		break;
	case '(':
		i = 3;
		break;
	case')':
		i = 4; //界限符返回-1
		break;
	case'\0':
		i = -10;//过界返回-10
		break;
	case '#':
		i = 6;//如果是到了栈底
		break;
	default:
		i = 0; //数字返回0
		break;
	}
	return i;
}
//用于字符串的拆分,为压栈做准备
char** conversion(char x[])
{
	int i = 0, j = 0, k = 0;
	int q = WEIDU_NUM;
	int p = DATE_NUM;
	char **y = (char**)malloc(sizeof(char*)*q);
	for (i = 0; i < q; i++)
	{
		y[i] = (char*)malloc(sizeof(char)*p);
	}
	//动态分配二维数组进行存储
	i = 0;
	do
	{//其实此段可以进行化简 只要进行字符串的化简
		j = 0;
		if (judgenumber(x[i]) == 0)
		{
			while (judgenumber(x[i]) == 0 && x[i] != '\0')//当输入的字符是数字 进行存储
			{
				y[k][j] = x[i];
				i++;
				j++;
			}
			y[k][j] = '\0';
		}
		else
		{
			y[k][j] = x[i];
			y[k][1] = '\0';
			i++;
		}
		k++;
	} while (x[i] != '\0');
	y[k][0] = '\0';//结尾元素怎么设计
	i = 0;
	printf("将输入的字符串进行拆分 \n");
	while (y[i][0] != '\0')
	{
		printf("%s  ", y[i]);
		i++;
	}
	return y;
}
//用于后缀式的排序 排数字和运算符
status rank_list(stack *s, char x[])
{
	stack print_out_stack;
	initstack(&print_out_stack);//用于存储打印输出的栈
	int i = 0;//j的作用是 只用于入栈时候的循环  作用范围很小   i的作用是记录头尾的数字
	char**p = conversion(x);//拆分成独立的元素
	char *temp;//临时存储值
	int q = WEIDU_NUM;//用于p的释放
	while (p[i][0] != '\0')
	{
		if (judgenumber(p[i][0]) == 0)//如果
		{
			push(&print_out_stack, p[i]);//直接打印
			printf("\n遇见数字直接打印  %s \n ", p[i]);
		}
		else if (judgenumber(p[i][0]) == 1)//如果是运算符
		{
			if (0==isStackempty(*s) || judge_pre(p[i][0]) >= judge_pre(s->top->date[0])|| s->top->date[0]=='(')//如果栈为空或元素的优先级大于等于栈顶元素 进行入栈
			{
				printf("\n优先级较高 或栈顶为括号  入栈  %s\n", p[i]);
				push(s, p[i]);
			}
			else//将所有需要弹出的数字进行打印  并将新的运算符进行压栈
			{
				//弹出栈顶元素  直到遇见左括号或者遇见优先级更低的元素 或栈空 当栈顶元素优先级大或相等  出栈
				while (0 != isStackempty(*s) && judgenumber(s->top->date[0]) != 3 && judge_pre(s->top->date[0]) >= judge_pre(p[i][0]))//左括号和右括号的数字不同
				{
					
					Pop_Stack(s, &temp);
					push(&print_out_stack, temp);
					printf("\n%s优先级低于%s 将 %s 出栈打印\n", p[i],temp,temp);
				}
				push(s, p[i]);//并入栈
			}
		}
		else  //如果遇见括号  左括号直接进栈   右括号进行打印输出直到遇见左括号
		{
			if (judgenumber(p[i][0]) == 3)
			{
				printf("\n将左括号入栈\n");
				push(s, p[i]);
			}
			else//如果是右括号  进行弹出并进行一系列出栈操作
			{
				printf("\n遇见右括号  将左括号以前的操作符进行打印\n");
				while (judgenumber(s->top->date[0]) != 3)
				{
					Pop_Stack(s, &temp);
					push(&print_out_stack, temp);
					printf("\n打印  %s\n", temp);
				}
				Pop_Stack(s, &temp);//弹出左括号
				printf("\n弹出左括号\n");
			}
		}
		i++;
	}
	//对拆分构造的元素占用内存进行释放
	while (isStackempty(*s))
	{
		Pop_Stack(s, &temp);
		push(&print_out_stack, temp);
		printf("\n打印 %s\n", temp);
	}
	//释放截取字符时的内存
	for (i = 0; i < q; i++)//释放临时的二级指针
	{
		free(p[i]);
	}
	free(p);
	while (isStackempty(print_out_stack))
	{
		Pop_Stack(&print_out_stack, &temp);
		push(s, temp);
	}
	free(print_out_stack.base);
	return 1;
}
//判断运算符的优先级
status judge_pre(char x)
{
	int i;
	switch (x)
	{
	case '+':
	case'-':
		i = 0;
		break;
	case'*':
	case'/':
		i = 1;//运算符返回 1
		break;
	default:
		i = 2;
		break;
	}
	return i;
}
//弹出栈顶
status Pop_Stack(stack *S, char ** val)
{
	ElemType* p = S->top;
	(*val) = (char*)malloc(sizeof(char) * 5);
	(*val) = S->top->date;
	S->top = S->top->pNext;  //使pTop指针指向栈顶元素；  
	free(p);  //释放p指针所指向的那个节点的内存；  
	p = NULL;   //要养成好的习惯；  
	return 1;
}
void Traverse_Stack(stack s)
{
	ElemType  *p = s.top;
	printf("\n栈中的元素是：\n");
	while (p != s.base)
	{
		printf("%s ", p->date);
		p = p->pNext;
	}
	printf("\n");
}
//用于计算后缀式
status cal_list(stack s)//传入的数据
{
	stack mystack;//用于计算的栈
	initstack(&mystack);
	char * temp;//用于临时存储的栈顶元素
	while (s.top != s.base)
	{
		if(judgenumber(s.top->date[0]) == 0)//如果是数字直接进行压栈
		{
			Pop_Stack(&s, &temp);
			push(&mystack, temp);
       }
		else
		{//如果遇到运算符进行计算
			char *v;//用于
			int a = (int)atof(mystack.top->date);//转化栈顶元素
			int b = (int)atof(mystack.top->pNext->date);//转化第二个元素
			int c = cal(a, b, s.top->date[0]);
			printf("\n取出栈中的 %d %d 进行%c的计算", a, b,s.top->date[0]);
			printf("  %d %c %d = %d\n", b, s.top->date[0], a, c);
			Pop_Stack(&mystack, &v);//计算完成后对数据进行相应的出栈
			Pop_Stack(&mystack, &v);
			Pop_Stack(&s, &v);
			itoa(c, v, 10);
			push(&mystack, v);//将计算结果进行入栈
			free(v);//对临时分配的量进行释放
		}
	}
	free(temp);
	int  c = (int)atof(mystack.top->date);
	free(mystack.top);
	return c;
}
int cal(int a, int b, char x)//进行计算
{
	switch (x)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return b- a;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return b / a;
		break;
	}
}
//销毁栈
status destory(stack *s)
{
	ElemType *p;
	while (s->top != s->base)
	{
		p = s->top;
		s->top = s->top->pNext;
		free(p);
	}
	free(s->base);
	return 1;
}
