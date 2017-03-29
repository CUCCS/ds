#include <stdio.h>
#include "Stack.h"

/*���ٽ���ѭ��*/
#define times(i,size) for((i)=1;(i)<=(size);++(i))
/*ָ����ͼ����*/
#define SIZE 10
/*�ú�ʵ����1Ϊ�±���Թ���ȡ��*/
#define Maze(x,y) Maze[(x)-1][(y)-1]
/*�ж��������Ƿ����*/
#define equal(pa,pb) ((pa).x == (pb).x && (pa).y == (pb).y)

/*����DEBUG && printf(...)����ʹ�ã������ΪDP(...)*/
/*��ϣ����DEBUGΪ0ʱ������ݣ�ʹ��!DP(...)����*/
#define DP DEBUG && printf
#define DEBUG 0



/*����*/
/*��Ѱ·����Ҳ����Ϊ���Σ����Լ򻯺����ĳЩ����*/
typedef enum _Terrain {FLOOR,RIGHT,DOWN,LEFT,UP,BAY,END,WALL} Terrain;
/*��ӡ�Թ�ʱ����ӡ���Ӧ�ķ���*/
char Marks[] = " >V<^$@#";
char Marks_2[] = "  ��������";
/*�Թ������εĶ�ά����*/
Terrain Maze[SIZE][SIZE] ;

/*ȫ�ֱ���������յ�*/
Point start ;
Point end ;

/*����ĳ����ĵ���*/
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
/*����5���������ڻ�ȡĳ�������/��/��/��/ǰ���ĵ�*/
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

/*�㷨 �Թ����*/
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
