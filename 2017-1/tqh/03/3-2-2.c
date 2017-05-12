#include <stdio.h>

#define M 1000

typedef int Elemtype;
typedef enum{
	ERROR,
	OK
}Status;

 typedef struct Stack {
        char string[M];
        Elemtype top;
    }Stack;
 //定义stack结构体类型
 void InitStack(Stack *s)
    {
        s->top = -1;
    }
	//结构体初始化
 Status PushStack(Stack *s, char ch)
    {
        if(s->top == M-1) {
            return ERROR;
        }
        s->top++;
        s->string[s->top] = ch;
        return OK;
    }
 //入栈
 Status PopStack(Stack *s, char *ch)
    {
        if(s->top == -1) {
            return ERROR;
        }
        *ch = s->string[s->top];
        s->top--;
        return OK;
    }
 //出栈

 Status GetTop(Stack *s, char *ch)
 {
      if(s->top == -1) {
          return ERROR;
      }
        *ch = s->string[s->top];
        return OK;
 }
 //得到指定元素的值
 Status IsEmpty(Stack *s)
    {
        if(s->top == -1) 
		{
            return OK;
        } 
		else {
            return ERROR;
        }
    }
 //判断是否栈为空
Elemtype MatchBracket(char ch1, char ch2)
{
    if(ch1 == '(' && ch2 == ')') {
        return 1;
    }
    if(ch1 == '[' && ch2 == ']') {
        return 1;
    }
    if(ch1 == '{' && ch2 == '}') {
        return 1;
    }
	return 0;
}
//判断括号是否匹配
int main()
{
    Stack s;
    char str[M] = {0}, ch;
    int i;

    InitStack(&s);
    fprintf(stdout, "Input brackets:");
    fscanf(stdin, "%s", str);
    for(i = 0; str[i] != 0; i++) {
        switch(str[i]) {
            case '(':
            case '[':
            case '{':
                PushStack(&s, str[i]);
                break;
            case ')':
            case ']':
            case '}':
                if(IsEmpty(&s)) {
                    printf("right bracket spilth.\n");
                    return 0;
                } else {
                    GetTop(&s, &ch);
                    if(MatchBracket(ch , str[i])) {
                        PopStack(&s, &ch);
                    } else{
                        printf("left and right brackets are different.\n");
                        return 0;
                    }
                }
				break;
			default:
				printf("Input error\n");
        }
    }
    if(IsEmpty(&s)) {
        printf("Left and right brackets are matched.\n");
    } else {    
        printf("Left bracket spilth..\n");
    }
    return 0;
}