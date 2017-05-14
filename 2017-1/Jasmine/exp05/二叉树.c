#include<stdio.h>
#include<stdlib.h>
#define TelemType char
TelemType count = 0;
typedef struct BitNode
{
	TelemType data;
	struct BitNode *lchild, *rchild;
}BitNode;
typedef enum
{
	error,ok
}Status;
BitNode* CreateBiTree(BitNode* T,TelemType *c)
{

	if (c[count++] == ' ')
		T = NULL;
	else
	{
			T = (BitNode*)malloc(sizeof(BitNode));
			T->data = c[count-1];
			T->lchild=CreateBiTree(T->lchild,c);
			T->rchild=CreateBiTree(T->rchild,c);
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
	char str[25] = "ABDG   EH  I K  C F  ";
	TelemType *c = str;
	printf("Create a BitTree:");
	T=CreateBiTree(T,c);
	printf("%s\n", str);
	printf("Postorder Traverse:");
	PostOrder(T);
}