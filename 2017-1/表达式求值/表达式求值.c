#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include <string>  
#include <stack>  
#include<algorithm>  
#define MAXN 1000  
using namespace std;  
stack<char> s;  //定义了一个栈  

char *tranfExp(char* exp)  
{  
	char tempStr[1000];//保存后缀表达式的字符串  

	int i=0,j=0;  
	while(exp[i] !='\0')  
	{  
		if(exp[i]>='0' &&exp[i]<='9')  //如果是数字字符串就保存到后缀表达式字符串中  
		{  
			tempStr[j++] = exp[i];  
		}  
		else if(exp[i] == '(' )  //如果是左括号及入栈  
		{  
			s.push(exp[i]);  
		}  
		else if(exp[i] == ')' )  //如果是右括号就把接近栈顶的左括号上面所有的运算符出栈存进字符串中  左括号出栈  
		{  
			while(s.empty() == false)  
			{  
				if(s.top() == '(' )  
				{  
					s.pop();  
					break;  
				}  
				else  
				{  
					tempStr[j++] = s.top();  
					s.pop();  
				}  
			}  
		}  
		else if(exp[i] == '+' || exp[i] == '-')   //如果的事+-|操作符就把比他优先级高或者等于的所有运算符出栈进入字符串  
		{  
			while(s.empty() == false)  
			{  
				char ch = s.top();  
				if(ch == '+'||ch == '-'||ch == '/'||ch == '*')  
				{  

					tempStr[j++] = s.top();  
					s.pop();  
				}  
				else  
					break;  
			}  
			s.push(exp[i]);  
		}  
		else if(exp[i] == '*' || exp[i] == '/')  //类似于扫描到+- 只是如果栈中有=-运算符就不用出栈  因为运算符优先级比较小  
		{  
			while(s.empty() == false)  
			{  
				char ch = s.top();  
				if(ch == '/' || ch=='*')  
				{  
					tempStr[j++] = s.top();  
					s.pop();  
				}  
				else  
					break;  
			}  
			s.push(exp[i]);  
		}  
		i++;  
	}  
	while(s.empty() == false)   //把栈中剩余的所有运算符出栈  
	{  
		tempStr[j++] = s.top();  
		s.pop();  
	}  
	tempStr[j] = 0;   //最后一个赋值为0  也就是字符串结束的标志  
	return tempStr;   //返回已经得到的后缀表达式  
}  
int calcExp(char* exp)// 计算后缀表达式  
{  
	puts(exp);   //展示已经得到的后缀  
	while( !s.empty() )  
		s.pop();  
	int i=0;  
	while(exp[i] != '\0')  
	{  
		if(exp[i]>='0' && exp[i]<='9')  
		{  
			s.push(exp[i]-'0');  
		}  
		else if(exp[i] == '-')  
		{  
			int m = s.top();  
			s.pop();  
			int n = s.top();  
			s.pop();  
			s.push(n-m);  
		}  
		else if(exp[i] == '+')  
		{  
			int m = s.top();  
			s.pop();  
			int n = s.top();  
			s.pop();  
			s.push(n+m);  
		}  
		else if(exp[i] == '/')  
		{  
			int m = s.top();  
			s.pop();  
			int n = s.top();  
			s.pop();  
			s.push(n/m);  
		}  
		else if(exp[i] == '*')  
		{  
			int m = s.top();  
			s.pop();  
			int n = s.top();  
			s.pop();  
			s.push(n*m);  
		}  
		i++;  
	}   
	printf("\n\n\n");  
	return s.top();  
}  
int main()  
{  
	char str[1000];  
	char* tranStr;  
	tranStr = (char *)malloc(100*sizeof(char));  
	printf("please input expression with kuohao:\n");  
	scanf("%s",str);  
	tranStr =  tranfExp(str);//中缀表达式转换为后缀表达式函数  
	//puts(tranStr); //输出转换后的后缀表达式  
	printf("%d",calcExp(tranStr));  
	return 0;  
}  