#define MAXQSIZE 100 //���д�С����

typedef char ElemType;

typedef struct BiTNode { //�������ṹ����
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree, *QElemType;

typedef enum {
	OK,        // OK = 0
	ERROR     //ERROR = 1
}Status;//��������״̬ 

typedef enum {
	false,
	true
}bool;//��������״̬

typedef struct QNode { //���нṹ����
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//==========���еĻ�������=============// 
Status InitQueue(LinkQueue *Q);
bool QueueEmpty(LinkQueue Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);

//==========�������Ļ�������=============// 
Status PostOrderTraverse(BiTree T);
int Depth(BiTree T);
int Width(BiTree T);
bool Compelete(BiTree T);
int Count(BiTree T);
int CountLeaf(BiTree T);
bool Full(BiTree T);
Status CountNode(BiTree T);

//==========����һ�����ַ�������ʽ���� ������ ������������һ�ö�����=============// 
Status CreateBiTree(BiTree *T);

//==========���������ɶ�������������������н���=============// 
int Search(char ino[], char p);
int Getlength(char *p);
Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n);
void print(char *pre, char *in, BiTree T);

#pragma once