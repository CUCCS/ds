#include<stdio.h>
#include<stdlib.h>

#define NEWBIT (BiTNode*)malloc(sizeof(BiTNode))
#define OVERFLOW -1
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0

typedef char TElemType;
typedef int Status;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild;//左孩子指针
	struct BiTNode *rchild;//右孩子指针
}BiTNode, *BiTree;

Status CreateBiTree(BiTree *pT,int size) {
	//递归先序建立二叉树
	char data;
	char ch[] = "ABC##DE#G##F###";
	data = ch[size];
	size++;
	if (data == '#') {
		*pT = NULL;
	}//AB#D##CE###
	else {
		*pT = NEWBIT;
		(*pT)->data = data;//生成根节点
		CreateBiTree(&(*pT)->lchild,size);//构造左子树
		CreateBiTree(&(*pT)->rchild,size);//构造右子树
	}
	return OK;
}
void preOrderTraverse(BiTree T) {
	//先序遍历
	if (!T) printf("#");
	if (T) {
		printf("%c", T->data);//输出根节点
		preOrderTraverse(T->lchild);//遍历左子树
		preOrderTraverse(T->rchild);//遍历右子树
	}
}
void inOrderTraverse(BiTree T) {
	if (!T) printf("#");
	if (T) {
		preOrderTraverse(T->lchild);
		printf("%c",T->data);
		preOrderTraverse(T->rchild);
	}
}
void destroyBiTree(BiTree *pT) {
	if (*pT) {
		destroyBiTree(&(*pT)->lchild);
		destroyBiTree(&(*pT)->rchild);
		delete *pT;
		*pT = NULL;
	}
}
int main() {
	BiTree T;
	int size = 0;
	T = NULL;
	CreateBiTree(&T,size);
	printf("先序遍历:");
	preOrderTraverse(T);
	printf("\n");
	printf("中序遍历:");
	inOrderTraverse(T);
	printf("\n");
	return 0;
}
//ABC##DE#G##F### 