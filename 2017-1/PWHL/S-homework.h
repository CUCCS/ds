#include <stdio.h>
#include <stdlib.h>
typedef int status;
typedef char ElemType;
int count=0;//用于计算结点个数
typedef struct BiTree
{
	struct BiTree *lchild;
	struct BiTree *rchild;
	ElemType data;
}BiTNode, *BiTree;
status CreateBiTree(BiTree *T, char *c);
void postorderTraversal(BiTree T);
