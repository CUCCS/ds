#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree, *QElemType;

//队列基本操作
typedef enum{
    OK,
	ERROR
}Status;
typedef struct QNode {
    QElemType data;
	struct QNode *next;
}QNode, * QueuePtr;
typedef struct {
    QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//构造一个空队列Q
Status InitQueue(LinkQueue *Q)
{
	Q->front =	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		return ERROR;
	}
	Q->front->next = NULL;
	return OK;
}

//若队列Q为空队列，则返回TRUE，否则返回FALSE
Status QueueEmpty(LinkQueue *Q)
{
	if(Q->rear==Q->front)
	{
		return OK;
	}
	return ERROR;
}

//插入元素e为Q的新队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
Status DeQueue(LinkQueue *Q, QElemType e )
{
	QNode *p;
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	e = p->data;
	printf("%d was deleted.\n", e);
	Q->front->next = p->next;
	if(Q->rear==p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

//返回Q的元素个数，即为队列的长度
int QueueLength(LinkQueue Q)
{
	int count = 0;
	QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        //printf("%d",p->data);
        p=p->next;
		count++;
     }
	 return count;
}

Status PostOrderTraverse(BiTree T) {
	//后序遍历二叉树的递归算法
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}

int Depth(BiTree T){ // 返回二叉树的深度
	int depthval;
	int depthLeft, depthRight;
    if(!T) {
        depthval = 0;
    } else {
        depthLeft = Depth(T->lchild);
        depthRight= Depth(T->rchild);
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    } 
    return depthval;
}

int Width(BiTree T) {
	// 层序遍历二叉树,返回二叉树的宽度
	LinkQueue Q;
	BiTNode *p = T;
	int width = 1; //二叉树宽度
	int temp = 0; //上一层宽度
	int last = 0;
	int now = 0; //当前宽度

	if (!T) {
		return 0;
	}
	InitQueue(&Q); //建立工作队列
	EnQueue(&Q, T); //将根节点入队列
	last = 1;
	while (!QueueEmpty(&Q)) {
		temp = last;
		while (temp != 0) {
			DeQueue(&Q, T);
			if (p->lchild) {
				EnQueue(&Q, p->lchild);
			}
			if (p->rchild) {
				EnQueue(&Q, p->rchild);
			}
			temp--;
		}
		now = QueueLength(Q);
		width = now > width ? now : width;
		last = now;
	}
	return ++width;
}

int Count(BiTree T) {
	//返回指针T所指二叉树中所有结点个数
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = Count(T->lchild);
		n = Count(T->rchild);
		return m + n + 1;
	}
}

int CountLeaf(BiTree T) {
	// 返回指针T所指二叉树中所有叶子结点个数
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = CountLeaf(T->lchild);
		n = CountLeaf(T->rchild);
		return m + n;
	}
}

bool Compelete(BiTree T) {
	//判断是否为完全二叉树
	LinkQueue Q;
	BiTNode *p = T;
	InitQueue(&Q); //建立工作队列
	EnQueue(&Q, T);

	while (!QueueEmpty(&Q)) {
		DeQueue(&Q, T);
		if (p->lchild) {
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(&Q, p->rchild);
		}
		if ((!p->lchild) && p->rchild) {
			return false;
		}
	}
	return true;
}

bool Full(BiTree T) {
	//判断是否为满树（若树的深度为k，应有2^k-1个结点）
	if (pow(2.0, Depth(T)) - 1 == Count(T)) {
		printf("It is a full tree\n");
		return true;
	}
	printf("It is not a full tree\n");
	return false;
}
