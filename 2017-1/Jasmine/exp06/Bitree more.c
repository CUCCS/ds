#include<stdio.h>
#include<stdlib.h>
#define TelemType char
int count = 0;
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
	{
		T = NULL;
	}
	else
	{
		T = (BitNode*)malloc(sizeof(BitNode));
		T->data = c[count - 1];
		T->lchild = CreateBiTree(T->lchild, c);
		T->rchild = CreateBiTree(T->rchild, c);
	}
	return T;
}
void PostOrder(BitNode* T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}
int Depth(BitNode* T)
{
	int depthL, depthR, depth;
	if (!T)
	{
		depth = 0;
	}
	else
	{
		depthL = Depth(T->lchild);
		depthR = Depth(T->rchild);
		depth = 1 + (depthL > depthR ? depthL : depthR);
	}
	return depth;
}
int a[10] = { 0 };
int i = 0;
void Width(BitNode *T)
{
	if (T != NULL)
	{
		if (i == 0)
		{
			a[0] = 1;
			i++;
			if (T->lchild != NULL) a[i]++;
			if (T->rchild != NULL) a[i]++;
		}
		else {
			i++;
			if (T->lchild != NULL) a[i]++;
			if (T->rchild != NULL) a[i]++;
		}
		Width(T->lchild);
		i--;
		Width(T->rchild);
	}
}
int MaxWidth()
{
	int max = 0,i;
	for (i = 0;i < 10;i++)            //找出最大宽度
		if (max < a[i])
			max = a[i];
	return max;
}

int main()
{
	BitNode* T = NULL;
	char str[25] = "ABDG   EH  I K  C F  ";
	TelemType *c = str;
	printf("Create a BitTree:");
	T = CreateBiTree(T, c);
	printf("%s\n", str);
	printf("Postorder Traverse:");
	PostOrder(T);
	printf("\nThe depth of the BiTree is:");
	printf("%d", Depth(T));
	printf("\nThe width of the BiTree is:");
	Width(T);
	printf("%d", MaxWidth());
}