#include <stdio.h>  
#include <stdlib.h>  
#define LH +1     //左高  
#define EH  0     //等高  
#define RH -1     //右高  
typedef int ElemType;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum {
	false,
	true
}bool;
//二叉树的二叉链表结点结构定义
typedef struct BSTNode {
	ElemType data;                            //结点数据  
	int bf;                                   //结点平衡因子  
	struct BSTNode *lchild, *rchild;           //左右孩子指针  
} BSTNode, *BSTree;

void R_Rotate(BSTree* p);
void L_Rotate(BSTree* p);
void LeftBalance(BSTree* T);
void RightBalance(BSTree* T);
int  InsertAVL(BSTree* T, ElemType e, bool* taller);
bool FindNode(BSTree root, ElemType e, BSTree* pos);
int TraversePrint(BSTree T, FILE*pfile);
int PreOrderTraverse(BSTree T);
bool print(int data, FILE*pfile);
bool DeleteBST(BSTree *T, int key);