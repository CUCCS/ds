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

Status CreateBiTree( BiTree *T, char *c);//����������
Status InOrderTraverse( BiTree T, Status (*Print)(char e));//�������������
Status MeasureLength(BiTree T);//������������
Status MeasureWidth(BiTree T,int length);//���������ÿ����
Status GetWidth();//�ó������������
Status MeasureLeaf(BiTree T,int *count1,int *count2);//����Ҷ�ӽڵ�ͷ�Ҷ�ӽڵ�