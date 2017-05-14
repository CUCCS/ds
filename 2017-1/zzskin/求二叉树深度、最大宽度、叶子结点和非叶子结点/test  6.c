#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef char TElemType ;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;   //左右孩子的指针
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;         //枚举定义（返回状态）


Status CreateBiTree(BiTree *T,TElemType *p);
void PostOrderTraverseTree(BiTree T);
int BiTreeDepth(BiTree T);
int BiTreeWidth(BiTree T);
int BiTreeCount(BiTree T);
int BiTreeCountLeaf(BiTree T);


int count = 0;  //定义全局变量  用于对二叉树进行计数

Status CreateBiTree(BiTree *T,TElemType *p) // 创建二叉树
{
	TElemType ch;
	ch = p[count];
	count++;                          //定义数组存储字符串

	if(ch == ' ')
	{
		return OK;

	}
	else if(ch == '#')
	{
		*T = NULL;
	}
	else
	{
		if(!(*T = (BiTNode *)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;     //根节点
		CreateBiTree(&(*T)->lchild,p);  //构造左孩子
		CreateBiTree(&(*T)->rchild,p);   //构造右孩子
	}
	return OK;
}

void PostOrderTraverseTree(BiTree T)
{
	if(T != NULL) 
	{ 
		PostOrderTraverseTree(T->lchild); 
		PostOrderTraverseTree(T->rchild); 
		printf("%c",T->data); 
	}
}

int BiTreeDepth(BiTree T)
{
	int depthleft,depthright;
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		depthleft = BiTreeDepth(T->lchild);
		depthright = BiTreeDepth(T->rchild);
		if(depthleft > depthright)
		{
			return (depthleft + 1);
		}
		else
		{
			return (depthright + 1);
		}
	}
}

int pot[100];   //存放各层结点数
int max = 0;    //最大宽度

int BiTreeWidth(BiTree T)  //递归求最大宽度
{

	if(T == NULL)
	{
		return 0;
	}
		count++;
		pot[count]++;
		if(max < pot[count])
		{
			max = pot[count];
		}
		BiTreeWidth(T->lchild);
		BiTreeWidth(T->rchild);
		count--;
		return max;
}

int BiTreeCount(BiTree T)//返回指针T所指二叉树中所有结点个数 
{
	if(T == NULL)
	{
		return 0;
	}
	else if((T->lchild == NULL) && (T->rchild == NULL))
	{
		return 1;
	}
	else
	{
		return BiTreeCount(T->lchild) + BiTreeCount(T->rchild) + 1;
	}
}

int BiTreeCountLeaf(BiTree T)// 返回指针T所指二叉树中所有叶子结点个数 
{
	if(T == NULL)
	{
		return 0;
	}
	else if((T->lchild == NULL) && (T->rchild == NULL))
	{
		return 1;
	}
	else
	{
		return BiTreeCountLeaf(T->lchild) + BiTreeCountLeaf(T->rchild);
	}
}


int main()
{
	BiTree T = NULL;

	TElemType str1[40] = "ABDG###EH##I#K##C#F##"; 
    TElemType str2[40] = "ABD#F###CE###"; 

    printf("处理第一个二叉树 :  ABDG###EH##I#K##C#F## \n"); 
	CreateBiTree(&T,str1); 
	printf("此二叉树高度为%d\n最大宽度为%d\n",BiTreeDepth(T),BiTreeWidth(T)); 
    printf("此二叉树结点为%d\n叶子结点为%d",BiTreeCount(T),BiTreeCountLeaf(T)); 
	printf("\n");

	count = 0;     //处理第二个二叉树
	
    printf("处理第二个二叉树 :  ABD#F###CE### \n"); 
    CreateBiTree(&T,str2);
	printf("此二叉树高度为%d\n最大宽度为%d\n",BiTreeDepth(T),BiTreeWidth(T)); 
    printf("此二叉树结点为%d\n叶子结点为%d",BiTreeCount(T),BiTreeCountLeaf(T)); 
	printf("\n");

	return 0;
}