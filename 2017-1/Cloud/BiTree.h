//二叉树采用二叉链表存储
//计算整个二叉树高度的算法（二叉树的高度也叫二叉树的深度）。
//计算二叉树最大宽度的算法（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）。
//--------------------------------------------------------------------------------------
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
