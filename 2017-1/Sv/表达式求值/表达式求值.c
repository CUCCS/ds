#include "3.3.h"

Status InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S->base) { exit(OVERFLOW); }
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) { return TRUE; }
	else { return FALSE; }
}

Status Pop(SqStack *S, SElemType *e) {
	if (S->top == S->base) { return ERROR; }
	*e = *(--S->top);
	return OK;
}

Status Push(SqStack *S, SElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S->base) { exit(OVERFLOW); }
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push

Status GetTop(SqStack S, SElemType *e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.top == S.base) { return ERROR; }
	*e = *(S.top - 1);
	return OK;
}

Status nInitStack(COUNT *S) {
	S->base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!S->base) { exit(OVERFLOW); }
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status nStackEmpty(COUNT S) {
	if (S.base == S.top) { return TRUE; }
	else { return FALSE; }
}

Status nPop(COUNT *S, int *e) {
	if (S->top == S->base) { return ERROR; }
	*e = *(--S->top);
	return OK;
}

Status nPush(COUNT *S, int e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(int));
		if (!S->base) { exit(OVERFLOW); }
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push

Status nGetTop(COUNT S, int *e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.top == S.base) { return ERROR; }
	*e = *(S.top - 1);
	return OK;
}

int IN(char ch) {
	int i = 0,flag=0;
	for (i = 0; i < 7; i++) {
		if (ch == OP[i]) { flag = 1; break; }
	}
	return flag;
}

void Pass(char *suffix, char ch) {
	static int i = 0;
	suffix[i] = ch;
	i++;
}

int Precede(char c, char ch) {
	int i, j;
	switch (c) {
	case'+':i = 0; break;
	case'-':i = 1; break;
	case'*':i = 2; break;
	case'/':i = 3; break;
	case'(':i = 4; break;
	case')':i = 5; break;
	case'#':i = 6; break;
	}
	switch (ch) {
	case'+':j = 0; break;
	case'-':j = 1; break;
	case'*':j = 2; break;
	case'/':j = 3; break;
	case'(':j = 4; break;
	case')':j = 5; break;
	case'#':j = 6; break;
	}
	return PrecedenceTable[i][j];
}

int operate(char ch, int t1, int t2) {
	switch (ch) {
	case'+':return t2 + t1; break;
	case'-':return t2 - t1; break;
	case'*':return t2*t1; break;
	case '/':return t2 / t1; break;
	}

}

void transform(char *suffix, char *exp) {
	SqStack S;
	SElemType c='#' ;
	InitStack(&S);
	Push(&S, c);
	char *p;p = exp;
	char ch = *p;
	while (StackEmpty(S)==FALSE) {
		if (!IN(ch)) {
			Pass(suffix,ch);
		}
		else {
			switch (ch) {
				case'(':
					Push(&S, ch);
					break;
				case')':
					Pop(&S, &c);
					while (c != '(') {
						Pass(suffix, c);
						Pop(&S,&c);
					}
					break;
				default:
					// Precede函数是判定运算符的栈顶运算符与读入的运算符之间优先关系的函数
					while (GetTop(S, &c) == OK && (Precede(c, ch))) {
						Pass(suffix, c);
						Pop(&S, &c);
					}
					if (ch != '#') {
						Push(&S, ch);
					}
					break;
			}//switch
		}//else
		if (ch != '#') {
			p++;
			ch = *p;
		}
		else {
			Pop(&S, &ch);
			Pass(suffix, ch);
		}
	}//while
}//transform

int count(char *suffix) {
	//typedef int SElemType;
	SqStack(OPTR);//操作符
	COUNT(OPND);//操作数
	InitStack(&OPTR);
	nInitStack(&OPND);
	char *p; p = suffix;
	char ch = *p;
	char c;
	while (ch != '#') {
		if (!IN(ch)) {
			nPush(&OPND, ch - '0');
		}
		else {
			Push(&OPTR, ch);
			if ((OPND.top - 1) && (OPND.top - 2)) {
				//如果栈顶和其下面的栈有数，则执行算数操作
				int t1, t2;
				//GetTop(OPND, &t1);
				nPop(&OPND, &t1);
				nPop(&OPND, &t2);
				int t3 = operate(ch, t1, t2);
				nPush(&OPND, t3);
				Pop(&OPTR, &c);
			}
		}
			p++;
			ch = *p;
	}//while
		int sum;
		nPop(&OPND,&sum);
		return sum;
}