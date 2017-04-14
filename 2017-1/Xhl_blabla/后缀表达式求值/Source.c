#include "Source.h"
int main()
{
	char x[SUANSHUSHI_NUM];
	int t;
	scanf("%s", x);
	stack mystack;
	initstack(&mystack);
	rank_list(&mystack, x);
	printf("\n 初次排序完成后  （只进行括号里的字符排序  和括号外的数字和字符排序 ） ");
	Traverse_Stack(mystack);//第一次进行排序之后
	rank_list_more(&mystack);//后缀式排序完成
	Traverse_Stack(mystack);
	printf("\n第二步 对后缀式进行计算\n");
	t=cal_list(mystack);
	printf("公式的计算结果是 %d", t);
	destory(&mystack);
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
	s->base=s->top =NULL;//防止出现野指针
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
	case')':
		i = -1; //界限符返回-1
		break;
	case'\0':
		i = -10;//过界返回-10
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
			while (judgenumber(x[i]) ==0&& x[i] != '\0')//当输入的字符是数字 进行存储
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
//用于后缀式的初次排序 排数字和运算符
status rank_list(stack *s, char x[])
{
	int i = 0, j;//j的作用是 只用于入栈时候的循环  作用范围很小   i的作用是记录头尾的数字
	int begin = 0, end = 0;//压栈数组的始末
	int flag;//辅助判断
	char**p = conversion(x);//拆分成独立的元素
	int q = WEIDU_NUM;//用于p的释放
	p[0];
	char temp[DATE_NUM];//临时存储值
	int  a, b;
	while (p[i][0] != '\0')
	{
		if (judgenumber(p[i][0]) == -1)//如果是括号  进行内部排序  再入栈    一次就彻底排好  以后看作一个整体
		{//确定开始结尾  进行压栈
			push(s, p[i]);//将括号入栈
			i++;
			begin = i;
			while (judgenumber(p[i][0]) != -1)//当不是括号时循环
			{
				i++;
			}
			end = i;
			//冒泡法对数组进行排序
			for (a = begin; a < end-1 ; a++)
			{
				for (b = begin; b < end - 1 - a+begin; b++)
				{	
					int k = 0;
					if (judge_pre(p[b][0]) < judge_pre(p[b + 1][0]))//对优先级比较排序
					{
						strcpy(temp, p[b]);
						strcpy(p[b], p[b + 1]);
						strcpy(p[b + 1], temp);
					}	
				}
			}
			int de;
			printf("\n 将括号里的字符进行排序 \n");
			for ( de= begin; de< end;de++)
			{
				printf("%s  ", p[de]);
			}
			for (j = begin; j < end; j++)
			{
				push(s, p[j]);//对元素进行入栈
			}
			push(s, p[i]);//将括号入栈
			i++;
			begin = i;
		}
		else	//如果不是括号直接进行排序 压栈
		{//在这里面只进行数字与运算符的排序
			flag = 0;
			while (flag == 0 || judgenumber(p[i][0]) == 0)//是数字或者第一次进入
			{
				if (judgenumber(p[i][0]) != 0)//如果不是数字
				{
					flag = 1;
					if (judgenumber(p[i + 1][0]) == 0)//交换数值
					{
						strcpy(temp, p[i]);
						strcpy(p[i], p[i + 1]);
						strcpy(p[i + 1], temp);
						end = i + 1;
						i += 2;
					//可以进行压栈了
					for (j = begin; j <= end; j++)
					{
						push(s, p[j]);//对元素进行入栈
					}
					begin = i;
                     i--;
					}
					else
					{
						push(s, p[i]);	
						begin = i+1;//对begin进行赋
					}
					//压完栈就可以跳出来了
				}
				else//如果是数字直接入栈
				{
					push(s, p[i]);
					begin++;//压栈之后对值做出更新
				}
				i++;//进行下一轮
				//什么作用
				for (a = begin; a < end - 1; a++)
				{
					for (b = begin; b < end - 1 - a + begin; b++)
					{
						int k = 0;
						if (judge_pre(p[b][0]) < judge_pre(p[b + 1][0]))//对优先级比较排序
						{
							strcpy(temp, p[b]);
							strcpy(p[b], p[b + 1]);
							strcpy(p[b + 1], temp);
						}
					}
				}
			}
		}	
	}
	for (i = 0; i < q; i++)//释放临时的二级指针
	{
		free(p[i]);
	}
	free(p);
	return 1;
}
//判断优先级 二次判断后缀式的时候使用
status judge_pre2(char x)
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
	case '(':
	case')':
		i = 1;//运算符返回 1
		break;
	default:
		i = 1;//字母的优先级
		break;
	}
	return i;
}
//对字符的优先级进行  优先级越大数值越高 用于初次排序
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
			case '(':
			case')':
				i = 1;//运算符返回 1
				break;
			default:
				i = 2;//字母的优先级
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
//这一次只用排运算符
status rank_list_more(stack *s)
{
	//这一次只用排运算符
	int i = 0, j, k = 0;
	int q = WEIDU_NUM;
	int p = DATE_NUM;
	char **y = (char**)malloc(sizeof(char*)*q);//临时存储要排序的元素
	char**x = (char**)malloc(sizeof(char*)*q);//存储从括号里拿出来的元素
	for (i = 0; i < q; i++)
	{
		y[i] = (char*)malloc(sizeof(char)*p);
		x[i] = (char*)malloc(sizeof(char)*p);
	}
	//动态分配二维数组进行存储
	ElemType *temp;
	temp = s->top;
	i = 0;
	j = 0;
	while (temp != s->base)
	{
		if (judgenumber(temp->date[0]) != -1)//如果不是括号
		{
			strcpy(y[i], temp->date);
			i++;
			temp = temp->pNext;
		}
		else
		{
			strcpy(y[i], temp->date);//将括号存进去
			i++;
			temp = temp->pNext;//存括号里的其余的部分
			while (judgenumber(temp->date[0]) != -1)
			{
				strcpy(x[j], temp->date);
				j++;
				temp = temp->pNext;
			}
			strcpy(x[j], temp->date);
			temp = temp->pNext;
		}
	}
	int end = i;
	int x_num = j + 1;
	//对运算符进行排序
	char *tem = (char*)malloc(sizeof(char)*p);
	for (i = 0; i<end - 1; i++)
	{
		for (j = 0; j<end - 1 - i; j++)
		{
			if (judge_pre2(y[j][0]) > judge_pre2(y[j + 1][0]))//对优先级比较排序
			{
				strcpy(tem, y[j]);
				strcpy(y[j], y[j + 1]);
				strcpy(y[j + 1], tem);
			}
		}
	}//插入括号中取出的元素
	free(tem);//释放临时分配的内存
	printf("\n二次排序求后缀式时 未插入括号前\n");
	for (i = 0; i < end; i++)
	{
		printf("%s ", y[i]);
	}
	for (i = 0; i < end; i++)
	{
		if (judgenumber(y[i][0]) == -1)
		{
			for (j = 0; j < x_num; j++)
			{
				for (k = end - 1; k > i + j; k--)
				{
					strcpy(y[k + 1], y[k]);
				}
				strcpy(y[i + j + 1], x[j]);
				end++;
			}
			break;//插入括号后就跳出来
		}
	}
	//然后再入栈
	printf("\n二次排序求后缀式时 插入括号后\n");
	for (i = 0; i < end; i++)
	{
		printf("%s ", y[i]);
	}
	i = end - 1;
	temp = s->top;
	while (temp != s->base)//将排好序的数组入栈
	{

		strcpy(temp->date, y[i]);
		temp = temp->pNext;
		i--;
	}
	for (i = 0; i < q; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	free(x);
	free(y);
	return 1;
}
//用于计算后缀式
status cal_list(stack s)
{
	stack mystack;
	initstack(&mystack);
	ElemType *temp;
	temp = s.top;
	while (temp != s.base)
	{
		if (judgenumber(temp->date[0]) != -1)//如果不是括号就进行压栈
		{
			push(&mystack, temp->date);
			//判断是否可以进行运算
			if ( judgenumber(mystack.top->date[0]) == 1)//是运算符
			{
				if (judgenumber(mystack.top->pNext->date[0]) == 0)//数字
				{
					if (judgenumber(mystack.top->pNext->pNext->date[0]) == 0)//进行数字转换并计算并压栈
					{
						char *v=(char*)malloc(sizeof(char)*DATE_NUM);//用到
						int a =(int) atof(mystack.top->pNext->date);
                        
						int b = (int)atof(mystack.top->pNext->pNext->date);
						
						int c = cal(a, b, mystack.top->date[0]);
						printf("\n取出栈中的 %d %d 进行%c的计算", a, b, mystack.top->date[0]);
						printf("  %d %c %d = %d\n", a, mystack.top->date[0], b, c);
						Pop_Stack(&mystack, &v);
						//printf("弹出%s \n", val);
						Pop_Stack(&mystack, &v);
						//printf("弹出%s \n", val);
						Pop_Stack(&mystack, &v);
					     itoa(c, v,10);
						push(&mystack, v);
					}
				}
			}
			temp = temp->pNext;
		}
		else
		{
         	temp = temp->pNext;
		}
	}
	return (int)atof(mystack.top->date);
}
int cal(int a, int b, char x)//进行计算
{
	switch (x)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return b - a;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return b/a;
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
