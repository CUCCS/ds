#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define num_length 20
#define  s_length  10
#define  num  25
typedef int ElemType;
typedef int Status;
typedef enum { FALSE, TRUE }  bool;
typedef  struct BiTNode
{
	ElemType  data;//������
	struct BiTNode  *lchild, *rchild;
}  BiTNode, *BiTree;
//���ҽ�� 
Status SearchBST(BiTree T, ElemType d, BiTree f, BiTree  *p);
Status InsertBST(BiTree *T, ElemType e);
Status DeleteBST(BiTree *T, ElemType d);
Status PreOrderTraverse(BiTree T);
Status  print(BiTree T, FILE *fp);
int  Delete(BiTree *p);
int out[num];//���ڴ洢�������������� 
//���ڸ�������� 


