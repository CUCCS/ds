#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MazeScale 10
//点的位置坐标
typedef struct position
{
	int x;
	int y;
}position;
//每走一步进行记录
typedef struct SElement
{
	int  ord;//通道在路径块上的序号
	position  seat;//通道块在路径上的坐标
	int di;//从此通道块走向下一块的“方向“

}SElement;
typedef struct Mystack
{
	SElement *base;
	SElement *top;
	int stacksize;
}Mystack;
int  Initstack(Mystack *);
int Pass(position);
void Footprint(position, int);
int Push(Mystack*, SElement);
position Nextposition(position, int);
int isStackempty(Mystack*);
int Pop(Mystack *, SElement*);
position Nextposition(position, int);
void Markprint(position p);
int Maze[MazeScale][MazeScale] ;
void clear(Mystack*);