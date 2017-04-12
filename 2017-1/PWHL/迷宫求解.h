#include <stdio.h>  
#include <stdlib.h>  

#define OK      1  
#define ERROR   0  
#define TRUE    1  
#define FALSE   0  
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10 //ջ���� 

#define COLUMN 10   //�Թ�����  
#define ROW 10      //�Թ�����  

typedef int Status; //��������״̬  

typedef struct //�Թ����� 
{
	char **maze;//�Թ�����  //(ָ��ָ���ָ�룬���Ե���ά����ʹ��)
	int **footprint;//�㼣����  
	int row;//����  
	int column;//����  
}MazeType;

typedef struct //�Թ�λ������  
{
	int x;
	int y;
}PosType;

typedef struct
{
	int number;//ͨ������·���ϵ�"���"  
	PosType seat;//ͨ�������Թ��е�"����λ��"  
	int direction;//�Ӵ�ͨ�ſ�������һͨ�����"����"  
}SElemType;  //ջԪ������  

typedef struct //˳��ջ�ṹ����  
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);
//����һ����ջS  
Status InitMaze(MazeType *M);
//��ʼ���Թ�����  
Status DestroyStack(SqStack *S);
//����ջS��S���ٴ���  
Status ClearStack(SqStack *S);
//��ջS��Ϊ��ջ  
Status StackEmpty(SqStack S);
//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE  
int StackLength(SqStack S);
//����SԪ�صĸ�������ջ�ĳ���  
Status GetTop(SqStack S, SElemType *e);
//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
Status Push(SqStack *S, SElemType e);
//����Ԫ��eΪ�µ�ջ��Ԫ��  
Status Pop(SqStack *S, SElemType *e);
//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  
Status StackTraverse(const SqStack *S);
//��ջ�׵�ջ�����ζ�ÿ��Ԫ�ؽ��з���  
Status PrintMaze(MazeType *M);
//����Թ�  
Status MazePath(SqStack *S, MazeType maze, PosType start, PosType end);
//���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջ�У���ջ��  
//��ջ������������TRUE�����򷵻�FALSE  
Status FootPrint(MazeType *M, PosType pos);
//���Թ��ĵ�ǰλ��pos����Ϊ"�߹�"����footprint��λ��Ϊ1  
Status Pass(MazeType *M, PosType pos);
//�жϵ�ǰλ���Ƿ��߹�  
SElemType NewSElem(int step, PosType pos, int d);
//�����½�㣬��step��pos��d��ʼ���ý��  
PosType NextPos(PosType pos, int d);
//��λ��pos�ķ�����Ϊd  
Status MarkPrint(MazeType *M, PosType pos);
//���Թ�M��posλ�ã���Ϊ���ߣ��ɹ�����OK�����򷵻�ERROR  
Status PrintFoot(MazeType *M, SqStack *S);
//����Թ���·��  
