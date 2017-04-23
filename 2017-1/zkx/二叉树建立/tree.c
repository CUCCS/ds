#include "tree.h"

int i = 0;       //用于计数的全局变量
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;

	ch = p[i];
	i++;                     //用数组形式处理字符串，不用人为输入
	if (ch == '#')        //空孩子
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;              // 生成根结点
		CreateBiTree(&(*T)->lchild, p);   // 构造左子树
		CreateBiTree(&(*T)->rchild, p);   // 构造右子树
	}
	return OK;
}

void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	
}

int main()
{
	BiTree T = NULL;
	Status ret;
	TElemType str1[50] = "ABDG###EH##I#K##C#F##";
	TElemType str2[50] = "ABD#F###CE###";

	printf("----------------二叉树的建立和后序输出----------------\n");

	ret = CreateBiTree(&T,str1);
	printf("处理第一个二叉树 : ABDG###EH##I#K##C#F##\n");
	printf("后序遍历结果为   :  ");
	PostOrderTraverse(T);

	i = 0;       //重新将计数变量置为0，进行第二个字符串的处理
	ret = CreateBiTree(&T, str2);
	printf("\n处理第二个二叉树 : ABD#F###CE###\n");
	printf("后序遍历结果为   :  ");
	PostOrderTraverse(T);
	printf("\n");

	return 0;

}