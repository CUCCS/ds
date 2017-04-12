//我必须得把顺序栈改成链式栈
//只能处理有一个括号的运算式  而且是int 整数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SUANSHUSHI_NUM 20//输入的式子所在的数组的长度
#define DATE_NUM 10      //栈的字符串元素的长度
#define STACR_INIT_SIZE 100
#define  STACR_ADD_SIZE 10
#define  WEIDU_NUM 20;
typedef struct ElemType
{
	char  *date;
	struct ElemType *pNext;
}ElemType;
typedef int status;//整数的别名
typedef struct
{
	ElemType  *base;
	ElemType   *top;
}stack;//用于存储运算符和操作数的栈  
status initstack(stack *s);//初始化栈  
status destory(stack *s);
status isStackempty(stack s);//检验栈是否为空  是返回0 否返回1
status judgenumber(char x);//用于判断是数字还是操作符 运算符返回 1 界限符返回-1  过界返回-10 数字返回0
status rank_list(stack*, char x[]);//用于后缀式的排序
status cal_list(stack);//用于计算后缀式
char** conversion(char x[]);//用于字符串的拆分
//char** rank_num(char **);//对传进来的二维数组进行排序
status judge_pre(char);//对字符的优先级进行比较  优先级越大数字越大
status judge_pre2(char);//此时运算符和数字的运算符优先级一样大
status push(stack *s, char *e);
status initstack(stack* s);//创建一个空栈，里面没有任何有效数据；  
status Pop_Stack(stack *S, char ** val);
void Traverse_Stack(stack s);
status rank_list_more(stack *s);
int cal(int a, int b, char x);
char* number_to_zifu(int x);
status destory(stack *top);