#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum {
	false,
	true
}bool;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);
Status DestoryStack(SqStack *S);
Status ClearStack(SqStack *S);
bool StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType *e);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
Status StackTraverse(SqStack S, Status(*visit)());
