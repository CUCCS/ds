#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define num_length 20
#define  s_length  10 
#define  num  25
typedef int ElemType;
typedef int Status;
typedef enum { FALSE, TRUE }  bool;//�Զ��岼��  ����״̬
typedef  struct BiTNode
{
	ElemType  data;//������
	struct BiTNode  *lchild, *rchild;
}  BiTNode, *BiTree;
//���ҽ��
Status SearchBST(BiTree T, ElemType kval, BiTree f, BiTree  *p);
Status InsertBST(BiTree *T, ElemType e);
Status DeleteBST(BiTree *T, ElemType kval);
int  Delete(BiTree *p);
int out[num];//���ڴ洢��������������
int k=0;//���ڸ��������
Status InOrder(BiTree T);
Status  print(BiTree T, FILE *fp);