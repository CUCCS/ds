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

Status size = 0;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild;//左孩子指针
	struct BiTNode *rchild;//右孩子指针
}BiTNode, *BiTree;

Status CreateBiTree(BiTree *pT) {
	//递归先序建立二叉树
	char data;
	char ch[] = "ABDG###EH##I#K##C#F##";
	data = ch[size];
	size++;
	if (data == '#') {
		*pT = NULL;
	}
	else {
		*pT = NEWBIT;
		(*pT)->data = data;//生成根节点
		CreateBiTree(&(*pT)->lchild);//构造左子树
		CreateBiTree(&(*pT)->rchild);//构造右子树
	}
	return OK;
}
void preOrderTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);//输出根节点
		preOrderTraverse(T->lchild);//遍历左子树
		preOrderTraverse(T->rchild);//遍历右子树
	}
}
void inOrderTraverse(BiTree T) {
	if (T) {
		inOrderTraverse(T->lchild);
		printf("%c",T->data);
		inOrderTraverse(T->rchild);
	}
}
void postOrderTraverse(BiTree T) {
	if (T) {
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}
int main() {
	BiTree T;
	T = NULL;
	CreateBiTree(&T);
	printf("先序遍历:");
	preOrderTraverse(T);
	printf("\n");
	printf("中序遍历:");
	inOrderTraverse(T);
	printf("\n");
	printf("后序遍历:");
	postOrderTraverse(T);
	printf("\n");
	return 0;
}