#include <stdio.h>
#include <stdlib.h>

extern int i;
extern int high;
extern int wide[50];
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct QNode
{
	BiTree data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;



//���ַ����ַ�����ȡ��;
char AbstractWord(char*s);

//����������;
Status CreateBiTree(BiTree *T, char *s);

//�Ժ���ʽ���;
Status PostOrderTraverse(BiTree T);

//�ݻٶ�����;
Status destoryBiTree(BiTree T);

//�ݹ����������߶�;
int getHigh(BiTree T);
int Max(int x, int y);

//�ݹ������������;
int getWide(BiTree T,int level);

//�ݹ����Ҷ�ӽ��;
void CountLeaf(BiTree T, int *count,int *ncounts);



