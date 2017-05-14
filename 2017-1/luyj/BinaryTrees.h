#include <stdio.h>
#include <stdlib.h>


extern int i;
extern int high;
extern int wide[50];
extern int swide;


typedef char TElemType;



typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	true,
	false
}bool;

/*=========�������Ķ�������洢��ʾ===========*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*===========���е���ʽ�洢��ʾ===========*/
typedef struct QNode
{
	BiTNode data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//������ʼ��
void valInit(int level, int wide[50], int count, int ncounts);

//���ַ����ַ�����ȡ��;
char AbstractWord(char*s);



/*=========���л�������=========*/
Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue*Q, BiTNode e);
Status DeQueue(LinkQueue*Q, BiTNode*e);
bool QueueEmpty(LinkQueue*Q);


/*===========�������Ļ�������===========*/
//����������;
Status CreateBiTree(BiTree *T, char *s);
//�Ժ���ʽ���;
Status PostOrderTraverse(BiTree T);
//�ݻٶ�����;
Status destoryBiTree(BiTree T);


/*===========����������㷨ʵ��===========*/
//�ݹ����������߶�;
int getHigh(BiTree T);
int Max(int x, int y);
//�ݹ������������;
int getWide(BiTree T,int level);
// �ݹ����Ҷ�ӽ��;
void CountLeaf(BiTree T, int *count,int *ncounts);
//�ж��Ƿ�Ϊ��ȫ������.���ö��жԶ��������й�����ȱ�����
bool isComplete(BiTree);


/*=========�����������=========*/

//�������ʽ;
void printBiTree(BiTree T);
//���Ҷ�Ӽ���Ҷ�ӽ����Ŀ;
void printLeafNumber(BiTree T, int count, int ncounts);
//�жϲ�����Ƿ�Ϊ��ȫ������;
void printIsComplete(BiTree T);





