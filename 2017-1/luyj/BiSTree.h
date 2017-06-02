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

/*=========˳��������Ĵ洢�ṹ=========*/
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

/*=========˳���������غ���ʵ��=========*/

//���Ҷ������Ƿ����ĳֵ���;
bool SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p);

//ɾ��˳���������ָ�����;
bool Delete(BiTree *p);
bool DeleteBST(BiTree *T, KeyType key);

//��˳�����������ָ�����;
bool InsertBST(BiTree *T, ElemType e, BiTree p);

//����˳�������,����������ɾ��������������ɾ��;
bool searchInDelete(BiTree *T, ElemType e);

//���������������ļ�
Status print(ElemType data, FILE*pfile);
Status PreOrderTraverse(BiTree T, FILE*pfile);
