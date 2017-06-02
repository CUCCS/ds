#include <stdio.h>
#include <stdlib.h>

#define LH +1 // ���
#define EH 0 // �ȸ�
#define RH -1 // �Ҹ�

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

typedef struct AVLTNode { // ���ṹ
	int bf; //ƽ������
	KeyType key;
	struct AVLTNode  *lchild, *rchild; // ���Һ���ָ��
} AVLTNode, *AVLTree;

Status CreateAVLT(AVLTree *T, ElemType d[], int n);// ����һ�ö���ƽ����
Status SearchAVLT(AVLTree *T, KeyType kval, AVLTree f, AVLTree *p);// ������Ѱ�ҹؼ���Ϊkval��Ԫ��
bool EQ(KeyType a, KeyType b);// ����ж�
bool LT(KeyType a, KeyType b);// С���ж�
Status InsertAVLT(AVLTree *T, ElemType e, bool *taller);// �����в���Ԫ��
Status L_Rotate(AVLTree *T); // ����
Status R_Rotate(AVLTree *T); // ����
Status LeftBalance(AVLTree *T); // ��ƽ����ת����
Status RightBalance(AVLTree *T); // ��ƽ����ת����
Status PreOrderTraverse(AVLTree T, FILE *p, Status(*Visit)(ElemType)); // �������
Status Visit(ElemType e, FILE *p); // ������е�Ԫ��
Status PrintTree(AVLTree T, FILE *p); // ���������

AVLTree DeleteNode(AVLTree *T, KeyType key); // ɾ�����йؼ���Ϊkval��Ԫ��
Status DelLeftCase(AVLTree *T, int bfChild); // ɾ�����������
Status DelRightCase(AVLTree *T, int bfChild); // ɾ�����������