#include <stdio.h>
#include <stdlib.h>

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
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct {
	BiTree base;
	BiTree top;
	int stacksize;
}SqStack;

Status CreateBiTree( BiTree T, char *c);
Status InOrderTraverse( BiTree T, Status (*Print)(char e));