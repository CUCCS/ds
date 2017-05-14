#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;
typedef int ElemType;

typedef struct  BiTNode
{
	TElemType data;
	struct BiTDode *lchild,*rchild;
}BiTNode,*BiTree;

typedef enum
{
	OK,
	OVERFLOW,
	ERROR
}Status;

Status CreateBiTree(BiTree *T, TElemType *p);

ElemType Depth(BiTree T);

ElemType Width(BiTree T);

ElemType CountLeaf(BiTree T);

ElemType Count(BiTree T);

ElemType NotCountLeaf(BiTree T);


