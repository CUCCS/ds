#include <stdio.h>  
#include <stdlib.h>  

#define OK      1  
#define ERROR   0  
#define TRUE    1  
#define FALSE   0  
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10 //栈增长 

#define COLUMN 10   //迷宫行数  
#define ROW 10      //迷宫列数  

typedef int Status; //函数返回状态  

typedef struct //迷宫类型 
{
	char **maze;//迷宫数据  //(指向指针的指针，可以当二维数组使用)
	int **footprint;//足迹数据  
	int row;//行数  
	int column;//列数  
}MazeType;

typedef struct //迷宫位置坐标  
{
	int x;
	int y;
}PosType;

typedef struct
{
	int number;//通道块在路劲上的"序号"  
	PosType seat;//通道块在迷宫中的"坐标位置"  
	int direction;//从此通信块走向下一通道块的"方向"  
}SElemType;  //栈元素类型  

typedef struct //顺序栈结构定义  
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);
//构造一个空栈S  
Status InitMaze(MazeType *M);
//初始化迷宫数据  
Status DestroyStack(SqStack *S);
//销毁栈S，S不再存在  
Status ClearStack(SqStack *S);
//把栈S置为空栈  
Status StackEmpty(SqStack S);
//若栈S为空栈，则返回TRUE，否则返回FALSE  
int StackLength(SqStack S);
//返回S元素的个数，即栈的长度  
Status GetTop(SqStack S, SElemType *e);
//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE  
Status Push(SqStack *S, SElemType e);
//插入元素e为新的栈顶元素  
Status Pop(SqStack *S, SElemType *e);
//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  
Status StackTraverse(const SqStack *S);
//从栈底到栈顶依次对每个元素进行访问  
Status PrintMaze(MazeType *M);
//输出迷宫  
Status MazePath(SqStack *S, MazeType maze, PosType start, PosType end);
//若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈中（从栈底  
//到栈顶），并返回TRUE；否则返回FALSE  
Status FootPrint(MazeType *M, PosType pos);
//将迷宫的当前位置pos设置为"走过"，即footprint该位置为1  
Status Pass(MazeType *M, PosType pos);
//判断当前位置是否走过  
SElemType NewSElem(int step, PosType pos, int d);
//创建新结点，用step，pos，d初始化该结点  
PosType NextPos(PosType pos, int d);
//将位置pos的方向设为d  
Status MarkPrint(MazeType *M, PosType pos);
//将迷宫M的pos位置，设为已走，成功返回OK；否则返回ERROR  
Status PrintFoot(MazeType *M, SqStack *S);
//输出迷宫的路径  
