#define MAXQSIZE 100 //队列大小定义

typedef char ElemType;

typedef struct BiTNode { //二叉树结构定义
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree, *QElemType;

typedef enum {
	OK,        // OK = 0
	ERROR     //ERROR = 1
}Status;//函数返回状态 

typedef enum {
	false,
	true
}bool;//布尔返回状态

typedef struct QNode { //队列结构定义
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//==========队列的基本操作=============// 
Status InitQueue(LinkQueue *Q);
bool QueueEmpty(LinkQueue Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);

//==========二叉树的基本操作=============// 
Status PostOrderTraverse(BiTree T);
int Depth(BiTree T);
int Width(BiTree T);
bool Compelete(BiTree T);
int Count(BiTree T);
int CountLeaf(BiTree T);
bool Full(BiTree T);
Status CountNode(BiTree T);

//==========方法一，以字符串的形式“根 左子树 右子树”定义一棵二叉树=============// 
Status CreateBiTree(BiTree *T);

//==========方法二，由二叉树的先序和中序序列建树=============// 
int Search(char ino[], char p);
int Getlength(char *p);
Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n);
void print(char *pre, char *in, BiTree T);

#pragma once