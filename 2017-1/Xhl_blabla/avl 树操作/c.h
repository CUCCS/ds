#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define num_length 20
# define LH 1//���
#define EH 0
#define  RH -1
#define  s_length 5
#define  num  25
int out[num];//���ڴ洢��������������
int k = 0;//���ڸ��������
typedef int ElemType;
typedef int status;
typedef struct BSTNode
{
	ElemType  data;
	int bf;//�ڵ�ƽ������
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