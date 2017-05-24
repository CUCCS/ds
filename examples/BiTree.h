#ifndef _BTREE_H_
#define _BTREE_H_

#include "myds.h"

typedef struct BiTNode { // 结点结构
    TElemType      data;
    struct BiTNode  *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree *T);
void PostOrderTraverseTree(BiTree T);

#endif

