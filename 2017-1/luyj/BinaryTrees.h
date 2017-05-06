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

/*=========二叉树的二叉链表存储表示===========*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*===========队列的链式存储表示===========*/
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

//变量初始化
void valInit(int level, int wide[50], int count, int ncounts);

//将字符从字符串中取出;
char AbstractWord(char*s);



/*=========队列基本操作=========*/
Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue*Q, BiTNode e);
Status DeQueue(LinkQueue*Q, BiTNode*e);
bool QueueEmpty(LinkQueue*Q);


/*===========二叉树的基本操作===========*/
//建立二叉树;
Status CreateBiTree(BiTree *T, char *s);
//以后序式输出;
Status PostOrderTraverse(BiTree T);
//摧毁二叉树;
Status destoryBiTree(BiTree T);


/*===========二叉树相关算法实现===========*/
//递归计算二叉树高度;
int getHigh(BiTree T);
int Max(int x, int y);
//递归计算二叉树宽度;
int getWide(BiTree T,int level);
// 递归计算叶子结点;
void CountLeaf(BiTree T, int *count,int *ncounts);
//判断是否为完全二叉树.运用队列对二叉树进行广度优先遍历。
bool isComplete(BiTree);


/*=========输出函数整合=========*/

//输出后序式;
void printBiTree(BiTree T);
//输出叶子及非叶子结点数目;
void printLeafNumber(BiTree T, int count, int ncounts);
//判断并输出是否为完全二叉树;
void printIsComplete(BiTree T);





