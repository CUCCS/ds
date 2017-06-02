#include <stdio.h>
#include <stdlib.h>

#define LH +1 // 左高
#define EH 0 // 等高
#define RH -1 // 右高

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

typedef struct AVLTNode { // 结点结构
	int bf; //平衡因子
	KeyType key;
	struct AVLTNode  *lchild, *rchild; // 左右孩子指针
} AVLTNode, *AVLTree;

Status CreateAVLT(AVLTree *T, ElemType d[], int n);// 构造一棵二叉平衡树
Status SearchAVLT(AVLTree *T, KeyType kval, AVLTree f, AVLTree *p);// 在树中寻找关键字为kval的元素
bool EQ(KeyType a, KeyType b);// 相等判断
bool LT(KeyType a, KeyType b);// 小于判断
Status InsertAVLT(AVLTree *T, ElemType e, bool *taller);// 向树中插入元素
Status L_Rotate(AVLTree *T); // 左旋
Status R_Rotate(AVLTree *T); // 右旋
Status LeftBalance(AVLTree *T); // 左平衡旋转处理
Status RightBalance(AVLTree *T); // 右平衡旋转处理
Status PreOrderTraverse(AVLTree T, FILE *p, Status(*Visit)(ElemType)); // 先序遍历
Status Visit(ElemType e, FILE *p); // 输出树中的元素
Status PrintTree(AVLTree T, FILE *p); // 输出整棵树

AVLTree DeleteNode(AVLTree *T, KeyType key); // 删除树中关键字为kval的元素
Status DelLeftCase(AVLTree *T, int bfChild); // 删除左子树结点
Status DelRightCase(AVLTree *T, int bfChild); // 删除右子树结点