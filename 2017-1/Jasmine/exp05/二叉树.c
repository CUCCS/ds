#include<stdio.h>
#include<stdlib.h>
#define TelemType char
typedef struct BitNode
{
	TelemType data;
	struct BitNode *lchild, *rchild;
}BitNode;
typedef enum
{
	error,ok
}Status;
BitNode* CreateBiTree(BitNode* T)
{
	TelemType c;
	scanf("%c", &c);
	if (c == ' ')
		T = NULL;
	else
	{
			T = (BitNode*)malloc(sizeof(BitNode));
			T->data = c;
			T->lchild=CreateBiTree(T->lchild);
			T->rchild=CreateBiTree(T->rchild);
	}
	return T;
}
void PostOrder(BitNode* T)
{
	if (T!=NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}
int main()
{
	BitNode* T=NULL;
	printf("Create a BitTree:");
	T=CreateBiTree(T);
	printf("Postorder Traverse:");
	PostOrder(T);
}