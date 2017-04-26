#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status PostOrderTraverse(BiTree T) {
	//��������������ĵݹ��㷨
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}
