#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char ElemType_Optr;
typedef int ElemType_Opnd;
typedef enum {
	ERROR,
	OK
}Status;
typedef enum {
	false,
	true
}bool;
typedef struct {
	ElemType_Opnd *base;
	ElemType_Opnd *top;
	int stacksize;
}OpndStack;
typedef struct {
	ElemType_Optr *base;
	ElemType_Optr *top;
	int stacksize;
}OptrStack;

Status InitOptrStack(OptrStack *S);
Status GetOptrTop(OptrStack S, ElemType_Optr *e);
Status PushOptr(OptrStack *S, ElemType_Optr e);
Status PopOptr(OptrStack *S, ElemType_Optr *e);
bool OptrStackEmpty(OptrStack S);

Status InitOpndStack(OpndStack *S);
Status GetOpndTop(OpndStack S, ElemType_Opnd *e);
Status PushOpnd(OpndStack *S, ElemType_Opnd e);
Status PopOpnd(OpndStack *S, ElemType_Opnd *e);
bool OpndStackEmpty(OpndStack S);

Status Standard(char *exp);
bool Precede(ElemType_Optr a, ElemType_Optr b);
bool IN(char c);
ElemType_Opnd Operate(ElemType_Opnd a, ElemType_Optr op, ElemType_Opnd b);

Status Evaluate(char suffix[][5]);
Status Pass(char suffix[50][5], char *c);
Status Transform(char suffix[50][5], char exp[]);