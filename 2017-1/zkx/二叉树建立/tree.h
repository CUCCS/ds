#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef struct BiTNode     // 结点结构
{ 
	TElemType      data;
	struct BiTNode  *lchild, *rchild;    // 左右孩子指针
} BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;


Status CreateBiTree(BiTree *T, TElemType *p);

void PostOrderTraverse(BiTree T);
