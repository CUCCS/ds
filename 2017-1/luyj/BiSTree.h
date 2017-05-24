#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define KeyType int



typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	true,
	false
}bool;

/*=========顺序二叉树的存储结构=========*/
typedef struct ElemType
{
	int key;
}ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;



bool EQ(int k, int tk);
bool LT(int k, int tk);

/*=========顺序二叉树相关函数实现=========*/

//查找二叉树是否存在某值结点;
bool SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p);

//删除顺序二叉树中指定结点;
bool Delete(BiTree *p);
bool DeleteBST(BiTree *T, KeyType key);

//在顺序二叉树插入指定结点;
bool InsertBST(BiTree *T, ElemType e, BiTree p);

//查找顺序二叉树,若结点存在则删除，若不存在则删除;
bool searchInDelete(BiTree *T, ElemType e);

//按先序遍历输出到文件
Status print(ElemType data, FILE*pfile);
Status PreOrderTraverse(BiTree T, FILE*pfile);
