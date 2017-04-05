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
ElemType_Optr GetOptrTop(OptrStack S);
Status PushOptr(OptrStack *S, ElemType_Optr e);
Status PopOptr(OptrStack *S, ElemType_Optr *e);
bool OptrStackEmpty(OptrStack S);

Status InitOpndStack(OpndStack *S);
Status GetOpndTop(OpndStack S, ElemType_Opnd *e);
Status PushOpnd(OpndStack *S, ElemType_Opnd e);
Status PopOpnd(OpndStack *S, ElemType_Opnd *e);
bool OpndStackEmpty(OpndStack S);

Status Standard(char *exp);
char Precede(ElemType_Optr a, ElemType_Optr b);
Status Pass(char *suffix, char c);
Status Transform(char *suffix, char exp[]);
bool  IN(char c);
ElemType_Opnd Operate(ElemType_Opnd a, ElemType_Optr op, ElemType_Opnd b);
const char *GetOpnd(const char *p, ElemType_Opnd *op);
ElemType_Opnd Evaluate(char *exp);
