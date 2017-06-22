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
	int bf;//���ƽ������
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

typedef enum
{
	RH = -1,//�Ҹ�
	EH = 0,//�ȸ�
	LH = +1//���	
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


/*=========ƽ�����������,����,ɾ������=========*/

//����
Bool InsertAVL(BSTree *t, ElemType e, Boolean *taller);
//���ҹؼ��ֽ���Ƿ����
Bool SearchBST(BSTree t, ElemType e);
//ɾ����ؼ�����ͬ�Ľ��
Status DeleteAVL(BSTree *t, ElemType e, Boolean *lower);
Bool Delete(BSTree *p);

//��ص���ƽ�����
Status LeftBalance(BSTree*t);
Status RightBalance(BSTree *t);
void R_Rotate(BSTree *p);
void L_Rotate(BSTree*p);






