#include <stdio.h>
#include <stdlib.h>
int count = 0;
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
	if(T==NULL)
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
int width(BiTree T)
{
	int static level[10];//假设最多有10层
	int static max = 0;//最大宽度
	int static j = 0;
	int static counter[20];
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

int main()
{
	BiTree T;
	ElemType str[30] = "ABDG###EH##I#K##C#F##";
	printf("输出:    ");
	CreatBiTree( &T,  str);
	printf("用例：ABDG###EH##I#K##C#F##:\n");
	PostOrderTraverse(T);
	printf("深度为：%d\n最大宽度为：%d\n",depth(T),width(T));
	printf("\n");
	
}