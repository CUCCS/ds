#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#define TElemType int 
#define KeyType int 

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild, *parent;

}BiTNode, *BiTree;
typedef enum {
	FALSE,
	TRUE
}bool;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

/* ���ұ�ĳ�ʼ������ */
Status _CreateBST(BiTree *T, TElemType * c);

/* ��T���в��ҹؼ���key */
Status SearchBST(BiTree T, TElemType key, BiTree f, BiTree * p);

/* c����ؼ���key */
Status InsertBST(BiTree *T, TElemType key);

/* ��ӡһ����ұ� */
Status _print(BiTree T);

/* ������������� */
Status PreOrderTraverse(BiTree T, int i);

/* ɾ��һ����� */
Status Delete(BiTree  p, BiTree f);

/* �ڲ��ұ��в��� */
Status _Search(BiTree T, TElemType * a);

#endif // !1
