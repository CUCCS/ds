#include <stdio.h>
#include <malloc.h>

#define TElemType char
#define ElemType BiTNode *   // ���Ľ��

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
	root->lchild = CreatBiTree(z); //����������
	root->rchild = CreatBiTree(z); //����������
	return(root);
}

int Depth(BiTNode* BT)//�������
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

int  Width(BiTNode* BT)   //���������
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
		i--;    //���ظ����
		return max;
}

void main()
{
	char z[] = "ABDG***EH**I*K**C*F**";  //��������
	BiTNode *T;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T = CreatBiTree(z);

	printf("����������ABDG***EH**I*K**C*F** �����Ϊ��%d\n", Depth(T));
	printf("\n");
    printf("����������ABDG***EH**I*K**C*F** �������Ϊ��%d\n", Width(T));
	printf("\n");
}


