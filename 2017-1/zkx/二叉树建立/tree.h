#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef struct BiTNode     // ���ṹ
{ 
	TElemType      data;
	struct BiTNode  *lchild, *rchild;    // ���Һ���ָ��
} BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;


Status CreateBiTree(BiTree *T, TElemType *p);

void PostOrderTraverse(BiTree T);
