#include <stdio.h>  
#include <stdlib.h>  
#define LH +1     //���  
#define EH  0     //�ȸ�  
#define RH -1     //�Ҹ�  
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
//�������Ķ���������ṹ����
typedef struct BSTNode {
	ElemType data;                            //�������  
	int bf;                                   //���ƽ������  
	struct BSTNode *lchild, *rchild;           //���Һ���ָ��  
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