#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
#include "Stack.h"

#define SIZE 10
#define Maze(x,y) Maze[x-1][y-1]
#define RotateDir(a) ((a)-1)
#define Marks(a) Marks[(a)] /*个人习惯*/
#define DEBUG 1
#define DP DEBUG && printf

char Marks[] = { ' ','>','v','<','^' ,'$','#','@'};
typedef enum _Mark {FLOOR, RIGHT,DOWN,LEFT,UP,BAY,WALL,END} Mark;

int Maze[SIZE][SIZE] = { 0 };
Point start = { 2, 2 };
Point destination = { 9,9 };
Point current;
Point Next(Point p) {
	int dir  = Maze(p.x, p.y);
	if (dir == LEFT)
		p.x -= 1;
	else if (dir == DOWN)
		p.y += 1;
	else if (dir == RIGHT)
		p.x += 1;
	else if (dir == UP)
		p.y -= 1;
	return p;
}
inline Point TheLeft(Point p) {
	p.x -= 1;
	return p;
}
inline Point TheDown(Point p) {
	p.y += 1;
	return p;
}
inline Point TheEast(Point p) {
	p.x += 1;
	return p;
}
inline Point TheUp(Point p) {
	p.y -= 1;
	return p;
}
void SetCurrent(Point p , int needUpdate) {
	DP("Set current as ( %d , %d ) \n",p.x,p.y);
	current.x = p.x;
	current.y = p.y;
	if (needUpdate) {
		char * ptr = &Maze(current.x, current.y);
		if (*ptr <= UP)
			*ptr += 1;
	}
}
void InitMaze() {
	int i;
	Point Walls[20] = {
		2,8,	3,5,	3,7,	3,8,
		4,2,	4,3,	4,5,	4,8,
		5,5,	5,6,	5,8,	6,4,
		7,4,	7,7,	7,8,	8,2,
		8,3,	8,8,	9,5,	9,6
	};
	/*设定墙体*/
	for (i = 1; i <= SIZE; ++i) {
		Maze(i, 1) = Maze(i, SIZE) = Maze(1, i) = Maze(SIZE, i) = WALL;
	}
	for (i = 0; i < 20; ++i) {
		Maze(Walls[i].x,Walls[i].y)=WALL;
	}
	/*设定起点*/
	Maze(start.x, start.y) = RIGHT;
	/*设定终点*/
	Maze(destination.x, destination.y) = END;
}
void ShowMaze() {
	int x, y;
	printf("  ");
	for (x = 1; x <= SIZE; ++x)
		printf("%x ",x);
	printf("\n");
	for (y = 1; y <= SIZE; ++y) {
		printf("%x ",y);
		for (x = 1; x <= SIZE; ++x)
			printf("%c ", Marks(Maze(x,y)));
		printf("\n");
	}
}
int isMovableFT(Point from, Point to) {
	if (Maze(to.x, to.y) == FLOOR || Maze(to.x, to.y) == END)
		return 1;
	if (Maze(to.x, to.y) > UP)
		return 0;
	if (abs(Maze(from.x,from.y)-Maze(to.x,to.y)) == 2)
		return 0;
	else
		return 1;
}
void SolveMaze() {
	Stack S;
	int isEmpty;
	time_t t;
	Elemtype data;
	InitStack(&S);
	/*设定当前位置的初值为入口位置*/
	Push(S, start);
	SetCurrent(TheEast(start),1);\
	do {
		printf("\n");
		ShowMaze();
		DEBUG || system("cls");
		IsStackEmpty(S, &isEmpty);
		GetTop(S, &data);
		DP("Current is ( %d , %d ) , %c \n",
			current.x, current.y,
			Marks(Maze(current.x, current.y)));
		DP("From ( %d , %d ) to ( %d , %d ) is %smovable \n", data.x,data.y,current.x,current.y,isMovableFT(data, current) ? "" : "not ");
		/*若当前位置可通*/
		if (isMovableFT(data, current)) {
			if (Maze(current.x, current.y) == FLOOR)
				Maze(current.x, current.y) += 1;
			/*将当前位置插入栈顶*/
			Push(S, current);
			DP("Push current ( %d , %d ) \n",current.x,current.y);
			/*若该位置是出口位置，则算法结束*/
			if (current.x == destination.x && current.y == destination.y) {
				DP("Current is at destination . End searching \n");
				return;
			}
			/*否则切换当前位置的东邻方块为新的当前位置*/
			SetCurrent(TheEast(current),1);
			
		}
		/*否则若当前位置不可通*/
		else{
			/*	若栈不空*/
			DP("Stack is %sempty\n",isEmpty ? "" : "not ");
			if (!isEmpty) {
				GetTop(S, &data);
				DP("Data is top of stack ( %d , %d ) \n",data.x,data.y);
				DP("Data's mark is %c , ",Marks(Maze(data.x,data.y)));
				/*且栈顶位置尚有其他方向未被探索*/
				if (Maze(data.x,data.y) < UP) {
					DP("still new direction to search \n");
					/*	则沿顺时针方向旋转栈顶位置*/
					Maze(data.x, data.y) += 1;
					/*	设置当前位置为栈顶位置的下一相邻块*/
					SetCurrent(Next(data),0);
				}
				/*且栈顶位置的四周均不可通，则*/
				else {
					DP("all directions searched \n");
					if (Maze(data.x, data.y) == UP)
						Maze(data.x, data.y) += 1;
					/*	删去栈顶位置*/
					Pop(S, &data);
					DP("Pop ( %d , %d ) \n",data.x,data.y);
					/*	若栈不空，则重新测试新的栈顶位置*/
					
				}
			}/*end if !isEmpty*/
		}/*end ifMovable*/
		IsStackEmpty(S, &isEmpty);
	} while (!isEmpty);
	/*若栈空，则表明迷宫没有通路。*/
}

int main() {
	InitMaze();
	SolveMaze();
	if(!DEBUG)
		ShowMaze();
	return 0;
}