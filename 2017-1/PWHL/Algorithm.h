//�Թ����

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
	char **maze;//�Թ�����(ָ��ָ���ָ�룬���Ե���ά����ʹ��)
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
//����һ����ջS  
Status InitStack(SqStack *S);

//��ʼ���Թ�����  
Status InitMaze(MazeType *M);

//����ջS��S���ٴ���  
Status DestroyStack(SqStack *S);

//��ջS��Ϊ��ջ 
Status ClearStack(SqStack *S);

//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE  
Status StackEmpty(SqStack S);

//����SԪ�صĸ�������ջ�ĳ���  
int StackLength(SqStack S);

//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
Status GetTop(SqStack S, SElemType *e);

//����Ԫ��eΪ�µ�ջ��Ԫ��  
Status Push(SqStack *S, SElemType e);

//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  
Status Pop(SqStack *S, SElemType *e);



//����Թ�  
Status PrintMaze(MazeType *M);

//���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջ�У���ջ��  
//��ջ������������TRUE�����򷵻�FALSE
Status MazePath(SqStack *S, MazeType maze, PosType start, PosType end);

//���Թ��ĵ�ǰλ��pos����Ϊ"�߹�"����footprint��λ��Ϊ1  
Status FootPrint(MazeType *M, PosType pos);

//�жϵ�ǰλ���Ƿ��߹�  
Status Pass(MazeType *M, PosType pos);

//�����½�㣬��step��pos��d��ʼ���ý��  
SElemType NewSElem(int step, PosType pos, int d);

//��λ��pos�ķ�����Ϊd  
PosType NextPos(PosType pos, int d);

//���Թ�M��posλ�ã���Ϊ���ߣ��ɹ�����OK�����򷵻�ERROR  
Status MarkPrint(MazeType *M, PosType pos);

//����Թ���·��  
Status PrintFoot(MazeType *M, SqStack *S);
//http://blog.csdn.net/nuaazdh/article/details/7051278(������Դ)