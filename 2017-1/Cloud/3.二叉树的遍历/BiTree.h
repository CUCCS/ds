#include<stdio.h>
#include<stdlib.h>
#define  MAX_TREE_SIZE  100      // 二叉树的最大结点数
#define TElemType char 
extern int count ;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct BiTNode { // 结点结构
	TElemType      data;
	struct BiTNode  *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree *T ,TElemType* d);
int Postorder(BiTree T);
int Depth(BiTree T);
int Width(BiTree T);
int CountLeafNode(BiTree T);
int CountAllNode (BiTree T);
int CountNonLeafNode(BiTree T);
