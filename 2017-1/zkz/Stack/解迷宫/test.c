#include <stdio.h>
#include "Stack.h"

/*快速进行循环*/
#define times(i,size) for((i)=1;(i)<=(size);++(i))
/*指定地图长宽*/
#define SIZE 10
/*用宏实现以1为下标从迷宫中取点*/
#define Maze(x,y) Maze[(x)-1][(y)-1]
/*判断两个点是否相等*/
#define equal(pa,pb) ((pa).x == (pb).x && (pa).y == (pb).y)

/*由于DEBUG && printf(...)大量使用，将其简化为DP(...)*/
/*若希望当DEBUG为0时输出内容，使用!DP(...)即可*/
#define DP DEBUG && printf
#define DEBUG 0



/*地形*/
/*将寻路方向也定义为地形，可以简化后面的某些操作*/
typedef enum _Terrain {FLOOR,RIGHT,DOWN,LEFT,UP,BAY,END,WALL} Terrain;
/*打印迷宫时，打印其对应的符号*/
char Marks[] = " >V<^$@#";
char Marks_2[] = "  →↓←↑";
/*迷宫，地形的二维数组*/
Terrain Maze[SIZE][SIZE] ;

/*全局变量起点与终点*/
Point start ;
Point end ;

/*设置某个点的地形*/
void setTerrain(Point p, Terrain t){
	Maze(p.x, p.y) = t;
}
void setTerrainXY(int x, int y, Terrain t) {
	Maze(x, y) = t;
}

void InitMaze() {
	int i,j;
	times(j, SIZE)
		times(i, SIZE)
		setTerrainXY(i, j, FLOOR);
	/*Set walls*/
	times(i, SIZE) {
		Maze(1, i) = Maze(SIZE, i) = Maze(i, 1) = Maze(i, SIZE) = WALL;
	}
	Point Walls[20] = { 
		4,2,	8,2,	4,3,	8,3,	6,4,
		7,4,	3,5,	4,5,	5,5,	9,5,
		5,6,	9,6,	3,7,	7,7,	2,8,
		3,8,	4,8,	5,8,	7,8,	8,8
	};
	times(i, 20) {
		setTerrainXY(Walls[i - 1].x, Walls[i - 1].y, WALL);
	}
	/*Set start*/
	setTerrain(start, RIGHT);
	/*Set end*/
	setTerrain(end, END);
}
int ShowTerrain(Terrain t) {
	/*set its return-value-type as int
	so it's suitable for DEBUG && XX expression*/
	if (t >= 5)
		printf("%c ", Marks[t]);
	else
		printf("%c%c", Marks_2[2 * t], Marks_2[2 * t + 1]);
}
int ShowMaze() {
	/*set its return-value-type as int
	so it's suitable for DEBUG && XX expression*/
	int x, y;
	printf("  ");
	times(x, SIZE)
		printf("%x ",x);
	printf("\n");
	times(y, SIZE) {
		printf("%x ",y);
		times(x, SIZE)
			ShowTerrain(Maze(x,y));
		printf("\n");
	}

	return 0;
}
int isMovable(Point p) {
	if (Maze(p.x, p.y) == FLOOR || Maze(p.x, p.y) == END)
		return 1;
	return 0;
}
/*以下5个函数用于获取某个点的右/下/左/上/前方的点*/
Point TheRight(Point p) {
	p.x += 1;
	return p;
}
Point TheDown(Point p) {
	p.y += 1;
	return p;
}
Point TheLeft(Point p) {
	p.x -= 1;
	return p;
}
Point TheUp(Point p) {
	p.y -= 1;
	return p;
}
Point TheNext(Point p) {
	Terrain t = Maze(p.x, p.y);
	if (t == RIGHT)
		return TheRight(p);
	if (t == DOWN)
		return TheDown(p);
	if (t == LEFT)
		return TheLeft(p);
	if (t == UP)
		return TheUp(p);
	return p;
}

/*算法 迷宫求解*/
void SolveMaze() {
	Stack S;
	Point current,data,top;
	int isEmpty;
	//current = TheRight(start);
	//if(Maze(current.x,current.y)==FLOOR)
	//	setTerrain(current, RIGHT);
	InitStack(&S);
	Push(S, start);
	do {
		DP("\n");
		DEBUG && ShowMaze();
		IsStackEmpty(S, &isEmpty);
		if (isEmpty) {
			DP("Stack is empty \n");
			break;
		}
		GetTop(S, &top);
		DP("Top of stack : %d , %d \n",top.x,top.y);
		current = TheNext(top);
		DP("Set current as top ");
		if(! equal(current,top))
			DP("'s next : %d , %d ", current.x, current.y);
		DP("\n");
		/*If current is end*/
		if (equal(current, end)) {
			DP("Destination found \n");
			break;
		}
		/*If current is not end*/
		DP("Current's terrain is \'");
		DEBUG && ShowTerrain(Maze(current.x, current.y));
		DP("\' \n");
		/*If current is movable*/
		if (isMovable(current)) {
			DP("Current is movable \n");
			setTerrain(current,RIGHT);
			DP("Push current \n");
			Push(S, current);
		}
		/*Else if current is not movable*/
		else {
			DP("Current is not movable \n");
			/*Top has new direction to search*/
			DP("Top's terrain is \'");
			DEBUG && ShowTerrain(Maze(top.x, top.y));
			DP("\' \n");
			if (Maze(top.x, top.y) <= UP) {
				Maze(top.x, top.y) += 1;
				DP("Top's terrain is changed to \'");
				DEBUG && ShowTerrain(Maze(top.x, top.y));
				DP("\' \n");
			}
			/*Top has no new direction to search*/
			else {
				Pop(S, &data);
				DP("Pop Stack \n");
				IsStackEmpty(S, &isEmpty);
				if (!isEmpty) {
					GetTop(S, &top);
					DP("New top is %d , %d \n", top.x, top.y);
				}
				if (Maze(top.x, top.y) <= UP) {
					Maze(top.x, top.y) += 1;
					DP("Top's terrain is changed to \'");
					DEBUG && ShowTerrain(Maze(top.x, top.y));
					DP("\' \n");
				}
			}
		}
		IsStackEmpty(S, &isEmpty);
		if (isEmpty)
			DP("Stack is empty \n");
	} while (!isEmpty);
	DP("End searching \n");
}

int main() {
	start.x = 2;
	start.y = 2;
	end.x = 9;
	end.y = 9;
	InitMaze();
	printf("Test 1 : start at %d , %d , end at %d , %d \n\n",start.x,start.y,end.x,end.y);
	!DP("Before:\n");
	DEBUG || ShowMaze();
	SolveMaze();
	!DP("\nAfter:\n");
	DEBUG || ShowMaze();
	
	start.x = 9;
	start.y = 9;
	end.x = 2;
	end.y = 2;
	InitMaze();
	setTerrainXY(5, 7, WALL);
	printf("\nTest 2 : start at %d , %d , end at %d , %d \n", start.x, start.y, end.x, end.y);
	printf("And this time , block 5 , 7 is set as WALL\n\n");
	!DP("Before:\n");
	DEBUG || ShowMaze();
	SolveMaze();
	!DP("\nAfter:\n");
	DEBUG || ShowMaze();
}
