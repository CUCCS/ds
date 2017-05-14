#include <stdio.h>
#include <stdlib.h>
int count = 0;
int jiedian = 0;//总节点数
typedef char ElemType;
typedef struct BiNode
{
	ElemType      data;
	struct BiNode  *lchild, *rchild;
} BiNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status CreatBiTree(BiTree *T, ElemType *ar)
{
	ElemType ch;
	ch = ar[count];
	count++;
	if (ch == '#')
	{
		*T = NULL;//节点没有子树
	}
	else
	{
		jiedian++;
		if (!(*T = (BiTree)malloc(sizeof(BiNode))))
		{
			return OVERFLOW;//内存分配失败
		}
		(*T)->data = ch;//生成根节点              
		CreatBiTree(&(*T)->lchild, ar);//创建左子树   
		CreatBiTree(&(*T)->rchild, ar); //创建右子树  
	}
	return OK;
}
void PostOrderTraverse(BiTree T)//后序遍历及输出
{
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
int depth(BiTree T)//计算深度
{
	int ldepth, rdepth;
	if (T == NULL)
	{
		return 0;
	}
	ldepth = depth(T->lchild);
	rdepth = depth(T->rchild);
	if (ldepth > rdepth)
	{
		return ldepth + 1;
	}
	else
	{
		return rdepth + 1;
	}
}
int j = 0;
int max = 0;//最大宽度
int counter[20];//每层宽度
int width(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	j++;
	counter[j]++;
	if (max < counter[j])
	{
		max = counter[j];
	}
	width(T->lchild);
	width(T->rchild);
	j--;
	return max;
}
int leaf_num(BiTree T)//叶子节点
{
	int l, r;
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
		l = leaf_num(T->lchild);
		r = leaf_num(T->rchild);
		return l + r;
	}
}

int main()
{
	BiTree T, R;
	ElemType str1[30] = "ABDG###EH##I#K##C#F##";
	ElemType str2[30] = "ABD#F###CE###";
	CreatBiTree(&T, str1);

	printf("用例-1：ABDG###EH##I#K##C#F##:\n");
	printf("深度为：%d\n最大宽度为：%d\n", depth(T), width(T));
	printf("输出:    ");
	PostOrderTraverse(T);
	printf("\n");
	printf("叶子节点数：%d\n", leaf_num(T));
	printf("非叶子节点数：%d", jiedian - leaf_num(T));
	printf("\n\n");

	count = 0;
	jiedian = 0;
	max = 0;
	int g;
	for (g = 0; g < 20; g++)
	{
		counter[g] = 0;
	}
	CreatBiTree(&R, str2);
	printf("用例-2：ABD#F###CE###:\n");
	printf("深度为：%d\n最大宽度为：%d\n", depth(R), width(R));
	printf("输出:    ");
	PostOrderTraverse(R);
	printf("\n");
	printf("叶子节点数：%d\n", leaf_num(R));
	printf("非叶子节点数：%d", jiedian - leaf_num(R));
	printf("\n");
}