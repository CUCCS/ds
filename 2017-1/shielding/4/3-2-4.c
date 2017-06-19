//��������α���� �������ݼ��������ִ���ο�http://www.cnblogs.com/AlgrithmsRookie/p/5958040.html

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;//����״̬

typedef enum{
	false,
	true
}bool;

typedef struct{
	int x;
	int y;
}PosType;//����λ��

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;//ջ��Ԫ������

typedef struct _Stack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}Stack;//ջ

Status InitStack(Stack *S){
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}//��ʼ��;��ջ�ɹ�����������ok��1�������򷵻�error��0����

bool IsStackEmpty(Stack *S)
{
	if (S->top == S->base) return true;
	else return false;
}//�ж�ջ�Ƿ�Ϊ��

Status GetTop(Stack *S, SElemType *e)
{
	if (IsStackEmpty(S)) return ERROR;
	e = S->top - 1;
	return OK;
}//��ȡջ��Ԫ�أ�����ǿ�ջ����ERROR

int StackLength(Stack* S)
{
	return S->top - S->base;
}//����ջ�ĳ���

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
	return OK;//����Ԫ��eΪ�µ�ջ��Ԫ�أ�����ɹ��򷵻�OK
}

int Pop(Stack* S, SElemType* e)
{
     if (IsStackEmpty(S)) return ERROR;
	 *e = *--S->top;
     return OK;
}//����ջ��Ԫ�ظ�ֵ��e,�ɹ�����OK��ʧ�ܷ���ERROR

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
}//���쵱ǰ·���ܷ�ͨ�� 



//��˳ʱ�뷽��Ӷ���ʼѰ�Ҿ�����ĳһ��λ�õ��ٽ�λ�� 
PosType NextPosition(PosType now, int direction)
{
    PosType next;
	int x = now.x;
    int y = now.y;
	switch (direction)
	{
		//�� 
		case 1:{
			next.x = x;
			next.y = y + 1;
			break;
	    }
		//�� 
		case 2:{
			next.x = x + 1;
			next.y = y;
			break;
		}
		//��
		case 3:{
			next.x = x;
			next.y = y - 1;
			break;
		}
		//��
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
	curpos.y = 1;//��ʼ����ǰλ��Ϊ������� 
	int curstep = 1;//��̽���Ĳ��� 
	do
		 {
			if (Pass(curpos))
			{
				FootPrint(curpos, curstep);//�����������㼣 
				SElemType e;
				e.di = 1;
				e.ord = curstep;
				e.seat.x = curpos.x;
				e.seat.y = curpos.y;
				Push(&path, e);//����·�� 
				if (curpos.x == MazeScale - 2 && curpos.y == MazeScale - 2) break; //��������Թ����յ���˳�ѭ��
				curpos = NextPosition(curpos, 1);//�����λ������һ��λ��
				curstep++;
			}
		else//��ǰλ�ò���ͨ��
			{
				if (!IsStackEmpty(&path))
				{
			         SElemType e;
				     Pop(&path, &e);
				     curstep--;
		           //����һ�����е���Χ·�����Ѿ������Թ���·����ջ����� 
					while (e.di == 4 && !IsStackEmpty(&path)){
						MarkPrint(e.seat);
						Pop(&path, &e);
						curstep--;
					}
					if (e.di<4){
						curpos = NextPosition(e.seat, e.di + 1);//����һ������̽��
						e.di++;
						curstep++;
						Push(&path, e);
					}
		         }
		    }
		}while (!IsStackEmpty(&path));
	    printf("\n");
	    //��ӡ������Թ����� 
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

