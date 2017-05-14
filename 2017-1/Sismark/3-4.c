#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#define CREAT 10
#define OVERFLOW -1
#define OK 0
#define ERROR -1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *pS) {
	//构造空栈
	(*pS).base = (SElemType *)malloc(SIZE * sizeof(SElemType));
	if (!(*pS).base) exit(OVERFLOW);//存储分配失败
	(*pS).top = (*pS).base;
	(*pS).stacksize = SIZE;
	return OK;
}

Status Push(SqStack *pS, SElemType e) {
	//插入元素e为新的栈顶元素
	if ((*pS).top - (*pS).base >= (*pS).stacksize) {
		(*pS).base = (SElemType *)realloc((*pS).base, ((*pS).stacksize + CREAT) * sizeof(SElemType));
		if (!(*pS).base) exit(OVERFLOW);
		(*pS).top = (*pS).base + (*pS).stacksize;
		(*pS).stacksize += CREAT;
	}
	*(*pS).top++  = e;
	return OK;
}

Status Pop(SqStack *pS, SElemType *e) {
	if ((*pS).top == (*pS).base) return ERROR;
	*e = *--(*pS).top;
	return *e;
	return OK;
}

Status GetTop(SqStack S, SElemType *e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return e;
	return OK;
}

Status StackEmpty(SqStack *pS) {
	if ((*pS).base == (*pS).top) return TRUE;
	else return FALSE;
}

Status IN(SElemType e) {
	if (e != '+'&&e != '-'&&e != '*'&& e != '/'&&e != '#'&&e != '('&&e != ')') return TRUE;
	else return FALSE;
}

Status Precede(SElemType ch, SElemType e) {
	switch (e) {
	case'+': {
		if (ch == '#' || ch == '(') return '>';
		else return '<';
		break;
	}
	case'-': {
		if ( ch == '#'||ch=='(') return '>';
		else return '<';
		break;
	}
	case'*': {
		return '>';
		break;
	}
	case'/': {
	    return '>';
		break;
	}
	case'#': {
		if (ch == '#') return '=';
		else return '<';
		break;
	}
	case'(': return '>'; break;
	case')': return '!!'; break;
	}
	return OK;
}

Status Count() {
	SqStack S1;
	SqStack S2;
	SElemType e;
	int E=0;
	InitStack(&S1);//造栈
	InitStack(&S2);
	Push(&S1, '#');
	int i = 0, j = 0;
	char ch[100] = "1*2+(3-8/4)*6#";
	printf("表达式:%s\n", ch);
	char suf[100] = " ";
	char ah[100] = " ";
	while (ch[i] != '#') {
		if (IN(ch[i]) && ch[i] != '#')
		{
			suf[j] = ch[i];
			j++;
			i++;
		}
		else {
			switch (Precede(GetTop(S1,&e), ch[i])) {

			case'>':
			{ Push(&S1, ch[i]); i++;  }; break;

			case'<':
			{  Pop(&S1, &e); suf[j] = e;    j++;  }; break;

			case'=': break;

			case'!!': { 
				while (e != '(') {
					Pop(&S1, &e); if (e != '(') { suf[j] = e;   j++; }
				};
					  i++;
			}
			}
		}

	}
	while (!StackEmpty(&S1)) {
		Pop(&S1, &e);
		suf[j] = e; j++;
	};
	printf("后缀式:");
	for (int k = 0; k < j; k++) 	 	 printf("%c", suf[k]);
	printf("\n");
	//start
	i = 0;
	while (suf[i] != '#') {
		if (IN(suf[i])) { Push(&S2, suf[i] - '0');  i++; }
		if (!IN(suf[i])) {
			int a1, a2,a3;
			Pop(&S2, &E); a1=E ;
			Pop(&S2, &E); a2=E;
			printf("a2=%d ope=%c a1=%d\n",a1,suf[i],a2);
			if (suf[i] == '+') a3 = a2+a1;
			if (suf[i] == '-') a3 = a2-a1;
			if (suf[i] == '*') a3 = a2*a1;
			if (suf[i] == '/') a3 = a2/a1;
			printf("a3=%d\n",a3);
			Push(&S2, a3);
			i++;
		}
	}//end while
	printf("\n表达式结果:%d", Pop(&S2, &E));
	return 0;
}
int main() {
	Count();
	return 0;
}
//a*b + (c - d / e)*f#