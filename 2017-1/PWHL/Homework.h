#include <stdio.h>
#include <stdlib.h>
typedef int status;
typedef char ElemType;
#define nwidth  10
int  w = 1;//计算层数
int width[nwidth] = { 0 };
int number = 0;//用于计算结点个数
int count[100];

typedef struct BiTree
{
	struct BiTree *lchild;
	struct BiTree *rchild;
	ElemType data;
}BiTNode, *BiTree;
status CreateBiTree(BiTree *T, char *c);
void postorderTraversal(BiTree T);
int TreeDepth(BiTree T);
int widthHouxu(BiTree T);

