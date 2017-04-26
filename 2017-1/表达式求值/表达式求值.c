#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include <string>  
#include <stack>  
#include<algorithm>  
#define MAXN 1000  
using namespace std;  
stack<char> s;  //������һ��ջ  

char *tranfExp(char* exp)  
{  
	char tempStr[1000];//�����׺���ʽ���ַ���  

	int i=0,j=0;  
	while(exp[i] !='\0')  
	{  
		if(exp[i]>='0' &&exp[i]<='9')  //����������ַ����ͱ��浽��׺���ʽ�ַ�����  
		{  
			tempStr[j++] = exp[i];  
		}  
		else if(exp[i] == '(' )  //����������ż���ջ  
		{  
			s.push(exp[i]);  
		}  
		else if(exp[i] == ')' )  //����������žͰѽӽ�ջ�����������������е��������ջ����ַ�����  �����ų�ջ  
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
		else if(exp[i] == '+' || exp[i] == '-')   //�������+-|�������Ͱѱ������ȼ��߻��ߵ��ڵ������������ջ�����ַ���  
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
		else if(exp[i] == '*' || exp[i] == '/')  //������ɨ�赽+- ֻ�����ջ����=-������Ͳ��ó�ջ  ��Ϊ��������ȼ��Ƚ�С  
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
	while(s.empty() == false)   //��ջ��ʣ��������������ջ  
	{  
		tempStr[j++] = s.top();  
		s.pop();  
	}  
	tempStr[j] = 0;   //���һ����ֵΪ0  Ҳ�����ַ��������ı�־  
	return tempStr;   //�����Ѿ��õ��ĺ�׺���ʽ  
}  
int calcExp(char* exp)// �����׺���ʽ  
{  
	puts(exp);   //չʾ�Ѿ��õ��ĺ�׺  
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
	tranStr =  tranfExp(str);//��׺���ʽת��Ϊ��׺���ʽ����  
	//puts(tranStr); //���ת����ĺ�׺���ʽ  
	printf("%d",calcExp(tranStr));  
	return 0;  
}  