#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define num_length 20
# define LH 1//左高
#define EH 0
#define  RH -1
#define  s_length 5
#define  num  25
int out[num];//用于存储结点数据域的数组
int k = 0;//用于给数组计数
typedef int ElemType;
typedef int status;
typedef struct BSTNode
{
	ElemType  data;
	int bf;//节点平衡因子
	struct BSTNode *lchild;
	struct BSTNode *rchild;
}BSTNode, *BSTree;
void R_Rotate(BSTree *p);
void LeftBalance(BSTree *T);
status InsertAVL(BSTree *T, ElemType e, int * taller);
void   RightBalance(BSTree *T);
int  IsBalanced(BSTree  pRoot, int* pDepth);
int  Balanced(BSTree pRoot);
int DeleteAVL(BSTree *T, int key, int *shorter);
status InOrder(BSTree T);
status  print(BSTree  T, FILE *fp);