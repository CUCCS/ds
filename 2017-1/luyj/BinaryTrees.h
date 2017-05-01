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



//将字符从字符串中取出;
char AbstractWord(char*s);

//建立二叉树;
Status CreateBiTree(BiTree *T, char *s);

//以后序式输出;
Status PostOrderTraverse(BiTree T);

//摧毁二叉树;
Status destoryBiTree(BiTree T);

//递归计算二叉树高度;
int getHigh(BiTree T);
int Max(int x, int y);

//递归计算二叉树宽度;
int getWide(BiTree T,int level);

//递归计算叶子结点;
void CountLeaf(BiTree T, int *count,int *ncounts);



