#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum {
	false,
	true
}bool;

Status InitStack(SqStack *S);
bool StackEmpty(SqStack S);
Status GetTop(SqStack S, ElemType *e);
Status Push(SqStack *S, ElemType e);
Status Pop(SqStack *S, ElemType *e);

bool Precede(char a, char b);
bool IN(char c);
Status Pass(char *suffix, char c);
Status Evaluate(char *suffix);
Status Transform(char *suffix, char exp[]);
int Operate(int a, char op, int b);