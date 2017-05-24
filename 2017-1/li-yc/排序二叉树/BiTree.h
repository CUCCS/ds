#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef enum{
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

bool EQ(KeyType kval, KeyType data);
bool LT(KeyType kval, KeyType data);
Status preOrderTraverse(BiTree T);
bool SearchBST(BiTree T, KeyType kval, BiTree f, BiTree *p);
bool InsertBST(BiTree *T, KeyType e, BiTree p);
Status Delete(BiTree *p);
bool DeleteBST(BiTree *T, KeyType kval);