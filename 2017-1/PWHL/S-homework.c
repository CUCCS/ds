#include "S-homework.h"
status CreateBiTree(BiTree *T, char *c)
{
	
	ElemType ch;
	ch = c[count];
	count++;
	if (ch == '*')
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			exit(-1);
		}
		(*T)->data = ch;//���ɸ����
		CreateBiTree(&(*T)->lchild, c);//����������
		CreateBiTree(&(*T)->rchild, c);//����������
	}
	return 1;
}
void postorderTraversal(BiTree T)
{
	if (T==NULL)
	{
		printf("*");
		return;
	}

	postorderTraversal(T->lchild);
	postorderTraversal(T->rchild);
	printf("%c ", T->data);
}
int main()
{
	BiTree t;
	ElemType c[20];
	scanf("%s", c);
	CreateBiTree(&t, c);
	printf("����������˳��Ϊ\n");
	postorderTraversal(t);
	return 0;
}