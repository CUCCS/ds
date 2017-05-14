#include<stdio.h>
#include<stdlib.h>
#define  TElemType char
typedef struct BiTNode { // 结点结构
    TElemType data;
   struct BiTNode  *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;
enum Status{
    OVERFLOW,
	OK,
	FALSE
};
BiTNode* CreateBiTree(BiTNode *T,char *);
void Preorder(BiTNode *T);