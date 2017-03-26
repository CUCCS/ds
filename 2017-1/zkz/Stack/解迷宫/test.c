#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
#include "Stack.h"

#define SIZE 10
#define Maze(x,y) Maze[x-1][y-1]
#define RotateDir(a) ((a)-1)
#define Marks(a) Marks[(a)] /*����ϰ��*/
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
	/*�趨ǽ��*/
	for (i = 1; i <= SIZE; ++i) {
		Maze(i, 1) = Maze(i, SIZE) = Maze(1, i) = Maze(SIZE, i) = WALL;
	}
	for (i = 0; i < 20; ++i) {
		Maze(Walls[i].x,Walls[i].y)=WALL;
	}
	/*�趨���*/
	Maze(start.x, start.y) = RIGHT;
	/*�趨�յ�*/
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
	/*�趨��ǰλ�õĳ�ֵΪ���λ��*/
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
		/*����ǰλ�ÿ�ͨ*/
		if (isMovableFT(data, current)) {
			if (Maze(current.x, current.y) == FLOOR)
				Maze(current.x, current.y) += 1;
			/*����ǰλ�ò���ջ��*/
			Push(S, current);
			DP("Push current ( %d , %d ) \n",current.x,current.y);
			/*����λ���ǳ���λ�ã����㷨����*/
			if (current.x == destination.x && current.y == destination.y) {
				DP("Current is at destination . End searching \n");
				return;
			}
			/*�����л���ǰλ�õĶ��ڷ���Ϊ�µĵ�ǰλ��*/
			SetCurrent(TheEast(current),1);
			
		}
		/*��������ǰλ�ò���ͨ*/
		else{
			/*	��ջ����*/
			DP("Stack is %sempty\n",isEmpty ? "" : "not ");
			if (!isEmpty) {
				GetTop(S, &data);
				DP("Data is top of stack ( %d , %d ) \n",data.x,data.y);
				DP("Data's mark is %c , ",Marks(Maze(data.x,data.y)));
				/*��ջ��λ��������������δ��̽��*/
				if (Maze(data.x,data.y) < UP) {
					DP("still new direction to search \n");
					/*	����˳ʱ�뷽����תջ��λ��*/
					Maze(data.x, data.y) += 1;
					/*	���õ�ǰλ��Ϊջ��λ�õ���һ���ڿ�*/
					SetCurrent(Next(data),0);
				}
				/*��ջ��λ�õ����ܾ�����ͨ����*/
				else {
					DP("all directions searched \n");
					if (Maze(data.x, data.y) == UP)
						Maze(data.x, data.y) += 1;
					/*	ɾȥջ��λ��*/
					Pop(S, &data);
					DP("Pop ( %d , %d ) \n",data.x,data.y);
					/*	��ջ���գ������²����µ�ջ��λ��*/
					
				}
			}/*end if !isEmpty*/
		}/*end ifMovable*/
		IsStackEmpty(S, &isEmpty);
	} while (!isEmpty);
	/*��ջ�գ�������Թ�û��ͨ·��*/
}

int main() {
	InitMaze();
	SolveMaze();
	if(!DEBUG)
		ShowMaze();
	return 0;
}