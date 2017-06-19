//参照书上伪代码 测试数据及其他部分代码参考http://www.cnblogs.com/AlgrithmsRookie/p/5958040.html

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;//返回状态

typedef enum{
	false,
	true
}bool;

typedef struct{
	int x;
	int y;
}PosType;//坐标位置

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;//栈的元素类型

typedef struct _Stack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}Stack;//栈

Status InitStack(Stack *S){
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}//初始化;若栈成功创建，返回ok（1）；否则返回error（0）；

bool IsStackEmpty(Stack *S)
{
	if (S->top == S->base) return true;
	else return false;
}//判断栈是否为空

Status GetTop(Stack *S, SElemType *e)
{
	if (IsStackEmpty(S)) return ERROR;
	e = S->top - 1;
	return OK;
}//获取栈顶元素，如果是空栈返回ERROR

int StackLength(Stack* S)
{
	return S->top - S->base;
}//返回栈的长度

Status Push(Stack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S->base) exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;//插入元素e为新的栈顶元素，插入成功则返回OK
}

int Pop(Stack* S, SElemType* e)
{
     if (IsStackEmpty(S)) return ERROR;
	 *e = *--S->top;
     return OK;
}//弹出栈顶元素赋值给e,成功返回OK，失败返回ERROR

#define MazeScale 10
int Maze[MazeScale][MazeScale] = { { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }, { 2, 0, 0, 2, 0, 0, 0, 2, 0, 2 }, { 2, 0, 0, 2, 0, 0, 0, 2, 0, 2 }, { 2, 0, 0, 0, 0, 2, 2, 0, 0, 2 },
{2, 0, 2, 2, 2, 0, 0, 0, 0, 2}, { 2, 0, 0, 0, 2, 0, 0, 0, 0, 2 }, { 2, 0, 2, 0, 0, 0, 2, 0, 0, 2 }, { 2, 0, 2, 2, 2, 0, 2, 2, 0, 2 }, { 2, 2, 0, 0, 0, 0, 0, 0, 0, 2 }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 } };
 
bool Pass(PosType pos)
{
	 if (Maze[pos.x][pos.y] == 0)
     {
		 return true;
     }
	 return false;
}//考察当前路径能否通过 



//按顺时针方向从东开始寻找矩阵当中某一个位置的临近位置 
PosType NextPosition(PosType now, int direction)
{
    PosType next;
	int x = now.x;
    int y = now.y;
	switch (direction)
	{
		//东 
		case 1:{
			next.x = x;
			next.y = y + 1;
			break;
	    }
		//南 
		case 2:{
			next.x = x + 1;
			next.y = y;
			break;
		}
		//西
		case 3:{
			next.x = x;
			next.y = y - 1;
			break;
		}
		//北
		case 4:{
			next.x = x - 1;
			next.y = y;
			break;
	    }
		default:break;
		}
	return next;
}

void FootPrint(PosType p, int step)
{
	Maze[p.x][p.y] = step;
}

void MarkPrint(PosType p)
{
    Maze[p.x][p.y] = -1;
}

int main()
{
    for (int i = 0; i<MazeScale; i++)
	     {
	         for (int j = 0; j<MazeScale; j++)
	        {
	             printf("%d ", Maze[i][j]);
	        }
	        printf("\n");
	    }
    Stack path;
    InitStack(&path);
    PosType curpos;
	curpos.x = 1;
	curpos.y = 1;//初始化当前位置为矩阵入口 
	int curstep = 1;//被探索的步数 
	do
		 {
			if (Pass(curpos))
			{
				FootPrint(curpos, curstep);//可走则留下足迹 
				SElemType e;
				e.di = 1;
				e.ord = curstep;
				e.seat.x = curpos.x;
				e.seat.y = curpos.y;
				Push(&path, e);//加入路径 
				if (curpos.x == MazeScale - 2 && curpos.y == MazeScale - 2) break; //如果到了迷宫的终点就退出循环
				curpos = NextPosition(curpos, 1);//东面的位置是下一个位置
				curstep++;
			}
		else//当前位置不能通过
			{
				if (!IsStackEmpty(&path))
				{
			         SElemType e;
				     Pop(&path, &e);
				     curstep--;
		           //将这一段所有的周围路径都已经被测试过的路径从栈中清除 
					while (e.di == 4 && !IsStackEmpty(&path)){
						MarkPrint(e.seat);
						Pop(&path, &e);
						curstep--;
					}
					if (e.di<4){
						curpos = NextPosition(e.seat, e.di + 1);//换下一个方向探索
						e.di++;
						curstep++;
						Push(&path, e);
					}
		         }
		    }
		}while (!IsStackEmpty(&path));
	    printf("\n");
	    //打印出结果迷宫矩阵 
		for (int i = 0; i<MazeScale; i++)
		{
			for (int j = 0; j<MazeScale; j++)
			{
				printf("%5d", Maze[i][j]);
			}
			printf("\n");
		}
		return 0;
}

