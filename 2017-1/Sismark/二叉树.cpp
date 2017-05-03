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
	struct BiTNode *lchild;//����ָ��
	struct BiTNode *rchild;//�Һ���ָ��
}BiTNode, *BiTree;

Status CreateBiTree(BiTree *pT,int size) {
	//�ݹ�������������
	char data;
	char ch[] = "ABC##DE#G##F###";
	data = ch[size];
	size++;
	if (data == '#') {
		*pT = NULL;
	}//AB#D##CE###
	else {
		*pT = NEWBIT;
		(*pT)->data = data;//���ɸ��ڵ�
		CreateBiTree(&(*pT)->lchild,size);//����������
		CreateBiTree(&(*pT)->rchild,size);//����������
	}
	return OK;
}
void preOrderTraverse(BiTree T) {
	//�������
	if (!T) printf("#");
	if (T) {
		printf("%c", T->data);//������ڵ�
		preOrderTraverse(T->lchild);//����������
		preOrderTraverse(T->rchild);//����������
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
	printf("�������:");
	preOrderTraverse(T);
	printf("\n");
	printf("�������:");
	inOrderTraverse(T);
	printf("\n");
	return 0;
}
//ABC##DE#G##F### 