#include<stdio.h>
#include<stdlib.h>
//#define SElemType int
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct _PosType{
    int x;
    int y;
}PosType;

typedef struct _SElemType {
    int ord;
    PosType seat;
    int di;
}SElemType;

typedef struct _SqStack {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

typedef enum{
    FALSE,
    OK,
    OVERFLOW,
    TRUE,
    ERROR
}Status;

typedef  int MazeType[10][10];
  //  int (*array)[10];
//    maze={1,1,1,1,1,1,1,1,1,1,
//        1,0,0,1,0,0,0,1,0,1,
//        1,0,0,1,0,0,0,1,0,1,
//        1,0,0,0,0,1,1,0,0,1,
//        1,0,1,1,1,0,0,0,0,1,
//        1,0,0,0,1,0,0,0,0,1,
//        1,0,1,0,0,0,1,0,0,1,
//        1,0,1,1,1,0,1,1,0,1,
//        1,1,0,0,0,0,0,0,0,1,
//        1,1,1,1,1,1,1,1,1,1}

Status InitStack(SqStack *S);
Status StackEmpty(SqStack S);
Status Pop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status MazePath(MazeType maze,PosType start,PosType end);
SElemType NewElem(int ,PosType,int);
int Pass(PosType curpos,MazeType maze,MazeType);
void FootPrint(PosType curpos,MazeType);
PosType NextPos(PosType a,int b,MazeType maze);
void MarkPrint(PosType,MazeType);
void PRINT(MazeType,SqStack*);
