#include "operation.h"
const char OP[7] = { '+','-','*','/','(',')','#' };//struct an array to store 7 operators
const int  PrecedenceTable[7][7] = {
	{ 1,1,0,0,0,1,1 },
	{ 1,1,0,0,0,1,1 },
	{ 1,1,1,1,0,1,1 },
	{ 1,1,1,1,0,1,1 },
	{ 0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0 }
};//according to the chart 3-1 to make a precedenceTable 
Status InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(SIZE * sizeof(SElemType));
	if (!S->base) { exit(OVERFLOW); }//To judge whether the last step is success or not
	S->top = S->base;//the stack we initialize is empty
	S->stacksize = SIZE;
	return OK;
}//initialize a stack of operators
Status InitStackn(COUNT *S) {
	S->base = (int *)malloc(SIZE * sizeof(int));
	if (!S->base) { exit(OVERFLOW); }
	S->top = S->base;
	S->stacksize = SIZE;
	return OK;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) { return TRUE; }
	else { return FALSE; }
}//To judge whether the stack is empty or not
Status StackEmptyn(COUNT S) {
	if (S.base == S.top) { return TRUE; }
	else { return FALSE; }
}

Status Pop(SqStack *S, SElemType *e) {
	if (S->top == S->base) { return ERROR; }//we can not pop a character from an empty stack
	*e = *(--S->top);//poping the current top character is equal to make the second top character to the topmost position
	return OK;
}
Status Popn(COUNT *S, int *e) {
	if (S->top == S->base) { return ERROR; }
	*e = *(--S->top);
	return OK;
}

Status Push(SqStack *S, SElemType e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		//if the current stack is full,we should realloc some extra space to it before pushing a new character
		if (!S->base) { exit(OVERFLOW); }
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;//after reallocing,both the top character and the stacksize are changed
	}
	*S->top++ = e;//assign 'e' to s->top and then remove the adress of s->top to next position 
	return OK;
}
Status Pushn(COUNT *S, int e) {
	if (S->top - S->base >= S->stacksize) {
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
		if (!S->base) { exit(OVERFLOW); }
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status GetTop(SqStack S, SElemType *e) {
	//if the stack is not empty,use the charactor to return the value of s->top.else return ERROR
	if (S.top == S.base) { return ERROR; }
	*e = *(S.top - 1);
	return OK;
}
Status GetTopn(COUNT S, int *e) {

	if (S.top == S.base) { return ERROR; }
	*e = *(S.top - 1);
	return OK;
}

int IN(char ch) {
	int i = 0, flag = 0;
	for (i = 0; i < 7; i++) {
		if (ch == OP[i])
		{
			flag = 1;
			break;
		}
	}
	return flag;
}//To judge whether the character is one of the seven operators in the OP array or not

void Pass(char *suffix, char ch) {
	static int i = 0;
	suffix[i] = ch;
	i++;
}//Passing the charactor to an array so that we can change the original nifix experssion to suffix experssion

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
	SElemType c = '#';
	InitStack(&S);
	Push(&S, c);
	char *p;
	p = exp;
	char ch = *p;
	while (StackEmpty(S) == FALSE) {
		if (!IN(ch)) {
			Pass(suffix, ch);
		}//if 'ch' is an operand,passing it to the array suffix directly
		else {
			switch (ch) {
			case'(':
				Push(&S, ch);//Inserting  '(' as a new s->top value
				break;
			case')':
				Pop(&S, &c);//Poping the current s->top value and using 'c' to rutern the value
				while (c != '(') {
					Pass(suffix, c);//unless 'c' is ')',passing the operator to array suffix while poping 'c' to the stack S
					Pop(&S, &c);
				}
				break;
			default:
				while (GetTop(S, &c) == OK && (Precede(c, ch))) {
					Pass(suffix, c);
					Pop(&S, &c);
				}
				if (ch != '#') {
					Push(&S, ch);
				}
				break;
			}//if 'ch' is an operater,comparing it with the current top character in priority before pushing
		}
		if (ch != '#') {
			p++;
			ch = *p;
		}//Setting this step to ignore the appearance of operaters that  are not in the array of OP
		else {
			Pop(&S, &ch);
			Pass(suffix, ch);
		}
	}//end of while
}//end of transform

int count(char *suffix) {
	SqStack OPTR;
	COUNT OPND;
	InitStack(&OPTR);
	InitStackn(&OPND);
	char *p;
	p = suffix;
	char ch = *p;
	char c;
	while (ch != '#') {
		if (!IN(ch)) {
			Pushn(&OPND, ch - '0');//transforming operand's character code form to number form
		}
		else {
			Push(&OPTR, ch);
			if ((OPND.top - 1) && (OPND.top - 2)) {
				//if the operand stack have two operand form top to bottom,operate them
				int t1, t2;
				Popn(&OPND, &t1);
				Popn(&OPND, &t2);
				int t3 = operate(ch, t1, t2);
				Pushn(&OPND, t3);
				Pop(&OPTR, &c);
			}
		}
		p++;
		ch = *p;
	}//end of while
	int sum;
	Popn(&OPND, &sum);
	return sum;
}