#include<stdio.h>
#include<stdlib.h>
#define  TElemType char
typedef struct BiTNode { // ���ṹ
    TElemType data;
   struct BiTNode  *lchild, *rchild; // ���Һ���ָ��
} BiTNode, *BiTree;
enum Status{
    OVERFLOW,
	OK,
	FALSE
};
BiTNode* CreateBiTree(BiTNode *T,char *);
void Preorder(BiTNode *T);