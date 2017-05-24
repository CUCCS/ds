#define STACK_SIZE 100

typedef char SElemType;
typedef struct _Stack {
    SElemType *top;
    SElemType *base;
    int stacksize;
} SqStack;

typedef enum {
    OK,
    OVERFLOW,
    ERROR
} Status;

typedef enum {
    false,
    true
} bool;

Status InitStack(SqStack *S, int size);
void DestroyStack(SqStack *S);
bool IsStackEmpty(SqStack *S);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
SElemType GetTop(SqStack S);

