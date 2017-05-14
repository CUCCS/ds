#include<stdio.h>
#include<stdlib.h>
#define TelemType char
int count = 0;
int count1 = 0;
typedef struct BitNode
{
	TelemType data;
	struct BitNode *lchild, *rchild;
}BitNode;
typedef enum
{
	error, ok
}Status;
BitNode* CreateBiTree(BitNode* T, TelemType *c)
{

	if (c[count++] == ' ')
		T = NULL;
	else
	{
		T = (BitNode*)malloc(sizeof(BitNode));
		T->data = c[count - 1];
		T->lchild = CreateBiTree(T->lchild, c);
		T->rchild = CreateBiTree(T->rchild, c);
	}
	return T;
}
void PostOrder(BitNode* T)//计算所有节点个数
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}
void Point(BitNode* T)
{
	if (T != NULL)
	{
		count1++;
		Point(T->lchild);
		Point(T->rchild);
	}
}
int LeafPoint(BitNode* T)//返回叶子节点个数
{
	int m, n;
	if (T == NULL)
	{
		return 0;
	}
	if (T->lchild == NULL&&T->rchild == NULL)
	{
		return 1;
	}
	else
	{
		m = LeafPoint(T->lchild);
		n = LeafPoint(T->rchild);
	}
	return m + n;
}
int main()
{
	BitNode* T = NULL;
	int count2, count3;
	char str[25] = "ABDG   EH  I K  C F  ";
	TelemType *c = str;
	printf("Create a BitTree:");
	T = CreateBiTree(T, c);
	printf("%s\n", str);
	printf("Postorder Traverse:");
	PostOrder(T);
	Point(T);
	printf("\nTotal Points:%d", count1);
	count2=LeafPoint(T);
	printf("\nLeaf Points:%d", count2);
	count3 = count1 - count2;
	printf("\nNot LeafPoints:%d", count3);
}