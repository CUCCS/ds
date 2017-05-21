#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define num_length 20
#define  s_length  10 
#define  num  25
typedef int ElemType;
typedef int Status;
typedef enum { FALSE, TRUE }  bool;//自定义布尔  返回状态
typedef  struct BiTNode
{
	ElemType  data;//数据域
	struct BiTNode  *lchild, *rchild;
}  BiTNode, *BiTree;
//查找结点
Status SearchBST(BiTree T, ElemType kval, BiTree f, BiTree  *p);
Status InsertBST(BiTree *T, ElemType e);
Status DeleteBST(BiTree *T, ElemType kval);
int  Delete(BiTree *p);
int out[num];//用于存储结点数据域的数组
int k=0;//用于给数组计数
Status InOrder(BiTree T);
Status  print(BiTree T, FILE *fp);