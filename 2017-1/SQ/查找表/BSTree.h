#include <stdio.h>
#include <stdlib.h>

typedef int KeyType; // �ؼ�������
typedef int ElemType;

typedef enum { // ��������ֵ
	OK,
	ERROR
}Status;

typedef enum { // ���岼������ֵ
	false,
	true
}bool;

typedef struct BSTNode { // ���ṹ
	KeyType key;
	struct BSTNode  *lchild, *rchild; // ���Һ���ָ��
} BSTNode, *BSTree;

Status CreateBST(BSTree *T, ElemType d[], int n);// ����һ�ö���������
Status SearchBST(BSTree T, KeyType kval, BSTree f, BSTree *p);// ������Ѱ�ҹؼ���Ϊkval��Ԫ��
Status InsertBST(BSTree *T, ElemType e);// �����в���Ԫ��
bool EQ(KeyType a, KeyType b);// ����ж�
bool LT(KeyType a, KeyType b);// С���ж�
Status DeleteBST(BSTree *T, KeyType kval);// ɾ�����йؼ���Ϊkval��Ԫ��
Status Delete(BSTree *p);// ɾ���ľ������
Status PreOrderTraverse(BSTree T, Status(*Visit)(ElemType));// �������
Status Visit(ElemType e);// ������е�Ԫ��
Status PrintTree(BSTree T);// ���������