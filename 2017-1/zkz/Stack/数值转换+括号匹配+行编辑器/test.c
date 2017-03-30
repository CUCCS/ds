#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Status.h"
#include "Stack.h"

#define DEBUG 1
#define pare(l,r) \
		case (l):\
			DEBUG && printf("��ջ \n");\
			Push(S, *brackets);\
			break;\
		case (r):\
			DEBUG && printf("��ջ , ");\
			Pop(S, &bracket);\
			DEBUG && printf("���Ϊ %c \n",bracket);\
			if (bracket != (*brackets == ')' ? '(' : *brackets == ']' ? '[' : '{')) {\
				DEBUG && printf("    ���ʧ��\n");\
				*pResult = 0;\
				return;\
			}\
			break;//end pare(l,r)
#define check(s) \
	printf("��\"%s\" ����ƥ��\n", (s));\
	checkBrackets((s), &result);\
	printf("  \"%s\" ����Խ��Ϊ %d \n", (s), result);\

int testStack() {
	printf("=== �������� ===\n");
	Stack S1 = NULL;
	int n, isEmpty , size;
	CHECK(InitStack(&S1));
	printf("��ʼ��ջ\n");
	CHECK(SizeOfStack(S1,&size));
	printf("ջ��СΪ %d \n",size);
	CHECK(Push(S1, 5));
	printf("���� 5 ��ջ\n");
	CHECK(SizeOfStack(S1, &size));
	printf("ջ��СΪ %d \n", size);
	printf("���� : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(Push(S1, 9));
	printf("���� 9 ��ջ\n");
	CHECK(SizeOfStack(S1, &size));
	printf("ջ��СΪ %d \n", size);
	printf("���� : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(IsStackEmpty(S1, &isEmpty));
	printf("��ʱջ%sΪ�� \n", isEmpty ? "" : "��");
	CHECK(Pop(S1,&n));
	printf("��ջ , ���Ϊ %d \n",n);
	printf("���� : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(EmptyStack(S1));
	printf("��ջ���\n");
	CHECK(SizeOfStack(S1, &size));
	printf("ջ��СΪ %d \n", size);
	printf("���� : ");
	CHECK(Traverse(S1));
	printf("\n\n");

	return 0;
}
void conversion(int n,int d) {
	Stack S;
	int data,isEmpty;
	InitStack(&S);
	DEBUG && printf("    ��ʼ��ջ\n");
	DEBUG && printf("    n = %d , d = %d \n",n,d);
	while (n) {
		Push(S, n%d);
		DEBUG && printf("    n%%d= %d ��ջ , n/=d \n",n%d);
		n /= d;
	}
	IsStackEmpty(S,&isEmpty);
	DEBUG && !isEmpty && printf("    ջ��Ϊ�� , ��ʼ������\n");
	while (!isEmpty) {
		Pop(S, &data);
		printf("%d",data);
		IsStackEmpty(S, &isEmpty);
	}
	DEBUG && printf("\n    ջΪ�� , ѭ������");
}
void checkBrackets(char * brackets,int* pResult) {
	Stack S;
	int bracket,isEmpty;
	InitStack(&S);
	while (*brackets != '\0') {
		DEBUG && printf("    ��ǰ���� %c , ",*brackets);
		switch (*brackets) {
		pare('(',')')
		pare('[',']')
		pare('{','}')
		default:
			break;
		}/*end switch*/
		++brackets;
	}/*end while*/
	IsStackEmpty(S,&isEmpty);
	DEBUG && printf("    ƥ����� , ջ%sΪ�� \n", isEmpty ? "" : "��");
	*pResult = isEmpty;
}
void lineEdit(char * source , char ** pTarget) {
	Stack S;
	char * p = source;
	int size ,i=0 , isEmpty;
	Elemtype data;
	InitStack(&S);
	DEBUG && printf("    ��ʼ��ջ \n");
	do {
		DEBUG && printf("    ��ǰ�ַ�Ϊ %c , ",*p);
		if (*p == '#') {
			DEBUG && printf("�˸�� , ִ�г�ջ���� , ");
			Pop(S, &data);
			DEBUG && printf("��ջ���Ϊ %c \n",data);
		}
		else if (*p == '@') {
			DEBUG && printf("���з� , ִ��������ջ���� :");
			Push(S, (Elemtype)*p);
			do {
				Pop(S, &data);
				DEBUG && printf(" %c",data);
				IsStackEmpty(S, &isEmpty);
			} while (!isEmpty && data != '\n');
			!isEmpty && Push(S, (Elemtype)'\n');
		}
		else {
			DEBUG && printf("��ջ \n");
			Push(S, (Elemtype)*p);
		}
		++p;
	} while (*p != '\0');
	Push(S, (Elemtype)*p);
	DEBUG && printf("    ��ʼ��ջ�����ݿ������ַ�����\n");
	DEBUG && printf("    ��ջ��� :");
	SizeOfStack(S,&size);
	*pTarget = (char*)malloc(size *sizeof(char));
	for (i = size-1; i >= 0; --i) {
		Pop(S,&data);
		DEBUG && printf(" %c",data);
		(*pTarget)[i] = (char)data;
	}
	DEBUG && printf("\n");
}
void doSomeConversion() {
	printf("=== ����ת�� ===\n");
	int n;
	srand((unsigned int)time(NULL));
	n = rand() % 1024;
	printf("n = %d \n",n);
	printf("convert n to Bin : ");
	DEBUG && printf("\n");
	conversion(n, 2);
	printf("\n");
	printf("convert n to Aug : ");
	DEBUG && printf("\n");
	conversion(n, 8);
	printf("\n");
	printf("\n");
}
void doSomeCheckBrackets() {
	printf("=== ����ƥ�� ===\n");
	int result;
	check("([]{()})");
	check("}");
	check("({(]");
	printf("\n");
}
void doSomeLineEdit() {
	printf("=== �б༭�� ===\n");
	char *sa1 = "whli##ilr#e ( s#*s)\noutcha@putchar(*s=#++);";
	char *ta1;
	char *sa2 = "Mrs.##.Zong###hong is the f**king#######most\nugly@handsome man.";
	char *ta2;
	printf("(1) ����Ϊ : \n%s\n", sa1);
	lineEdit(sa1, &ta1);
	printf("���Ϊ : \n%s\n", ta1);
	printf("(2) ����Ϊ : \n%s\n", sa2);
	lineEdit(sa2, &ta2);
	printf("���Ϊ : \n%s\n", ta2);
}
int main() {
	DEBUG && testStack();
	doSomeConversion();
	doSomeCheckBrackets();
	doSomeLineEdit();
	return 0;
}