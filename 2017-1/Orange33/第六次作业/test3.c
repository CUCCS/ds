#include <stdio.h>
#include <malloc.h>

#define TElemType char
#define ElemType BiTNode *   // 树的结点

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

BiTNode *CreatBiTree(char z[])
{
	static int i = -1;
	BiTNode *root;
	i++;
	if (z[i] == '*')
	{
		return NULL;
	}
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = z[i];
	root->lchild = CreatBiTree(z); //构造左子树
	root->rchild = CreatBiTree(z); //构造右子树
	return(root);
}

int Depth(BiTNode* BT)//计算深度
{
	int dep1, dep2;
	if (!BT)
	{
		return 0;
	}
	else
	{
		dep1 = Depth(BT->lchild);
		dep2 = Depth(BT->rchild);
		if (dep1 > dep2)
		{
			return dep1 + 1;
		}
		else
		{
			return dep2 + 1;
		}
	}
}

int  Width(BiTNode* BT)   //计算最大宽度
{
	int count[50]; 
	int max = 0;    
	int i = 0;
	if (!BT)
	{
		return 0;
	}
		i++;
		count[i]++;
		if (max < count[i])
		{
			max = count[i];
		}
		Width(BT->lchild);
		Width(BT->rchild);
		i--;    //返回根结点
		return max;
}

void main()
{
	char z[] = "ABDG***EH**I*K**C*F**";  //测试用例
	BiTNode *T;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T = CreatBiTree(z);

	printf("测试用例：ABDG***EH**I*K**C*F** 的深度为：%d\n", Depth(T));
	printf("\n");
    printf("测试用例：ABDG***EH**I*K**C*F** 的最大宽度为：%d\n", Width(T));
	printf("\n");
}


