#include <stdio.h>
#include <stdlib.h>

typedef int KeyType; // 关键字类型
typedef int ElemType;

typedef enum { // 函数返回值
	OK,
	ERROR
}Status;

typedef enum { // 定义布尔函数值
	false,
	true
}bool;

typedef struct BSTNode { // 结点结构
	KeyType key;
	struct BSTNode  *lchild, *rchild; // 左右孩子指针
} BSTNode, *BSTree;

Status CreateBST(BSTree *T, ElemType d[], int n);// 构造一棵二叉排序树
Status SearchBST(BSTree T, KeyType kval, BSTree f, BSTree *p);// 在树中寻找关键字为kval的元素
Status InsertBST(BSTree *T, ElemType e);// 向树中插入元素
bool EQ(KeyType a, KeyType b);// 相等判断
bool LT(KeyType a, KeyType b);// 小于判断
Status DeleteBST(BSTree *T, KeyType kval);// 删除树中关键字为kval的元素
Status Delete(BSTree *p);// 删除的具体操作
Status PreOrderTraverse(BSTree T, Status(*Visit)(ElemType));// 先序遍历
Status Visit(ElemType e);// 输出树中的元素
Status PrintTree(BSTree T);// 输出整棵树