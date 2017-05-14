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

int main()
{
	BiTree T = NULL;
	Status pop;

	TElemType str1[40] = "ABDG###EH##I#K##C#F##"; 
    TElemType str2[40] = "ABD#F###CE###"; 

    printf("处理第一个二叉树 :  ABDG###EH##I#K##C#F## \n"); 
	pop = CreateBiTree(&T,str1);
	printf("后序遍历结果为   :  "); 
	PostOrderTraverseTree(T);

	printf("\n");

	count = 0;     //处理第二个二叉树
	
    printf("处理第二个二叉树 :  ABD#F###CE### \n"); 
	pop = CreateBiTree(&T,str1);
	printf("后序遍历结果为   :  "); 
	PostOrderTraverseTree(T);
	printf("\n");

	return 0;
}