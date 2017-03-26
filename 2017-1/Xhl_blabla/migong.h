#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MazeScale 10
//���λ������
typedef struct position
{
	int x;
	int y;
}position;
//ÿ��һ�����м�¼
typedef struct SElement
{
	int  ord;//ͨ����·�����ϵ����
	position  seat;//ͨ������·���ϵ�����
	int di;//�Ӵ�ͨ����������һ��ġ�����

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