#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef char TElemType;
typedef struct BiTNode
{
	TElemType      data;
	struct BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
Status CreateBiTree(BiTree *T, TElemType *p);
void PostOrderTraverse(BiTree T);
int Depth(BiTree T); 
int Count(BiTree top);
int Width(BiTree T);
int NoLeafCount(BiTree  T);