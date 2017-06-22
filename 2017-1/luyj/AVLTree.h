#include <stdio.h>
#include <malloc.h>


typedef int KeyType;
typedef struct ElemType
{
	int key;
}ElemType;

typedef struct BSTNode
{
	ElemType data;
	int bf;//结点平衡因子
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

typedef enum
{
	RH = -1,//右高
	EH = 0,//等高
	LH = +1//左高	
}bh;

typedef enum
{
	FALSE,
	TRUE
}Boolean,Bool;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;



Bool EQ(int k, int tk);
Bool LT(int k, int tk);
Status PreOrderTraverse(BSTree t,FILE*pfile);


/*=========平衡二叉树建立,查找,删除操作=========*/

//建立
Bool InsertAVL(BSTree *t, ElemType e, Boolean *taller);
//查找关键字结点是否存在
Bool SearchBST(BSTree t, ElemType e);
//删除与关键字相同的结点
Status DeleteAVL(BSTree *t, ElemType e, Boolean *lower);
Bool Delete(BSTree *p);

//相关调节平衡操作
Status LeftBalance(BSTree*t);
Status RightBalance(BSTree *t);
void R_Rotate(BSTree *p);
void L_Rotate(BSTree*p);






