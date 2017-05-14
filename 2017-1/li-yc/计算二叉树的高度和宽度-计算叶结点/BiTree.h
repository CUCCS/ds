#include <stdio.h>
#include <stdlib.h>

typedef enum{
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct {
	BiTree base;
	BiTree top;
	int stacksize;
}SqStack;

Status CreateBiTree( BiTree *T, char *c);//创建二叉树
Status InOrderTraverse( BiTree T, Status (*Print)(char e));//后序遍历二叉树
Status MeasureLength(BiTree T);//计算二叉树深度
Status MeasureWidth(BiTree T,int length);//计算二叉树每层宽度
Status GetWidth();//得出二叉树最大宽度
Status MeasureLeaf(BiTree T,int *count1,int *count2);//计算叶子节点和非叶子节点